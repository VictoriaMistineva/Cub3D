#include "cub.h"
int		check_num(const char *str, int num)
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

// void	check_for_space_extra(t_all *all, int k, int j)
// {
// 	if (j != 0)
// 	{
// 		(all->map[k][j - 1] == '0'
// 		|| all->map[k][j - 1] == '2')
// 	}
// 	if (j != (int)ft_strlen(all->map[k] - 1))
// 	{
// 		(all->map[k][j + 1] == '0'
// 		|| all->map[k][j + 1] == '2')
// 	}
// 	// if (error)
// 	// {
// 	// 	printf_exit("Карта не валидна, открытое пространство");
// 	// }
// 	all->map[k][j] = '1';
// }

// void	check_space(t_all *all, int k, int j)
// {
// 	int	error;

// 	error = 0;
// 	if (all->map[k][j] == ' ')
// 	{
// 		if (k != 0)
// 		{
// 			(all->map[k - 1][j] == '0'
// 			|| all->map[k - 1][j] == '2')
// 		}
// 		if (k != all->param_map->scr_h - 1)
// 		{
// 			(all->map[k + 1][j] == '0'
// 			|| all->map[k + 1][j] == '2')
// 		}
// 		check_for_space_extra(all, k, j);
// 	}
// }

void	check_invalid(t_all *all, int k, int j)
{
	if (!ft_strchr(VALID_MAP, all->map[k][j])) //проверить символы
		printf_exit("Невалидный символ в карте");
	if (j == 0 || all->map[k][j + 1] == '\0') //ширина
	{
		if (all->map[k][j] != '1')
			printf_exit("открытое пространство");
	}
	if (k == 0 || k == all->param_map->scr_h - 1) //высота и конец высоты
		{
			if (check_num(all->map[k], '1') > 0)
				printf_exit("открытое пространство");
		}
	if (ft_strchr(PLAYER, all->map[k][j]))
	{
			//проверить флаг для сторон света
			printf_exit("Два игрока на карте");
	} 
}

void	check_map(t_all *all)
{
	int k;
	int j;

	k = 0;
	while (all->map[k])//проверяем есть ли у нас карта
	{
		j = 0;
		while (all->map[k][j])
		{
			check_invalid(&all->map, k, j);
			//check_space(&all->map, k, j);
			j++;
		}
		k++;
	}
}