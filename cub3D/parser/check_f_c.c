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

	if (all->pm->floor_r != -1)
		printf_exit("двойной ввод цвета для FLOOR");
	return_space(line);
	color = ft_split((char const *)line, ' ');
	validate_color(all->pm->floor_r = ft_atoi_pars(color[1]));
	validate_color(all->pm->floor_g = ft_atoi_pars(color[2]));
	validate_color(all->pm->floor_b = ft_atoi_pars(color[3]));
	free_res(color);
	all->pm->color_floor = create_rgb(all->pm->floor_r,
			all->pm->floor_g, all->pm->floor_b);
	return (1);
}

int	celling_color(char *line, t_all *all)
{
	char	**color;

	if (all->pm->ceil_r != -1)
		printf_exit("двойной ввод цвета для CELLING");
	return_space(line);
	color = ft_split((char const *)line, ' ');
	validate_color(all->pm->ceil_r = ft_atoi_pars(color[1]));
	validate_color(all->pm->ceil_g = ft_atoi_pars(color[2]));
	validate_color(all->pm->ceil_b = ft_atoi_pars(color[3]));
	free_res(color);
	all->pm->color_ceil = create_rgb(all->pm->ceil_r,
			all->pm->ceil_g, all->pm->ceil_b);
	return (1);
}
