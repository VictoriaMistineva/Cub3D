#include "cub.h"
#include "Libft/includes/libft.h" 
#include <fcntl.h>
#include <stdio.h>

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

int	render_next_frame(t_all *all)
{
	mlx_clear_window(all->mlx, all->win->mlx);
	cast_rays(all);
	cast_sprites(all);
	if (all->flag_save == 1)
		create_screenshot(all);
	mlx_put_image_to_window(all->mlx, all->win->mlx, all->win->img, 0, 0);
	mlx_do_sync(all->mlx);
	return (0);
}

void	malloc_sp(t_all *all)
{
	all->sprite->sp_dist = malloc(sizeof(double) * all->sprite->sp_num);
	all->sprite->sp_order = malloc((sizeof(int)) * all->sprite->sp_num);
	all->sprite->sp_cast = malloc(sizeof(t_sprite) * all->sprite->sp_num);
	all->sprite->sp = malloc(sizeof(t_sprite));
	all->sprite->z_buf = malloc((sizeof(double)) * all->pm->scr_w);
}

void	init_tex(t_all *all)
{
	t_img		*texNO;
	t_img		*texSO;

	texNO = (t_img *)malloc(sizeof(t_img));
	texNO->img = mlx_png_file_to_image(all->mlx, all->pm->north,
			&texNO->width, &texNO->height);
	texNO->addr = mlx_get_data_addr(texNO->img, &texNO->bpp,
			&texNO->line_len, &texNO->endian);
	all->texNO = texNO;
	texSO = (t_img *)malloc(sizeof(t_img));
	texSO->img = mlx_png_file_to_image(all->mlx, all->pm->south,
			&texSO->width, &texSO->height);
	texSO->addr = mlx_get_data_addr(texSO->img, &texSO->bpp,
			&texSO->line_len, &texSO->endian);
	all->texSO = texSO;
}

void	init_tex_2(t_all *all)
{		
	t_img		*texWE;
	t_img		*texEA;
	t_img		*texS;

	texWE = (t_img *)malloc(sizeof(t_img));
	texWE->img = mlx_png_file_to_image(all->mlx, all->pm->west,
			&texWE->width, &texWE->height);
	texWE->addr = mlx_get_data_addr(texWE->img, &texWE->bpp,
			&texWE->line_len, &texWE->endian);
	all->texWE = texWE;
	texEA = (t_img *)malloc(sizeof(t_img));
	texEA->img = mlx_png_file_to_image(all->mlx, all->pm->east,
			&texEA->width, &texEA->height);
	texEA->addr = mlx_get_data_addr(texEA->img, &texEA->bpp,
			&texEA->line_len, &texEA->endian);
	all->texEA = texEA;
	texS = (t_img *)malloc(sizeof(t_img));
	texS->img = mlx_png_file_to_image(all->mlx, all->pm->sprite,
			&texS->width, &texS->height);
	texS->addr = mlx_get_data_addr(texS->img, &texS->bpp,
			&texS->line_len, &texS->endian);
	all->texS = texS;
}

void	init_map(t_all *all, char *line, char *bigLine)
{	
	int		fd;
	char	*tmp;

	fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (type_flags_check(all) > 0)
			type_identifier(line, all);
		else
		{
			tmp = bigLine;
			bigLine = ft_strjoin(bigLine, line);
			free(tmp);
			tmp = bigLine;
			bigLine = ft_strjoin(bigLine, "\n");
			free(tmp);
		}
		free(line);
	}
	tmp = bigLine;
	bigLine = ft_strjoin(bigLine, line);
	free(tmp);
	all->map = ft_split(bigLine, '\n');
	free(bigLine);
}

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
