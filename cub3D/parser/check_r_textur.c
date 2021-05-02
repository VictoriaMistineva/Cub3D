#include "../cub.h"

int	resolution(char *line, t_all *all)
{
	char	**resolution;

	if (all->pm->scr_h != -1 && all->pm->scr_w != -1)
		printf_exit("двойной ввод R");
	resolution = ft_split(line, ' ');
	all->pm->scr_w = ft_atoi_pars(resolution[1]);
	all->pm->scr_h = ft_atoi_pars(resolution[2]);
	array_f(resolution);
	return (1);
}

int	check_texture(char *line, char **texture)
{
	int	i;

	i = 2;
	if (*texture != NULL)
		printf_exit("двойной ввод texture");
	while (line[i] == ' ')
		i++;
	*texture = ft_strdup(&line[i]);
	return (1);
}
