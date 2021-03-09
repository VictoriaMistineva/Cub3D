#include "cub.h"
#include <mlx.h>

void window(void)
{
	void *mlx = NULL;
	void *win = NULL;
	int x = 100;
	int y = 100;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480 , "test");
	while(y++ < 200)
	{
		x = 100;
		while(x++ < 200)
			mlx_pixel_put(mlx, win, x, y, 0xFFFF1);
	}
	while(y++ < 400)
	{
		x = 100;
		while(x++ < 600)
			mlx_pixel_put(mlx, win, x, y, 0xFFFF6);
	}
	mlx_loop(mlx);
}










// void window(void)
// {
// 	void *mlx = NULL;
// 	void *win = NULL;
// 	int x = 100;
// 	int y = 100;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 640, 480 , "test");
// 	while(y++ < 200)
// 	{
// 		x = 100;
// 		while(x++ < 200)
// 			mlx_pixel_put(mlx, win, x, y, 0xFFFF1);
// 	}
// 	while(y++ < 400)
// 	{
// 		x = 100;
// 		while(x++ < 600)
// 			mlx_pixel_put(mlx, win, x, y, 0xFFFF6);
// 	}
// 	mlx_loop(mlx);
// }