// #include "cub.h"

// static void coord_sprite(t_all *all)
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

// void spriteeee(t_all *all)
// {
// 	int i = 0;
// 	all->sprite->sp_dist = malloc(sizeof(double)* all->sprite->sp_num);
// 	all->sprite->sp_order = malloc((sizeof(int)) * all->sprite->sp_num);
// 	all->sprite->z_buffer = malloc((sizeof(double)) * all->param_map->scr_w);
// 	all->sprite->sp_cast = malloc(sizeof(t_sprite) * all->sprite->sp_num);
// 	all->sprite->sp = malloc(sizeof(t_sprite));

// 	coord_sprite(all);
// 	sp_1(all);
//     for(i = 0; i < all->sprite->sp_num; i++)
//     {
//         all->sprite->invDet = 1.0 / (all->param_map->planeX * all->param_map->dirY - all->param_map->dirX * all->param_map->planeY); //required for correct matrix multiplication
//         all->sprite->spriteX= (double)all->sprite->sp[all->sprite->sp_order[i]].x  - all->param_map->posX;
//         all->sprite->spriteY = all->sprite->sp[all->sprite->sp_order[i]].y - all->param_map->posY;
//         all->sprite->transformX  = all->sprite->invDet 
// 			* (all->param_map->dirY * all->sprite->spriteX- all->param_map->dirX * all->sprite->spriteY);
//         all->sprite->transformY = all->sprite->invDet 
// 			* (-all->param_map->planeY * all->sprite->spriteX+ all->param_map->planeX * all->sprite->spriteY); //this is actually the depth inside the screen, that what Z is in 3D
// 		all->sprite->sp_dist[i] = all->sprite->transformY;
//         all->sprite->spriteScreenX = (int)((all->param_map->scr_w / 2) * (1 + all->sprite->transformX  / all->sprite->transformY));
//         all->sprite->spriteHeight = abs((int)(all->param_map->scr_h / (all->sprite->transformY))); //using 'all->sprite->transformY' instead of the real distance prevents fisheye
//         all->sprite->drawStartY = -all->sprite->spriteHeight / 2 + all->param_map->scr_h / 2;   
// 		if(all->sprite->drawStartY < 0)
//             all->sprite->drawStartY = 0;



// 		all->sprite->drawEndY = all->sprite->spriteHeight / 2 + all->param_map->scr_h / 2;
//         if(all->sprite->drawEndY >= all->param_map->scr_h)
//             all->sprite->drawEndY = all->param_map->scr_h - 1;
//         all->sprite->spriteWidth = abs((int)(all->param_map->scr_h / (all->sprite->transformY)));
//         all->sprite->drawStartX= -all->sprite->spriteWidth / 2 + all->sprite->spriteScreenX;
//         if(all->sprite->drawStartX< 0)
//             all->sprite->drawStartX= 0;
//         all->sprite->drawEndX = all->sprite->spriteWidth / 2 + all->sprite->spriteScreenX;
//         if(all->sprite->drawEndX >= all->param_map->scr_w)
//             all->sprite->drawEndX = all->param_map->scr_w - 1;



//         for(int stripe = all->sprite->drawStartX; stripe < all->sprite->drawEndX; stripe++)
//         {

// 			printf("3- %d %d \n" ,stripe , all->sprite->drawStartX);
// 			printf("3.d- %d %d \n" ,stripe , all->sprite->drawEndX);
//             int texX = (int)(256 * (stripe - (-all->sprite->spriteWidth / 2 + all->sprite->spriteScreenX)) * all->texS->width / all->sprite->spriteWidth) / 256;
// 			int color;
//             if(all->sprite->transformY > 0 && stripe > 0 && stripe < all->param_map->scr_w)
//                 for(int r = all->sprite->drawStartY; r < all->sprite->drawEndY; r++) //for every pixel of the crrrent stripe
//                 {
//                     int d = (r) * 256 - all->param_map->scr_h * 128 + all->sprite->spriteHeight * 128; //256 and 128 factors to avoid floats
//                     int texY = ((d * all->texS->height) / all->sprite->spriteHeight) / 256;
//                     color = *(unsigned int *)(all->texS->addr + texY * all->texS->line_len + texX * (all->texS->bpp / 8));
//                     if (color != 0)
//                         my_mlx_pixel_put(all->win, stripe, r, color);
//                 }
//         }
//     }
// }