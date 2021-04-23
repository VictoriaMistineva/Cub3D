#include "cub.h"

void check_player_map(t_all *all, int k, int j)
{
	if(all->param_map->posX != 0)	
		printf_exit("Два игрока на карте");
}			
			
void	check_cell(t_all *all, int j, int k)
{
    if(all->map[k][j] == ' ' || all->map[k][j] == '1')
        return ;
    if (j == 0 || k == 0 || j == (all->param_map->scr_w - 1)
        || k == (all->param_map->scr_h - 1))
        printf_exit("нет карты");
    if (all->map[k + 0][j + 1] == ' '
        || all->map[k + 0][j - 1] == ' '
        || all->map[k + 1][j + 0] == ' '
        || all->map[k - 1][j + 0] == ' '
        || all->map[k - 1][j + 1] == ' '
        || all->map[k - 1][j - 1] == ' '
        || all->map[k + 1][j - 1] == ' '
        || all->map[k + 1][j + 1] == ' ')
        printf_exit("невалидная карта");
    if (ft_strchr(PLAYER ,all->map[k][j]))
    {
        all->param_map->posY = k;
        all->param_map->posX = j;
    }
}

void	check_invalid(t_all *all, int k, int j)
{
	if (!(ft_strchr(VALID_MAP, all->map[k][j]))) //проверить символы
		printf_exit("Невалидный символ в карте или его нет");
	if (j == 0 || all->map[k][j + 1] == '\0') //ширина
	{
		if (all->map[k][j] != '1' && all->map[k][j] != ' ')
			printf_exit("открытое пространство");
	}
	if (k == 0 || k == all->param_map->scr_h - 1) //высота и конец высоты
		{
			if (all->map[k][j] != '1' && all->map[k][j] != ' ')
				printf_exit("открытое пространство");
		}

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
			check_player_map(all, j, k);
			check_cell(all, j, k);
			check_invalid(all, k, j);
			j++;
		}
		k++;
	}
}