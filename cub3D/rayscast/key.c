#include "../cub.h"

int	key_esc(int key, t_all *all)
{
	exit(0);
}

void	key_w_s(t_all *all, double msd, int key)
{
	if (key == KEY_W)
	{
		if (all->map[(int)all->pm->posY]
			[(int)(all->pm->posX + all->pm->dirX * msd)] == '0')
			all->pm->posX += all->pm->dirX * msd;
		if (all->map[(int)(all->pm->posY + all->pm->dirY
				* msd)][(int)all->pm->posX] == '0')
			all->pm->posY += all->pm->dirY * msd;
	}
	if (key == KEY_S)
	{
		if (all->map[(int)all->pm->posY]
			[(int)(all->pm->posX - all->pm->dirX * msd)] == '0')
			all->pm->posX -= all->pm->dirX * msd;
		if (all->map[(int)(all->pm->posY - all->pm->dirY
				* msd)][(int)all->pm->posX] == '0')
			all->pm->posY -= all->pm->dirY * msd;
	}
}

void	key_a_d(t_all *all, double msd, int key)
{
	if (key == KEY_A)
	{
		if (all->map[(int)(all->pm->posY)]
				[(int)(all->pm->posX
				 - all->pm->plX * msd)] == '0')
			all->pm->posX -= all->pm->plX * msd;
		if (all->map[(int)(all->pm->posY
				+ all->pm->plY
				* msd)][(int)(all->pm->posX)] == '0')
			all->pm->posY -= all->pm->plY * msd;
	}
	if (key == KEY_D)
	{
		if (all->map[(int)(all->pm->posY)]
				[(int)(all->pm->posX + all->pm->plX * msd)] == '0')
			all->pm->posX += all->pm->plX * msd;
		if (all->map[(int)(all->pm->posY - all->pm->plY
				* msd)][(int)(all->pm->posX)] == '0')
			all->pm->posY += all->pm->plY * msd;
	}
}

void	key_left_right(int key, t_all *all, double rs)
{
	double	oldDirX;

	if (key == KEY_LEFT)
	{
		oldDirX = all->pm->dirX;
		all->pm->dirX = all->pm->dirX * cos(-rs) - all->pm->dirY * sin(-rs);
		all->pm->dirY = oldDirX * sin(-rs) + all->pm->dirY * cos(-rs);
		all->gl->old_plX = all->pm->plX;
		all->pm->plX = all->pm->plX * cos(-rs) - all->pm->plY * sin(-rs);
		all->pm->plY = all->gl->old_plX * sin(-rs) + all->pm->plY * cos(-rs);
	}
	if (key == KEY_RIGHT)
	{
		oldDirX = all->pm->dirX;
		all->pm->dirX = all->pm->dirX * cos(rs) - all->pm->dirY * sin(rs);
		all->pm->dirY = oldDirX * sin(rs) + all->pm->dirY * cos(rs);
		all->gl->old_plX = all->pm->plX;
		all->pm->plX = all->pm->plX * cos(rs) - all->pm->plY * sin(rs);
		all->pm->plY = all->gl->old_plX * sin(rs) + all->pm->plY * cos(rs);
	}
}

int	move(int key, t_all *all)
{
	double	msd;
	double	rs;

	msd = 0.3;
	rs = 0.1;
	if (key == KEY_ESC)
		key_esc(key, all);
	if (key == KEY_W || key == KEY_S)
		key_w_s(all, msd, key);
	if (key == KEY_A || key == KEY_D)
		key_a_d(all, msd, key);
	if (key == KEY_LEFT || key == KEY_RIGHT)
		key_left_right(key, all, rs);
	return (1);
}
