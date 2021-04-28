#include "cub.h"

static void coord_sprite(t_all *all)
{
	int i;
	int k;
	int j;

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
					printf("map %f\n",all->sprite->sp[i].x);
					i++;
			}
			j++;
		}
		k++;
	}
}

void spriteeee(t_all *all)
{
	int i = 0;
    double spriteX;
    double spriteY;

	all->sprite->sp_dist = malloc(sizeof(double)* all->sprite->sp_num);
	all->sprite->sp_order = malloc((sizeof(int)) * all->sprite->sp_num);
	all->sprite->z_buffer = malloc((sizeof(double)) * all->param_map->scr_w);
	all->sprite->sp_cast = malloc(sizeof(t_sprite) * all->sprite->sp_num);
	all->sprite->sp = malloc(sizeof(t_sprite));

	coord_sprite(all);
    for(; i < 1; i++)
    {
        //translate sprite position to relative to camera
        spriteX = all->sprite->sp->x - all->param_map->posX;
        spriteY = all->sprite->sp->y - all->param_map->posY;
    }
    // sort_tex(data, /*sprite,*/ i);
    //     // printf("%f %f\n", sprite[i].y, sprite[i].x);
    for(i = 0; i < 1; i++)
    {
        double invDet = 1.0 / (all->param_map->planeX * all->param_map->dirY - all->param_map->dirX * all->param_map->planeY); //required for correct matrix multiplication
        spriteX = (double)all->sprite->sp->x - all->param_map->posX;
        spriteY = all->sprite->sp->y - all->param_map->posY;
        double transformX = invDet * (all->param_map->dirY * spriteX - all->param_map->dirX * spriteY);
        double transformY = invDet * (-all->param_map->planeY * spriteX + all->param_map->planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D
        *all->sprite->sp_dist = transformY;
        // double invDet = 1.0 / (data->planeX * data->dirY - data->dirX * data->planeY); //required for correct matrix multiplication
        // double transformX = invDet * (data->dirY * spriteX - data->dirX * spriteY);
        // double transformY = invDet * (-data->planeY * spriteX + data->planeX * spriteY);
        int spriteScreenX = (int)((all->param_map->scr_w / 2) * (1 + transformX / transformY));
        //calculate height of the sprite on screen
        int spriteHeight = abs((int)(all->param_map->scr_h / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
        //calculate lowest and highest pixel to fill in current stripe
        int drawStartY = -spriteHeight / 2 + all->param_map->scr_h / 2;
        if(drawStartY < 0)
            drawStartY = 0;
        int drawEndY = spriteHeight / 2 + all->param_map->scr_h / 2;
        if(drawEndY >= all->param_map->scr_h)
            drawEndY = all->param_map->scr_h - 1;
        // printf("%f %f\n", sprite[i].y, sprite[i].x);
        //calculate width of the sprite
        int spriteWidth = abs((int)(all->param_map->scr_h / (transformY)));
        int drawStartX = -spriteWidth / 2 + spriteScreenX;
        if(drawStartX < 0)
            drawStartX = 0;
        int drawEndX = spriteWidth / 2 + spriteScreenX;
        if(drawEndX >= all->param_map->scr_w)
            drawEndX = all->param_map->scr_w - 1;
        //loop through every vertical stripe of the sprite on screen
        for(int sprX = drawStartX; sprX < drawEndX; sprX++)
        {
            int texX = (int)(256 * (sprX - (-spriteWidth / 2 + spriteScreenX)) * all->texS->width / spriteWidth) / 256;
            //the conditions in the if are:
            //1) it's in front of camera plane so you don't see things behind you
            //2) it's on the screen (left)
            //3) it's on the screen (right)
            //4) ZBuffer, with perpendicular distance
            //double ZBuffer[all->param_map->scr_w];
			int color;
            // if(transformY > 0 && sprX > 0 && sprX < all->param_map->scr_w && data->zBuffer[sprX] > transformY)
            if(transformY > 0 && sprX > 0 && sprX < all->param_map->scr_w)
                for(int r = drawStartY; r < drawEndY; r++) //for every pixel of the crrrent sprX
                {
                    int d = (r) * 256 - all->param_map->scr_h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
                    int texY = ((d * all->texS->height) / spriteHeight) / 256;
                    color = *(unsigned int *)(all->texS->addr + texY * all->texS->line_len + texX * (all->texS->bpp / 8));
                    if (color != 0)
                        my_mlx_pixel_put(all->win, sprX, r, color);
                    // color = texture[sprite[spriteOrder[i]].texture][all->texS->width * texY + texX]; //get current color from the texture
                    // if((color & 0x00FFFFFF) != 0) buffer[y][sprX] = color; //paint pixel if it isn't black, black is the invisible color
                }
        }
    }
}