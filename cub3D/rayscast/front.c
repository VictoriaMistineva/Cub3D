#include "../cub.h"

void	cr_part1(t_all *all, int x)
{
	double	camere_x;

	all->algo_data->camera_x = 2.0 * x / (double)all->param_map->scr_w - 1;
	all->algo_data->rayDirX = all->param_map->dirX
		+ all->param_map->planeX * all->algo_data->camera_x;
	all->algo_data->rayDirY = all->param_map->dirY
		+ all->param_map->planeY * all->algo_data->camera_x;
	all->algo_data->mapX = (int)all->param_map->posX;
	all->algo_data->mapY = (int)all->param_map->posY;
	all->algo_data->deltaDistX = fabs(1 / all->algo_data->rayDirX);
	all->algo_data->deltaDistY = fabs(1 / all->algo_data->rayDirY);
	all->algo_data->hit = 0;
}

void	cr_part2(t_all *all)
{
	if (all->algo_data->rayDirX < 0)
	{
		all->algo_data->stepX = -1;
		all->algo_data->sideDistX
			= (all->param_map->posX - all->algo_data->mapX)
			* all->algo_data->deltaDistX;
	}
	else
	{
		all->algo_data->stepX = 1;
		all->algo_data->sideDistX = (all->algo_data->mapX
				+ 1.0 - all->param_map->posX) * all->algo_data->deltaDistX;
	}
	if (all->algo_data->rayDirY < 0)
	{
		all->algo_data->stepY = -1;
		all->algo_data->sideDistY
			= (all->param_map->posY - all->algo_data->mapY)
			* all->algo_data->deltaDistY;
	}
	else
	{
		all->algo_data->stepY = 1;
		all->algo_data->sideDistY = (all->algo_data->mapY
				+ 1.0 - all->param_map->posY) * all->algo_data->deltaDistY;
	}
	all->algo_data->hit = 0;
}

void	cr_part3(t_all *all, int x)
{
	if (all->algo_data->sideDistX < all->algo_data->sideDistY)
	{
		all->algo_data->sideDistX += all->algo_data->deltaDistX;
		all->algo_data->mapX += all->algo_data->stepX;
		all->algo_data->side = 0;
	}
	else
	{
		all->algo_data->sideDistY += all->algo_data->deltaDistY;
		all->algo_data->mapY += all->algo_data->stepY;
		all->algo_data->side = 1;
	}
	if (all->map[all->algo_data->mapY][all->algo_data->mapX] == '1')
		all->algo_data->hit = 1;
	if (all->algo_data->side == 0)
		all->algo_data->pwd = (all->algo_data->mapX - all->param_map->posX
			+ (1 - all->algo_data->stepX) / 2) / all->algo_data->rayDirX;
	else
		all->algo_data->pwd = (all->algo_data->mapY - all->param_map->posY
			+ (1 - all->algo_data->stepY) / 2) / all->algo_data->rayDirY;
	all->sprite->z_buffer[x] = all->algo_data->pwd;
}

void	cr_part4(t_all *all)
{
	all->algo_data->line_h = (int)(all->param_map->scr_h
		/ all->algo_data->pwd);
	all->algo_data->draw_start = -1 * (all->algo_data->line_h)
		/ 2 + all->param_map->scr_h / 2;
	if (all->algo_data->draw_start < 0)
		all->algo_data->draw_start = 0;
	all->algo_data->draw_end = all->algo_data->line_h
		/ 2 + all->param_map->scr_h / 2;
	if (all->algo_data->draw_end >= all->param_map->scr_h)
		all->algo_data->draw_end = all->param_map->scr_h - 1;
}

void	cr_part5(t_all *all, t_img *tex)
{
	if (all->algo_data->side == 0)
		all->txtr_data->wall_x = all->param_map->posY
			+ all->algo_data->pwd * all->algo_data->rayDirY;
	else
		all->txtr_data->wall_x = all->param_map->posX + all->algo_data->pwd
			* all->algo_data->rayDirX;
	all->txtr_data->wall_x -= floor((all->txtr_data->wall_x));
	all->txtr_data->tex_x = (int)(all->txtr_data->wall_x
		* (double)(tex->width));
	if (all->algo_data->side == 0 && all->algo_data->rayDirX > 0)
		all->txtr_data->tex_x = tex->width - all->txtr_data->tex_x - 1;
	if (all->algo_data->side == 1 && all->algo_data->rayDirY < 0)
		all->txtr_data->tex_x = tex->width - all->txtr_data->tex_x - 1;
	all->txtr_data->step = 1.0 * tex->height / all->algo_data->line_h;
	all->txtr_data->text_pos
		= (all->algo_data->draw_start - all->param_map->scr_h
		/ 2 + all->algo_data->line_h / 2)
		* all->txtr_data->step;
}

void	cr_part6(t_all *all, int x, t_img *tex)
{
	int y;

	y = 0;
	while (y < all->param_map->scr_h)
	{
		if (y < all->algo_data->draw_start)
			my_mlx_pixel_put(all->win, x, y, all->param_map->color_ceil);
		if (y >= all->algo_data->draw_start && y <= all->algo_data->draw_end)
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
		if ( y > all->algo_data->draw_end)
			my_mlx_pixel_put(all->win, x, y, all->param_map->color_floor);
		y++;
	}
}

t_img	*chooseTex(t_all *all)
{
	if (all->algo_data->side == 1)
	{
		if (all->algo_data->mapY > all->param_map->posY)
			return (all->texSO);
		else
			return (all->texNO);
	}
	else
		if (all->algo_data->mapX > all->param_map->posX)
			return (all->texWE);
		else
			return (all->texEA);
}

int	cast_rays(t_all *all)
{
	int		x;
	t_img	*tmp;

	// all->sprite->z_buffer = malloc((sizeof(double)) * all->param_map->scr_w);
	x = 0;
	while (x < all->param_map->scr_w)
	{
		cr_part1(all, x);
		cr_part2(all);
		while (all->algo_data->hit == 0)
			cr_part3(all, x);
		cr_part4(all);
		tmp = chooseTex(all);
		cr_part5(all, tmp);
		cr_part6(all, x, tmp);
		x++;
	}
	return (0);
}
