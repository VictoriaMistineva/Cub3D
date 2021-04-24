#include "../cub.h"

int	charlen(char **str)
{
	int i;
	i = 0;
	while(str[i]!='\0')
		i++;
	return i;
}
char	*printf_exit(char *str)
{
	printf("%s\n", str);
	exit(-1);
}

int	ft_atoi_pars(const char *str)
{
	unsigned int	i;

	i = 0;
	while (*str)
	{
		if(*str >= '0' && *str <= '9')
		{
			i = i * 10 + *str - '0';
			str++;
		}
		else
			printf_exit("Error\nневалидная карта");
	}
	return (i);
}
int	type_flags_check(t_all *all)
{
	if(all->param_map->scr_h != -1 && all->param_map->scr_w != -1)
		if(all->param_map->floor_r != -1)
			if(all->param_map->ceil_r != -1)
					return(0);
	return (1);
}
int	check_num(const char *str, int num)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != num)
			return (0);
		i++;
	}
	return (1);
}