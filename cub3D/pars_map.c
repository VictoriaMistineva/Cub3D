#include "cub.h"

int	check_space_width(t_all *all, int k, int j)
{
	if (j != 0)
	{
		if((all->map[k][j - 1] == '0')
			|| (all->map[k][j - 1] == '2'))
			return(0);
	}
	if (j != (int)ft_strlen(all->map[k] - 1))
	{
		if((all->map[k][j + 1] == '0'
			|| all->map[k][j + 1] == '2'))
			return(0);
	}
	else
		printf_exit("открытое пространство");
	// all->map[k][j] = '1';
}

int	check_space(t_all *all, int k, int j)
{
	if (all->map[k][j] == ' ')
	{
		if (k != 0)
		{
			if((all->map[k - 1][j] == '0'
				|| all->map[k - 1][j] == '2'))
				return(0);
		}
		if (k != all->param_map->scr_h - 1)
		{
			if((all->map[k + 1][j] == '0'
				|| all->map[k + 1][j] == '2'))
				return(0);
		}
		check_space_width(all, k, j);
	}
}

void	check_invalid(t_all *all, int k, int j)
{
	// printf("x: %i y: %i map %c\n", j, k, all->map[k][j]);
	if (!(ft_strchr(VALID_MAP, all->map[k][j]))) //проверить символы
		printf_exit("Невалидный символ в карте или его нет");
	if (j == 0 || all->map[k][j + 1] == '\0') //ширина
	{
		if (all->map[k][j] != '1')
		{
			//printf("x: %i y: %i map %c\n", j, k, all->map[k][j]);
			printf_exit("открытое пространство j");
		}
	}
	if (k == 0 || k == all->param_map->scr_h - 1) //высота и конец высоты
		{
			if (all->map[k][j] != '1')
				printf_exit("открытое пространство k");
		}
	if (ft_strchr(PLAYER, all->map[k][j]))
			
			printf_exit("Два игрока на карте");
}

void	check_map(t_all *all)
{
	int k;
	int j;

	k = 0;
	while (all->map[k])
	{
		j = 0;
		while (all->map[k][j])
		{
			check_space(all, k, j);
			check_invalid(all, k, j);
			j++;
		}
		k++;
	}
}