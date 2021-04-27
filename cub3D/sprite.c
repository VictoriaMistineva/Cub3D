#include "cub.h"


void sp_1(t_all *all)
{
	int i;

	i = 0;
	all->sprite->sp_dist = malloc(sizeof(double)* all->sprite->sp_num);
	while (i < all->sprite->sp_num)
	{
		all->sprite->sp_order[i] = i;
		// all->sprite->sp_dist[i] = ((all->param_map->posX - all->sprite->sp_cast[i].x) //маллос
		// 	* (all->param_map->posX - all->sprite->sp_cast[i].x)
		// 	+ (all->param_map->posY - all->sprite->sp_cast[i].y)
		// 	* (all->param_map->posY - all->sprite->sp_cast[i].y));
		all->sprite->sp_dist[i] = sqrt(pow(all->param_map->posX - all->sprite[i].x, 2) + pow(all->param_map->posY - all->sprite[i].y, 2));	
		i++;
	}
}

void sp_2(t_all *all)
{
	//translate sprite position to relative to camera
	int i = 0;
	all->sprite->spriteX = all->sprite->sp_cast
		[all->sprite->sp_order[i]].x - all->param_map->posX;
	all->sprite->spriteY = all->sprite->sp_cast
		[all->sprite->sp_order[i]].y - all->param_map->posY;

	//required for correct matrix multiplication
	all->sprite->invDet = 1.0 / (all->param_map->planeX * all->param_map->dirY- all->param_map->dirX * all->param_map->planeY);
	all->sprite->transformX = all->sprite->invDet * (all->param_map->dirY*all->sprite->spriteX- all->param_map->dirX* all->sprite->spriteY);
	all->sprite->transformY = all->sprite->invDet * (-all->param_map->planeY * all->sprite->spriteX + all->param_map->planeX* all->sprite->spriteY);
	all->sprite->spriteScreenX = (int)((all->param_map->scr_w/ 2.0) * (1 + all->sprite->transformX / all->sprite->transformY));
	all->sprite->spriteHeight = abs((int)(all->param_map->scr_h/ (all->sprite->transformY)));
	all->sprite->drawStartY= -all->sprite->spriteHeight	/ 2 + all->param_map->scr_h/ 2;
	if (all->sprite->drawStartY < 0)
		all->sprite->drawStartY= 0;
}

void	sp_3(t_all *all) //calculate width of the sprite
{
	all->sprite->drawEndY= all->sprite->spriteHeight/ 2 + all->param_map->scr_h/ 2;
	if (all->sprite->drawEndY>= all->param_map->scr_h)
		all->sprite->drawEndY= all->param_map->scr_h- 1;
	all->sprite->spriteWidth= abs((int)(all->param_map->scr_h/ (all->sprite->transformY)));
	all->sprite->drawStartX= -all->sprite->spriteWidth/ 2 + all->sprite->spriteScreenX;
	if (all->sprite->drawStartX< 0)
		all->sprite->drawStartX= 0;
	all->sprite->drawEndX= all->sprite->spriteWidth/ 2 + all->sprite->spriteScreenX;
	if (all->sprite->drawEndX >= all->param_map->scr_w)
		all->sprite->drawEndX = all->param_map->scr_w - 1;
}

void	cs_part4(t_all *all, int stripe, int y)
{
	t_img *texS;

	all->sprite->texX = (int)(256 * (stripe - (-all->sprite->spriteWidth/ 2 + all->sprite->spriteScreenX)) * texS->width/ all->sprite->spriteWidth) / 256;
	if (all->sprite->transformY > 0 && stripe > 0
		&& stripe < all->param_map->scr_w
		&& all->sprite->transformY < all->sprite->z_buffer[stripe])
	{
		y = all->sprite->drawStartY;
		while (y < all->sprite->drawEndY)
		{
			all->sprite->d = (y) * 256 - all->param_map->scr_h * 128 + all->sprite->spriteHeight* 128;
			all->sprite->texY = ((all->sprite->d * texS->height) / all->sprite->spriteHeight) / 256;
			all->sprite->color = *(unsigned int *)(texS->addr + (all->sprite->texY * texS->line_len + all->sprite->texX * (texS->bpp / 8)));
			if ((all->sprite->color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(all->win, stripe, y, all->sprite->color);
			y++;
		}
	}
}

void	cast_sprites(t_all *all)
{
	int coun_sp;
	int sptite;
	int y;

	y = 0;
	coun_sp = 0;
	//int spriteOrder[sp_num];
	all->sprite->sp_order = malloc((sizeof(int)) * all->sprite->sp_num);
	//all->sprite->sp_order = 0;
	// // all->sprite->sp_cast = (t_sprite *)malloc(sizeof(t_sprite) * all->sprite->sp_num);
	// all->sprite->sp_cast = malloc(all->sprite->sp_num * sizeof(t_sp_cast));
	sp_1(all);
	// sort_sprites(&(all->sprite));
	//coun_sp = 0;
	int i = 0;
	while(i < all->sprite->sp_num)
	{
		sp_2(all);
		sp_3(all);
		sptite = all->sprite->drawStartX;
		while(sptite < all->sprite->drawEndX)
		{
			cs_part4(all, sptite, y);
			sptite++;
		}
		i++;
	}
}

