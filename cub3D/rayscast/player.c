/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:05:58 by ycordell          #+#    #+#             */
/*   Updated: 2021/05/01 20:29:09 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_ns_player(t_all *all, char map)
{
	if (map == 'N')
	{
		all->prm_map->dirX= 0;
		all->prm_map->dirY = -1;
		all->prm_map->planeX = 0.66;
		all->prm_map->planeY = 0;
	}
	if (map == 'S')
	{
		all->prm_map->dirX= 0;
		all->prm_map->dirY = 1;
		all->prm_map->planeX = -0.66;
		all->prm_map->planeY = 0;
	}
}

void	check_we_player(t_all *all, char map)
{
	if (map == 'W')
	{
		all->prm_map->dirX = -1;
		all->prm_map->dirY = 0;
		all->prm_map->planeX = 0;
		all->prm_map->planeY = -0.66;
	}
	if (map == 'E')
	{
		all->prm_map->dirX = 1;
		all->prm_map->dirY = 0;
		all->prm_map->planeX = 0;
		all->prm_map->planeY = 0.66;
	}
}

void	check_player(t_all *all)
{
	int	k;
	int	j;

	k = 0;
	while (all->map[k])
	{
		j = 0;
		while (all->map[k][j])
		{
			if (all->map[k][j] == 'N' || all->map[k][j] == 'S'
				|| all->map[k][j] == 'W' || all->map[k][j] == 'E')
			{
				check_player_map(all);
				if (all->prm_map->posX == 0)
				{
					all->prm_map->posX = j + 0.5;
					all->prm_map->posY = k + 0.5;
					check_ns_player(all, all->map[k][j]);
					check_we_player(all, all->map[k][j]);
					all->map[k][j] = '0';
				}
			}
			j++;
		}
		k++;
	}
}
