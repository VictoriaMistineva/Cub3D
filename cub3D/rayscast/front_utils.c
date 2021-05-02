#include "../cub.h"

void	cr_part1(t_all *all, int x)
{
	double	camere_x;

	all->gl->camera_x = 2.0 * x / (double)all->pm->scr_w - 1;
	all->gl->rayDirX = all->pm->dirX
		+ all->pm->plX * all->gl->camera_x;
	all->gl->rayDirY = all->pm->dirY
		+ all->pm->plY * all->gl->camera_x;
	all->gl->mapX = (int)all->pm->posX;
	all->gl->mapY = (int)all->pm->posY;
	all->gl->deltaDistX = fabs(1 / all->gl->rayDirX);
	all->gl->deltaDistY = fabs(1 / all->gl->rayDirY);
	all->gl->hit = 0;
}

void	cr_X(t_all *all)
{
	if (all->gl->rayDirX < 0)
	{
		all->gl->stepX = -1;
		all->gl->sideDistX
			= (all->pm->posX - all->gl->mapX)
			* all->gl->deltaDistX;
	}
	else
	{
		all->gl->stepX = 1;
		all->gl->sideDistX = (all->gl->mapX
				+ 1.0 - all->pm->posX) * all->gl->deltaDistX;
	}
}

void	cr_Y(t_all *all)
{
	if (all->gl->rayDirY < 0)
	{
		all->gl->stepY = -1;
		all->gl->sideDistY
			= (all->pm->posY - all->gl->mapY)
			* all->gl->deltaDistY;
	}
	else
	{
		all->gl->stepY = 1;
		all->gl->sideDistY = (all->gl->mapY
				+ 1.0 - all->pm->posY) * all->gl->deltaDistY;
	}
	all->gl->hit = 0;
}

void	cr_part3(t_all *all, int x)
{
	if (all->gl->sideDistX < all->gl->sideDistY)
	{
		all->gl->sideDistX += all->gl->deltaDistX;
		all->gl->mapX += all->gl->stepX;
		all->gl->side = 0;
	}
	else
	{
		all->gl->sideDistY += all->gl->deltaDistY;
		all->gl->mapY += all->gl->stepY;
		all->gl->side = 1;
	}
	if (all->map[all->gl->mapY][all->gl->mapX] == '1')
		all->gl->hit = 1;
	if (all->gl->side == 0)
		all->gl->pwd = (all->gl->mapX - all->pm->posX
				+ (1 - all->gl->stepX) / 2) / all->gl->rayDirX;
	else
		all->gl->pwd = (all->gl->mapY - all->pm->posY
				+ (1 - all->gl->stepY) / 2) / all->gl->rayDirY;
	all->sprite->z_buf[x] = all->gl->pwd;
}

void	cr_part4(t_all *all)
{
	all->gl->line_h = (int)(all->pm->scr_h
			/ all->gl->pwd);
	all->gl->draw_start = -1 * (all->gl->line_h)
		/ 2 + all->pm->scr_h / 2;
	if (all->gl->draw_start < 0)
		all->gl->draw_start = 0;
	all->gl->draw_end = all->gl->line_h
		/ 2 + all->pm->scr_h / 2;
	if (all->gl->draw_end >= all->pm->scr_h)
		all->gl->draw_end = all->pm->scr_h - 1;
}
