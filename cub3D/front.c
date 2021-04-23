#include "cub.h"

void	draw_fl_and_ce(t_all *all)
{
	int		x;
	int		dr;
	int		dr1;

	t_param_map *param_map;

	x = 0;
	while (x < param_map->scr_w)
	{
		dr = 0;
		while (dr <= param_map->scr_h / 2)
		{
			my_mlx_pixel_put(all->win, x, dr, param_map->color_ceil);
			dr++;
		}
		dr1 = param_map->scr_h / 2;
		while (dr1 <= param_map->scr_h - 1)
		{
			my_mlx_pixel_put(all->win, x, dr1, param_map->color_floor);
			dr1++;
		}
		x++;
	}
}

