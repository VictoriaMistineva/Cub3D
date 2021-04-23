#include "cub.h"

void	mlx_loops_and_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx.ptr, all_hook, data);
	mlx_hook(data->mlx.win, 2, 1L << 0, &key_pressed, data);
	mlx_hook(data->mlx.win, 3, 1L << 1, &key_released, data);
	mlx_hook(data->mlx.win, 17, 0, &simple_exit, data);
	mlx_loop(data->mlx.ptr);
}