#include "cub.h"
#include "Libft/includes/libft.h" 

int charlen(char **str)
{
	int i;
	i = 0;
	while(str[i]!='\0')
		i++;
	return i;
}

int check_resolution(char *line, t_all *all)
{
	char **resolution;
	printf("Y= %d %d\n",all->param_map->scr_w, all->param_map->scr_h);
	// if(all->param_map->scr_w != 0 && all->param_map->scr_h != 0) // flag
	// {
	// 	printf("двойной ввод R");
	// 	exit(0);
	// }
	resolution = ft_split((char const *)line,' ');
	all->param_map->scr_w = ft_atoi(resolution[1]);
	all->param_map->scr_h = ft_atoi(resolution[2]);
	printf("MY= %d %d\n",all->param_map->scr_w, all->param_map->scr_h);
	return (1);
}
int check_north(char *line, t_all *all)
{
	return 0;
}

int check_south(char *line, t_all *all)
{
	return 0;
}