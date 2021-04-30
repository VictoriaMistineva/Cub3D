#include "../cub.h"

char	*return_space(char *line)
{
	char	*tmp;

	tmp = line;
	while (*tmp != '\0')
	{
		if (*tmp == ',')
			*tmp = ' ';
		tmp++;
	}
	tmp = line;
	return (line);
}

void	free_res(char **color)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		free(color[k]);
		k++;
	}
	free(color);
}

int	floor_color(char *line, t_all *all)
{
	char	**color;

	if (all->param_map->floor_r != -1)
		printf_exit("двойной ввод цвета для FLOOR");
	return_space(line);
	color = ft_split((char const *)line, ' ');
	validate_color(all->param_map->floor_r = ft_atoi_pars(color[1]));
	validate_color(all->param_map->floor_g = ft_atoi_pars(color[2]));
	validate_color(all->param_map->floor_b = ft_atoi_pars(color[3]));
	free_res(color);
	all->param_map->color_floor = create_rgb(all->param_map->floor_r, all->param_map->floor_g, all->param_map->floor_b);
	return (1);
}

int	celling_color(char *line, t_all *all)
{
	char	**color;

	if (all->param_map->ceil_r != -1)
		printf_exit("двойной ввод цвета для CELLING");
	return_space(line);
	color = ft_split((char const *)line, ' ');
	validate_color(all->param_map->ceil_r = ft_atoi_pars(color[1]));
	validate_color(all->param_map->ceil_g = ft_atoi_pars(color[2]));
	validate_color(all->param_map->ceil_b = ft_atoi_pars(color[3]));
	free_res(color);
	all->param_map->color_ceil = create_rgb(all->param_map->ceil_r, all->param_map->ceil_g, all->param_map->ceil_b);
	return (1);
}
