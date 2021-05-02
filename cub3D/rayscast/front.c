#include "../cub.h"

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
	int	y;

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
				(tex->addr + (all->txtr_data->tex_y
						* tex->line_len + all->txtr_data->tex_x
						* (tex->bpp / 8)));
			my_mlx_pixel_put(all->win, x, y, all->txtr_data->color);
		}
		if (y > all->gl->draw_end)
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
	{
		if (all->gl->mapX > all->pm->posX)
			return (all->texWE);
		else
			return (all->texEA);
	}
}

int	cast_rays(t_all *all)
{
	int		x;
	t_img	*tmp;

	x = 0;
	while (x < all->pm->scr_w)
	{
		cr_part1(all, x);
		cr_X(all);
		cr_Y(all);
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
