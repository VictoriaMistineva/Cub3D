/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:30:19 by ycordell          #+#    #+#             */
/*   Updated: 2021/05/01 18:32:55 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	coord_sprite(t_all *all)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	while (all->map[k])
	{
		j = 0;
		while (all->map[k][j])
		{
			if (all->map[k][j] == '2')
			{
				all->sprite->sp[i].x = j + 0.5;
				all->sprite->sp[i].y = k + 0.5;
				i++;
			}
			j++;
		}
		k++;
	}
}

void	sp_1(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->sprite->sp_num)
	{
		all->sprite->sp_order[i] = i;
		all->sprite->sp_dist[i] = sqrt(pow(all->param_map->posX
					- all->sprite->sp[i].x, 2)
				+ pow(all->param_map->posY - all->sprite->sp[i].y, 2));
		i++;
	}
}

void	sp_drawstart(t_all *all, int i)
{
	all->sprite->invDet = 1.0 / (all->param_map->planeX * all->param_map->dirY
			- all->param_map->dirX * all->param_map->planeY);
	all->sprite->spriteX = (double)all->sprite->sp[all->sprite->sp_order[i]].x
		- all->param_map->posX;
	all->sprite->spriteY = all->sprite->sp[all->sprite->sp_order[i]].y
		- all->param_map->posY;
	all->sprite->transformX = all->sprite->invDet
		* (all->param_map->dirY * all->sprite->spriteX - all->param_map->dirX
			* all->sprite->spriteY);
	all->sprite->transformY = all->sprite->invDet
		* (-all->param_map->planeY * all->sprite->spriteX
			+ all->param_map->planeX * all->sprite->spriteY);
	all->sprite->sp_dist[i] = all->sprite->transformY;
	all->sprite->spriteScreenX = (int)((all->param_map->scr_w / 2)
			* (1 + all->sprite->transformX / all->sprite->transformY));
	all->sprite->spriteHeight = abs((int)(all->param_map->scr_h
				/ (all->sprite->transformY)));
	all->sprite->drawStartY = -all->sprite->spriteHeight / 2
		+ all->param_map->scr_h / 2;
	if (all->sprite->drawStartY < 0)
		all->sprite->drawStartY = 0;
}

void	sp_drawend(t_all *all)
{
	all->sprite->drawEndY = all->sprite->spriteHeight / 2 + all->param_map->scr_h / 2;
    if(all->sprite->drawEndY >= all->param_map->scr_h)
        all->sprite->drawEndY = all->param_map->scr_h - 1;
    all->sprite->spriteWidth = abs((int)(all->param_map->scr_h / (all->sprite->transformY)));
    all->sprite->drawStartX = -all->sprite->spriteWidth / 2 + all->sprite->spriteScreenX;
    if(all->sprite->drawStartX < 0)
        all->sprite->drawStartX = 0;
    all->sprite->drawEndX = all->sprite->spriteWidth / 2 + all->sprite->spriteScreenX;
    if(all->sprite->drawEndX >= all->param_map->scr_w)
        all->sprite->drawEndX = all->param_map->scr_w - 1;
}

void	sp_color(t_all *all)
{
	t_img *texS;
	int stripe;
	int y;

	texS = all->texS;
	stripe = all->sprite->drawStartX;
	while(stripe < all->sprite->drawEndX)
	{
		all->sprite->texX = (int)(256 * (stripe - (-all->sprite->spriteWidth/ 2 + all->sprite->spriteScreenX)) * texS->width/ all->sprite->spriteWidth) / 256;
		if (all->sprite->transformY > 0 && stripe > 0 && stripe < all->param_map->scr_w && all->sprite->transformY < all->sprite->z_buffer[stripe])
			y = all->sprite->drawStartY;
			while (y < all->sprite->drawEndY)
			{
				all->sprite->d = (y) * 256 - all->param_map->scr_h * 128 + all->sprite->spriteHeight * 128;
                all->sprite->texY = ((all->sprite->d * all->texS->height) / all->sprite->spriteHeight) / 256;
                    all->sprite->color = *(unsigned int *)(all->texS->addr + all->sprite->texY * all->texS->line_len + all->sprite->texX * (all->texS->bpp / 8));
				if ((all->sprite->color & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(all->win, stripe, y, all->sprite->color);
				y++;
			}
		stripe++;
	}
}

void	cast_sprites(t_all *all)
{
	int i;

	i = 0;
	coord_sprite(all);
	sp_1(all);
	i = 0;
	sotirovka_sprite(all->sprite);
	while(i < all->sprite->sp_num)
	{
		sp_drawstart(all, i);
		sp_drawend(all);
		sp_color(all);
		i++;
	}
}

