#include "cub.h"

static void floor_ceiling_check(t_all *all)
{
	if(all->param_map->floor_r != 0)
		printf_exit("двойной ввод цвета для FLOOR");
	if(all->param_map->ceil_r != 0
			&& all->param_map->ceil_g != 0 && all->param_map->ceil_b != 0)
		printf_exit("двойной ввод цвета для CELL");
}

int floor_texture(char *line, t_all *all)
{
	char **color;
	printf(" Y= %d %d %d\n",all->param_map->floor_r , all->param_map->floor_g, all->param_map->floor_b );
	if(all->param_map->floor_r != 0)
		printf_exit("двойной ввод цвета для FLOOR");
	color = ft_split((char const *)line,' ');
		free(color);
	color = ft_split(color[1],',');
	all->param_map->floor_r = ft_atoi(color[0]);
	all->param_map->floor_g = ft_atoi(color[1]);
	all->param_map->floor_b = ft_atoi(color[2]);
	printf(" MY= %d %d %d\n",all->param_map->floor_r , all->param_map->floor_g, all->param_map->floor_b );
	return(1);
}
//color сплит по пробелам сплит от 1 аргумента по запятой 