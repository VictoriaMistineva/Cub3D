#include "cub.h"

// void	mlx_loops_and_hooks(t_all *all)
// {
// 	mlx_loop_hook(data->mlx.ptr, all_hook, data);
// 	mlx_hook(data->mlx.win, 2, 1L << 0, &key_pressed, data);
// 	mlx_hook(data->mlx.win, 3, 1L << 1, &key_released, data);
// 	mlx_hook(data->mlx.win, 17, 0, &simple_exit, data);
// 	mlx_loop(data->mlx.ptr);
// }

// void	draw_fl_and_ce(t_all *all)
// {
// 	int		x;
// 	int		dr;
// 	int		dr1;

// 	t_param_map *param_map;

// 	x = 0;
// 	while (x < param_map->scr_w)
// 	{
// 		dr = 0;
// 		while (dr <= param_map->scr_h / 2)
// 		{
// 			my_mlx_pixel_put(all->win, x, dr, param_map->color_ceil);
// 			dr++;
// 		}
// 		dr1 = param_map->scr_h / 2;
// 		while (dr1 <= param_map->scr_h - 1)
// 		{
// 			my_mlx_pixel_put(all->win, x, dr1, param_map->color_floor);
// 			dr1++;
// 		}
// 		x++;
// 	}
// }