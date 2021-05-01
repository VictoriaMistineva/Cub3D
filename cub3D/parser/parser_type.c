#include "../cub.h"

int	type_identifier(char *line, t_all *all)
{
	int	i;

	i = -1; 
	while (line[++i])
	{
		if (line[i] == 'R' && line[i + 1] == ' ')
			return (resolution(line, all));
		else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
			return (check_texture(line, &all->pm->north));
		else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
			return (check_texture(line, &all->pm->south));
		else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
			return (check_texture(line, &all->pm->west));
		else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
			return (check_texture(line, &all->pm->east));
		else if (line[i] == 'S' && line[i + 1] == ' ')
			return (check_texture(line, &all->pm->sprite));
		else if (line[i] == 'F' && line[i + 1] == ' ')
			return (floor_color(line, all));
		else if (line[i] == 'C' && line[i + 1] == ' ')
			return (celling_color(line, all));
		else
		{
			printf_exit("ошибка типов");
		}
	}
	return (0);
}
