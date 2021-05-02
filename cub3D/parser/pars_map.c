#include "../cub.h"

void	check_player_map(t_all *all)
{
	if (all->pm->posX != 0)
		printf_exit("Два игрока на карте");
}			

void	check_cell(t_all *all, int j, int k)
{
	if (all->map[k][j] == ' ' || all->map[k][j] == '1')
		return ;
	if (j == 0 || k == 0 || j == (all->pm->scr_w - 1)
		|| k == (all->pm->scr_h - 1))
		printf_exit ("невалидная карта");
	if (all->map[k + 0][j + 1] == ' '
		|| all->map[k + 0][j - 1] == ' '
		|| all->map[k + 1][j + 0] == ' '
		|| all->map[k - 1][j + 0] == ' '
		|| all->map[k - 1][j + 1] == ' '
		|| all->map[k - 1][j - 1] == ' '
		|| all->map[k + 1][j - 1] == ' '
		|| all->map[k + 1][j + 1] == ' ')
		printf_exit("невалидная карта");
}

void	check_invalid(t_all *all, int k, int j)
{
	if (!(ft_strchr(VALID_MAP, all->map[k][j])))
		printf_exit("Невалидный символ в карте или его нет");
	if (j == 0 || all->map[k][j + 1] == '\0')
	{
		if (all->map[k][j] != '1' && all->map[k][j] != ' ')
			printf_exit("открытое пространство");
	}
	if (k == 0 || k == all->pm->scr_h - 1)
	{
		if (all->map[k][j] != '1' && all->map[k][j] != ' ')
			printf_exit("открытое пространство");
	}
}

void	check_map(t_all *all)
{
	int	k;
	int	j;

	k = 0;
	while (all->map[k])
	{
		j = 0;
		while (all->map[k][j])
		{
			check_cell(all, j, k);
			check_invalid(all, k, j);
			j++;
		}
		k++;
	}
}
