#include "../cub.h"

void	sp_1(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->sprite->sp_num)
	{
		all->sprite->sp_order[i] = i;
		all->sprite->sp_dist[i] = sqrt(pow(all->pm->posX
					- all->sprite->sp[i].x, 2)
				+ pow(all->pm->posY - all->sprite->sp[i].y, 2));
		i++;
	}
}

void	sp_drawstart(t_all *all, int i)
{
	all->sprite->invDet = 1.0 / (all->pm->plX * all->pm->dirY
			- all->pm->dirX * all->pm->plY);
	all->sprite->spriteX = (double)all->sprite->sp[all->sprite->sp_order[i]].x
		- all->pm->posX;
	all->sprite->spriteY = all->sprite->sp[all->sprite->sp_order[i]].y
		- all->pm->posY;
	all->sprite->transformX = all->sprite->invDet
		* (all->pm->dirY * all->sprite->spriteX - all->pm->dirX
			* all->sprite->spriteY);
	all->sprite->trfY = all->sprite->invDet
		* (-all->pm->plY * all->sprite->spriteX
			+ all->pm->plX * all->sprite->spriteY);
	all->sprite->sp_dist[i] = all->sprite->trfY;
	all->sprite->sp_ScrX = (int)((all->pm->scr_w / 2)
			* (1 + all->sprite->transformX / all->sprite->trfY));
	all->sprite->sp_H = abs((int)(all->pm->scr_h
				/ (all->sprite->trfY)));
	all->sprite->drawStartY = -all->sprite->sp_H / 2
		+ all->pm->scr_h / 2;
	if (all->sprite->drawStartY < 0)
		all->sprite->drawStartY = 0;
}

void	sp_drawend(t_all *all)
{
	all->sprite->drawEndY = all->sprite->sp_H
		/ 2 + all->pm->scr_h / 2;
	if (all->sprite->drawEndY >= all->pm->scr_h)
		all->sprite->drawEndY = all->pm->scr_h - 1;
	all->sprite->sp_W = abs((int)(all->pm->scr_h
				/ (all->sprite->trfY)));
	all->sprite->drawStartX = -all->sprite->sp_W
		/ 2 + all->sprite->sp_ScrX;
	if (all->sprite->drawStartX < 0)
		all->sprite->drawStartX = 0;
	all->sprite->drawEndX = all->sprite->sp_W
		/ 2 + all->sprite->sp_ScrX;
	if (all->sprite->drawEndX >= all->pm->scr_w)
		all->sprite->drawEndX = all->pm->scr_w - 1;
}

void	sp_color_2(t_all *all, int y, int stp)
{
	all->sprite->d = (y) * 256 - all->pm->scr_h * 128
		+ all->sprite->sp_H * 128;
	all->sprite->texY = ((all->sprite->d * all->texS->height)
			/ all->sprite->sp_H) / 256;
	all->sprite->color = *(unsigned int *)(all->texS->addr
			+ all->sprite->texY * all->texS->line_len
			+ all->sprite->texX * (all->texS->bpp / 8));
	if ((all->sprite->color & 0x00FFFFFF) != 0)
		my_mlx_pixel_put(all->win, stp, y, all->sprite->color);
}

void	sp_color(t_all *all)
{
	t_img	*texS;
	int		stp;
	int		y;

	texS = all->texS;
	stp = all->sprite->drawStartX;
	while (++stp < all->sprite->drawEndX)
	{
		all->sprite->texX = (int)(256 * (stp - (-all->sprite->sp_W
						/ 2 + all->sprite->sp_ScrX)) * texS->width
				/ all->sprite->sp_W) / 256;
		if (all->sprite->trfY > 0 && stp > 0 && stp < all->pm->scr_w
			&& all->sprite->trfY < all->sprite->z_buf[stp])
		{
			y = all->sprite->drawStartY;
			while (++y < all->sprite->drawEndY)
				sp_color_2(all, y, stp);
		}
	}
}
