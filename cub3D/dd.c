#include "cub.h"

// void coord_sprite(t_all *all)
// {
// 	int i;
// 	int k;
// 	int j;

// 	i = 0;
// 	k = 0;
// 	while (all->map[k])
// 	{
// 		j = 0;
// 		while (all->map[k][j])
// 		{
// 			if (all->map[k][j] == '2')
// 			{
// 				all->sprite->sp[i].x = j + 0.5;
// 				all->sprite->sp[i].y = k + 0.5;
// 					// printf("map %f\n",all->sprite->sp[i].x);
// 					i++;
// 			}
// 			j++;
// 		}
// 		k++;
// 	}
// }
	
// void sp_1(t_all *all)
// {
// 	int i;
// 	i = 0;
// 	// all->sprite->sp_dist = malloc(sizeof(double)* all->sprite->sp_num);
// 	while (i < all->sprite->sp_num)
// 	{
// 		all->sprite->sp_order[i] = i;
// 		all->sprite->sp_dist[i] = sqrt(pow(all->param_map->posX - all->sprite->sp[i].x, 2) 
// 			+ pow(all->param_map->posY - all->sprite->sp[i].y, 2));	
// 		i++;
// 	}
// }

// void sp_wh(t_all *all)
// {
// 	//translate sprite position to relative to camera
// 	int i;
// 	i = 0;
// 	//required for correct matrix multiplication
// 	all->sprite->invDet = 1.0 / (all->param_map->planeX * all->param_map->dirY - all->param_map->dirX * all->param_map->planeY);

// 	all->sprite->spriteX = (double)all->sprite->sp[all->sprite->sp_order[i]].x - all->param_map->posX;
// 	all->sprite->spriteY = all->sprite->sp[all->sprite->sp_order[i]].y - all->param_map->posY;

// 	// //required for correct matrix multiplication
// 	// all->sprite->invDet = 1.0 / (all->param_map->planeX * all->param_map->dirY - all->param_map->dirX * all->param_map->planeY);
// 	// printf("invDet%f\n", all->sprite->invDet);

// 	all->sprite->transformY = 0;	
// 	all->sprite->transformX = all->sprite->invDet * (all->param_map->dirY*all->sprite->spriteX- all->param_map->dirX* all->sprite->spriteY);
// 	all->sprite->transformY = all->sprite->invDet * (-1 * all->param_map->planeY * all->sprite->spriteX + all->param_map->planeX * all->sprite->spriteY);
	
	
// 	//таааак
// 	// all->sprite->transformY = 0;
// 	all->sprite->sp_dist[i] = all->sprite->transformY;
// 	//таааак


// 		// printf("transformX %f   transformY%f \n", all->sprite->transformX , all->sprite->transformY );

// 	all->sprite->spriteScreenX = (int)((all->param_map->scr_w/ 2) * (1 + all->sprite->transformX / all->sprite->transformY));

// 	all->sprite->spriteHeight = abs((int)(all->param_map->scr_h/ (all->sprite->transformY)));

// 	all->sprite->drawStartY= -all->sprite->spriteHeight	/ 2 + all->param_map->scr_h/ 2;
	
// 	if (all->sprite->drawStartY < 0)
// 		all->sprite->drawStartY= 0;
// }

// void	sp_wh_(t_all *all) //calculate width of the sprite
// {
// 	all->sprite->drawEndY= all->sprite->spriteHeight/ 2 + all->param_map->scr_h/ 2;

// 	if (all->sprite->drawEndY>= all->param_map->scr_h)
// 		all->sprite->drawEndY= all->param_map->scr_h- 1;

// 	all->sprite->spriteWidth= abs((int)(all->param_map->scr_h/ (all->sprite->transformY)));

// 	all->sprite->drawStartX= -all->sprite->spriteWidth/ 2 + all->sprite->spriteScreenX;
// 	// printf("d-  %d  %d\n" , all->sprite->spriteWidth, all->sprite->spriteScreenX);
// 	// printf("0-  %d\n" , all->sprite->drawEndX);
// 	if (all->sprite->drawStartX< 0)
// 		all->sprite->drawStartX= 0;

// 	// printf("1-  %d\n" , all->sprite->drawEndX);
// 	all->sprite->drawEndX = all->sprite->spriteWidth/ 2 + all->sprite->spriteScreenX;
// 	if (all->sprite->drawEndX >= all->param_map->scr_w)
// 		all->sprite->drawEndX = all->param_map->scr_w - 1;
// 	printf("2-  %d\n" , all->sprite->drawEndX);
// }

// void	cs_part4(t_all *all, int stripe, int y)
// {
// 	t_img *texS;

// 	texS = all->texS;
// 	all->sprite->texX = (int)(256 * (stripe - (-all->sprite->spriteWidth/ 2 + all->sprite->spriteScreenX)) * texS->width/ all->sprite->spriteWidth) / 256;
// 	if (all->sprite->transformY > 0 && stripe > 0
// 		&& stripe < all->param_map->scr_w
// 		&& all->sprite->transformY < all->sprite->z_buffer[stripe])
// 	{
// 		y = all->sprite->drawStartY;
// 		while (y < all->sprite->drawEndY)
// 		{
// 			all->sprite->d = (y) * 256 - all->param_map->scr_h * 128 + all->sprite->spriteHeight* 128;
// 			all->sprite->texY = ((all->sprite->d * texS->height) / all->sprite->spriteHeight) / 256;
// 			all->sprite->color = *(unsigned int *)(texS->addr + (all->sprite->texY * texS->line_len + all->sprite->texX * (texS->bpp / 8)));
// 			if ((all->sprite->color & 0x00FFFFFF) != 0)
// 				my_mlx_pixel_put(all->win, stripe, y, all->sprite->color);
// 			y++;
// 		}
// 	}
// }

// void	cast_sprites(t_all *all)
// {
// 	int stripe;
// 	int y;
// 	int i;

// 	y = 0;
// 	i = 0;
// 	all->sprite->sp_dist = malloc(sizeof(double)* all->sprite->sp_num);
// 	all->sprite->sp_order = malloc((sizeof(int)) * all->sprite->sp_num);
// 	all->sprite->z_buffer = malloc((sizeof(double)) * all->param_map->scr_w);
// 	all->sprite->sp_cast = malloc(sizeof(t_sprite) * all->sprite->sp_num);
// 	all->sprite->sp = malloc(sizeof(t_sprite));
// 	coord_sprite(all);
// 	sp_1(all);
// 	// sort_sprites(&(all->sprite));
// 	i = 0;
// 	while(i < all->sprite->sp_num)
// 	{
// 		sp_wh(all);
// 		sp_wh_(all);
// 		stripe = all->sprite->drawStartX;
// 		printf("3- %d %d \n" ,stripe , all->sprite->drawStartX);
// 		printf("3.d- %d %d \n" ,stripe , all->sprite->drawEndX);
// 		while(stripe <= all->sprite->drawEndX)
// 		{
// 			printf("4- %d %d \n" , stripe , all->sprite->drawEndX);
// 			cs_part4(all, stripe, y);
// 			stripe++;
// 		}
// 		i++;
// 	}
// }

