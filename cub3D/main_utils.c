#include "cub.h"

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
