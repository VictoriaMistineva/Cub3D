/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:55:42 by rvena             #+#    #+#             */
/*   Updated: 2021/04/27 01:42:59 by ycordell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub.h"

// void draw(t_all *all)
// {
// 	int x;
// 	char **tmp_map;

// 	tmp_map = all->map;
// 	x = 0;
// 	while (x < all->param_map->scr_w)
// 	{
// 		double cameraX = 2 * x / (double)all->param_map->scr_w - 1; //x-coordinate in camera space
//       	double rayDirX = all->param_map->dirX + all->param_map->planeX * cameraX;
//       	double rayDirY = all->param_map->dirY + all->param_map->planeY * cameraX;
// 		int mapX = (int)all->param_map->posX;
// 		int mapY = (int)all->param_map->posY;
		
// 		double sideDistX;
//       	double sideDistY;
// 		double deltaDistX = fabs(1 / rayDirX);
//       	double deltaDistY = fabs(1 / rayDirY);
//       	double perpWallDist;
// 		int stepX;
//       	int stepY;
		
// 		int hit = 0;
// 		int side;
// 		if(rayDirX < 0)
//       	{
//         stepX = -1;
//         sideDistX = (all->param_map->posX - mapX) * deltaDistX;
//       	}
//       	else
//       	{
//        		stepX = 1;
//         	sideDistX = (mapX + 1.0 - all->param_map->posX) * deltaDistX;
//       	}
//       	if(rayDirY < 0)
//       	{
//         	stepY = -1;
//         	sideDistY = (all->param_map->posY - mapY) * deltaDistY;
//       	}
//       	else
//       	{
//        		stepY = 1;
//     		sideDistY = (mapY + 1.0 - all->param_map->posY) * deltaDistY;
//       	}
// 		while (hit == 0)
//       	{
//         //jump to next map square, OR in x-direction, OR in y-direction
//         	if(sideDistX < sideDistY)
//         	{
//         	  sideDistX += deltaDistX;
//           	mapX += stepX;
//           	side = 0;
//        		}
//         	else
//         	{
//           		sideDistY += deltaDistY;
//           		mapY += stepY;
//           		side = 1;
//         	}
//         //Check if ray has hit a wall
//         	if(tmp_map[mapY][mapX] > '0') hit = 1;
//       	}
// 	  	if(side == 0) perpWallDist = (mapX - all->param_map->posX + (1 - stepX) / 2) / rayDirX;
//       	else          perpWallDist = (mapY - all->param_map->posY + (1 - stepY) / 2) / rayDirY;

//       	//Calculate height of line to draw on screen
//       	int lineHeight = (int)(all->param_map->scr_h / perpWallDist);

//       //calculate lowest and highest pixel to fill in current stripe
//       	int drawStart = -lineHeight / 2 + all->param_map->scr_h / 2;
//       	if(drawStart < 0)drawStart = 0;
//       	int drawEnd = lineHeight / 2 + all->param_map->scr_h / 2;
//       	if(drawEnd >= all->param_map->scr_h)drawEnd = all->param_map->scr_h - 1;
	
// 		for (int y = 0; y < all->param_map->scr_h; y++)
// 		{
// 			if (y < drawStart)
// 				my_mlx_pixel_put(all->win, x, y, 0x000000);
// 			else if (y >= drawStart && y <= drawEnd)
// 				my_mlx_pixel_put(all->win, x, y, 0xFF0000);
// 			else 
// 				my_mlx_pixel_put(all->win, x, y, 0x000000);
// 		}
// 		x++;
// 	}
// }