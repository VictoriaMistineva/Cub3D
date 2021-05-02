#include "cub.h"
#include <fcntl.h>
#include <stdio.h>

void	mall_struct(t_all *all)
{	
	all->win = malloc(sizeof(t_win));
	all->pm = malloc(sizeof(t_pm));
	all->gl = malloc(sizeof(t_gl));
	all->txtr_data = malloc(sizeof(t_txtr_data));
	all->sprite = malloc(sizeof(t_sprite));
}

void	mlx_render(t_all *all, void *mlx)
{
	init_tex(all);
	init_tex_2(all);
	mlx_hook(all->win->mlx, 2, 1L << 0, move, all);
	mlx_put_image_to_window(mlx, all->win->mlx, all->win->img, 0, 0);
	mlx_loop_hook(all->mlx, render_next_frame, all);
	mlx_loop(all->mlx);
}

void	set_cub_struct(t_all *all, int argc, char **argv)
{
	mall_struct(all);
	set_cub(all, argv, argc);
	is_save(argv, all, argc);
}

void	map_init(t_all *all, char *line)
{
	char	*bigLine;

	bigLine = NULL;
	init_map(all, line, bigLine);
}

int	main(int argc, char **argv)
{
	t_all		all;
	t_point		point;
	t_pm		*pm;
	void		*mlx;
	char		*line;

	line = NULL;
	set_cub_struct(&all, argc, argv);
	pm = all.pm;
	init_struct(&all);
	map_init(&all, line);
	check_player(&all);
	check_map(&all);
	free(line);
	malloc_sp(&all);
	all.mlx = mlx_init();
	all.win->mlx = mlx_new_window(all.mlx, pm->scr_w, pm->scr_h, "CUB_3D");
	all.win->img = mlx_new_image(all.mlx, pm->scr_w, pm->scr_h);
	all.win->addr = mlx_get_data_addr(all.win->img, &all.win->bits_per_pixel,
			&all.win->line_length, &all.win->endian);
	mlx_render(&all, mlx);
}
