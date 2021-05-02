#include "cub.h"

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	init_struct(t_all *all)
{
	all->pm->scr_h = -1;
	all->pm->scr_w = -1;
	all->pm->floor_r = -1;
	all->pm->floor_g = -1;
	all->pm->floor_b = -1;
	all->pm->ceil_r = -1;
	all->pm->ceil_g = -1;
	all->pm->ceil_b = -1;
	all->pm->color_ceil = 0;
	all->pm->color_floor = 0;
	all->pm->north = NULL;
	all->pm->south = NULL;
	all->pm->east = NULL;
	all->pm->west = NULL;
	all->pm->sprite = NULL;
	all->pm->posX = 0;
	all->pm->posY = 0;
	all->pm->dirY = 0;
	all->pm->dirX = 0;
	all->pm->plY = 0;
	all->pm->plX = 0;
}
