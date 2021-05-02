#include "../cub.h"

void	cr_part1(t_all *all, int x)
{
	double	camere_x;

	all->gl->camera_x = 2.0 * x / (double)all->pm->scr_w - 1;
	all->gl->rayDirX = all->pm->dirX
		+ all->pm->plX * all->gl->camera_x;
	all->gl->rayDirY = all->pm->dirY
		+ all->pm->plY * all->gl->camera_x;
	all->gl->mapX = (int)all->pm->posX;
	all->gl->mapY = (int)all->pm->posY;
	all->gl->deltaDistX = fabs(1 / all->gl->rayDirX);
	all->gl->deltaDistY = fabs(1 / all->gl->rayDirY);
	all->gl->hit = 0;
}

void	cr_X(t_all *all)
{
	if	(all->gl->rayDirX < 0)
	{
		all->gl->stepX = -1;
		all->gl->sideDistX
			= (all->pm->posX - all->gl->mapX)
			* all->gl->deltaDistX;
	}
	else
	{
		all->gl->stepX = 1;
		all->gl->sideDistX = (all->gl->mapX
				+ 1.0 - all->pm->posX) * all->gl->deltaDistX;
	}
}

void	cr_Y(t_all *all)
{

	if (all->gl->rayDirY < 0)
	{
		all->gl->stepY = -1;
		all->gl->sideDistY
			= (all->pm->posY - all->gl->mapY)
			* all->gl->deltaDistY;
	}
	else
	{
		all->gl->stepY = 1;
		all->gl->sideDistY = (all->gl->mapY
				+ 1.0 - all->pm->posY) * all->gl->deltaDistY;
	}
	all->gl->hit = 0;
}

void	cr_part3(t_all *all, int x)
{
	if (all->gl->sideDistX < all->gl->sideDistY)
	{
		all->gl->sideDistX += all->gl->deltaDistX;
		all->gl->mapX += all->gl->stepX;
		all->gl->side = 0;
	}
	else
	{
		all->gl->sideDistY += all->gl->deltaDistY;
		all->gl->mapY += all->gl->stepY;
		all->gl->side = 1;
	}
	if (all->map[all->gl->mapY][all->gl->mapX] == '1')
		all->gl->hit = 1;
	if (all->gl->side == 0)
		all->gl->pwd = (all->gl->mapX - all->pm->posX
				+ (1 - all->gl->stepX) / 2) / all->gl->rayDirX;
	else
		all->gl->pwd = (all->gl->mapY - all->pm->posY
				+ (1 - all->gl->stepY) / 2) / all->gl->rayDirY;
	all->sprite->z_buf[x] = all->gl->pwd;
}

void	cr_draw(t_all *all)
{
	all->gl->line_h = (int)(all->pm->scr_h
			/ all->gl->pwd);
	all->gl->draw_start = -1 * (all->gl->line_h)
		/ 2 + all->pm->scr_h / 2;
	if (all->gl->draw_start < 0)
		all->gl->draw_start = 0;
	all->gl->draw_end = all->gl->line_h
		/ 2 + all->pm->scr_h / 2;
	if (all->gl->draw_end >= all->pm->scr_h)
		all->gl->draw_end = all->pm->scr_h - 1;
}

void	cr_part5(t_all *all, t_img *tex)
{
	if (all->gl->side == 0)
		all->txtr_data->wall_x = all->pm->posY
			+ all->gl->pwd * all->gl->rayDirY;
	else
		all->txtr_data->wall_x = all->pm->posX + all->gl->pwd
			* all->gl->rayDirX;
	all->txtr_data->wall_x -= floor((all->txtr_data->wall_x));
	all->txtr_data->tex_x = (int)(all->txtr_data->wall_x
		* (double)(tex->width));
	if (all->gl->side == 0 && all->gl->rayDirX > 0)
		all->txtr_data->tex_x = tex->width - all->txtr_data->tex_x - 1;
	if (all->gl->side == 1 && all->gl->rayDirY < 0)
		all->txtr_data->tex_x = tex->width - all->txtr_data->tex_x - 1;
	all->txtr_data->step = 1.0 * tex->height / all->gl->line_h;
	all->txtr_data->text_pos
		= (all->gl->draw_start - all->pm->scr_h
			/ 2 + all->gl->line_h / 2)
		* all->txtr_data->step;
}

void	cr_part6(t_all *all, int x, t_img *tex)
{
	int y;

	y = 0;
	while (y < all->pm->scr_h)
	{
		if (y < all->gl->draw_start)
			my_mlx_pixel_put(all->win, x, y, all->pm->color_ceil);
		if (y >= all->gl->draw_start && y <= all->gl->draw_end)
		{
			all->txtr_data->tex_y = (int)all->txtr_data->text_pos
				& (tex->height - 1);
			all->txtr_data->text_pos += all->txtr_data->step;
			all->txtr_data->color = *(unsigned int *)
				(tex->addr
				+ (all->txtr_data->tex_y
				* tex->line_len
				+ all->txtr_data->tex_x
				* (tex->bpp / 8)));
			my_mlx_pixel_put(all->win, x, y, all->txtr_data->color);
		}
		if ( y > all->gl->draw_end)
			my_mlx_pixel_put(all->win, x, y, all->pm->color_floor);
		y++;
	}
}

t_img	*chooseTex(t_all *all)
{
	if (all->gl->side == 1)
	{
		if (all->gl->mapY > all->pm->posY)
			return (all->texSO);
		else
			return (all->texNO);
	}
	else
		if (all->gl->mapX > all->pm->posX)
			return (all->texWE);
		else
			return (all->texEA);
}

int	cast_rays(t_all *all)
{
	int		x;
	t_img	*tmp;

	// all->sprite->z_buf = malloc((sizeof(double)) * all->pm->scr_w);
	x = 0;
	while (x < all->pm->scr_w)
	{
		cr_part1(all, x);
		cr_part2(all);
		while (all->gl->hit == 0)
			cr_part3(all, x);
		cr_part4(all);
		tmp = chooseTex(all);
		cr_part5(all, tmp);
		cr_part6(all, x, tmp);
		x++;
	}
	return (0);
}
