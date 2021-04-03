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
	// if(all->param_map->scr_w != 0 || all->param_map->scr_h != 0) // flag
	// {
	// 	printf("повтор R");
	// 	exit(0);
	// }
	resolution = ft_split((char const *)line,' ');
	// printf("%s\n", resolution[1]);
	//printf("%s\n", resolution[1]);
	all->param_map->scr_w  = 0;
	all->param_map->scr_w = ft_atoi(resolution[1]);
	all->param_map->scr_h = ft_atoi(resolution[2]);
	printf("%d%d",all->param_map->scr_w, all->param_map->scr_h);
	return (0);
}
