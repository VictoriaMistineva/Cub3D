#include "cub.h"

void	check_ns_player(t_all *all, char map)
{
	if (map == 'N')
	{
		all->param_map->dirX= 0;
		all->param_map->dirY = -1;
		all->param_map->planeX = 0.66;
		all->param_map->planeY = 0;
	}
	if (map == 'S')
	{
		all->param_map->dirX= 0;
		all->param_map->dirY = 1;
		all->param_map->planeX = -0.66;
		all->param_map->planeY = 0;
	}
}

void	check_we_player(t_all *all, char map)
{
	if (map == 'W')
	{
		all->param_map->dirX= -1;
		all->param_map->dirY = 0;
		all->param_map->planeX = 0;
		all->param_map->planeY = -0.66;
	}
	if (map == 'E')
	{
		all->param_map->dirX= 1;
		all->param_map->dirY = 0;
		all->param_map->planeX = 0;
		all->param_map->planeY = 0.66;
	}
}

void	check_player(t_all *all)
{
	int k;
	int j;
	all->sprite->sp_num = 0;
	k = 0;
	while (all->map[k])
	{
		j = 0;
		while (all->map[k][j])
		{
			if (all->map[k][j] == 'N' || all->map[k][j] == 'S' 
				|| all->map[k][j] == 'W' || all->map[k][j] == 'E')
			{
				if (all->param_map->posX == 0)
				{
					all->param_map->posX = j + 0.5;
					all->param_map->posY = k + 0.5;
					check_ns_player(all, all->map[k][j]);
					check_we_player(all, all->map[k][j]);
					// all->param_map->planeX = all->param_map->dirY * -0.66;
                	// all->param_map->planeY = all->param_map->dirX * 0.66;
					all->map[k][j] = '0';
				}
				else
				{
					printf_exit("Два игрока");
				}
			}
			else if (all->map[k][j] == '2')
				all->sprite->sp_num++;
			j++;
		}
		k++;
	}
}
