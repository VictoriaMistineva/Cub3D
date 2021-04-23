#include "cub.h"

int key_press(int key, t_all *all)
{
	if(key = KEY_ESC)
	{
		exit(0); // доделать
	}

	if((move(key, all)) == 0)
	{
		//перезапись всех функций
	}
}





int		move(int key, t_all *all)
{
	double	movespeed;
	double	rotspeed;

	movespeed = 0.3;
	rotspeed = 0.3;
	if (key == KEY_W || key == KEY_S)
		key_w_or_key_s(all, movespeed, key);
	if (key == KEY_A|| key == KEY_D)
		key_a_or_key_d(all, movespeed, key);
	// if (key == KEY_LEFT || key == KEY_RIGHT)
	// 	//key_left_or_key_right;
	return (1);
}

void	key_w_or_key_s(t_all *all, double movespeed, int key)
{
	if (key == KEY_W)
	{
		if (all->map[(int)all->param_map->posY]
				[(int)(all->param_map->posX + all->param_map->dirX * movespeed)] == '0')
			all->param_map->posX += all->param_map->dirX * movespeed;
		if (all->map[(int)(all->param_map->posY + all->param_map->dirY
					* movespeed)][(int)all->param_map->posX] == '0')
			all->param_map->posY += all->param_map->dirY * movespeed;
	}
	if (key == KEY_S)
	{
		if (all->map[(int)all->param_map->posY]
				[(int)(all->param_map->posX - all->param_map->dirX * movespeed)] == '0')
			all->param_map->posX -= all->param_map->dirX * movespeed;
		if (all->map[(int)(all->param_map->posY - all->param_map->dirY
					* movespeed)][(int)all->param_map->posX] == '0')
			all->param_map->posY -= all->param_map->dirY * movespeed;
	}
}

void	key_a_or_key_d(t_all *all, double movespeed, int key)
{
	if (key == KEY_A)
	{
		if (all->map[(int)(all->param_map->posY)]
				[(int)(all->param_map->posX + all->param_map->planeX * movespeed)] == '0')
			all->param_map->posX += all->param_map->planeX * movespeed;
		if (all->map[(int)(all->param_map->posY + all->param_map->planeY
					* movespeed)][(int)(all->param_map->posX)] == '0')
			all->param_map->posY += all->param_map->planeY * movespeed;
	}
	if (key == KEY_D)
	{
		if (all->map[(int)(all->param_map->posY)]
				[(int)(all->param_map->posX - all->param_map->planeX * movespeed)] == '0')
			all->param_map->posX -= all->param_map->planeX * movespeed;
		if (all->map[(int)(all->param_map->posY - all->param_map->planeY
					* movespeed)][(int)(all->param_map->posX)] == '0')
			all->param_map->posY -= all->param_map->planeY * movespeed;
	}
}

// void	key_left_or_key_right(
// 		int key, t_all *all, double rotspeed)
// {
// 	if (key == KEY_LEFT)
// 	{
// 		algo_data->oldDirX = pl->dir.x;
// 		pl->dir.x = pl->dir.x * cos(-rotspeed)
// 			- pl->dir.y * sin(-rotspeed);
// 		pl->dir.y = algo_data.old_dir_x * sin(-rotspeed)
// 			+ pl->dir.y * cos(-rotspeed);
// 		algo_data.old_plane_x = pl->plane.x;
// 		pl->plane.x = pl->plane.x * cos(-rotspeed)
// 			- pl->plane.y * sin(-rotspeed);
// 		pl->plane.y = algo_data.old_plane_x
// 			* sin(-rotspeed) + pl->plane.y * cos(-rotspeed);
// 	}
// 	if (key == KEY_RIGHT)
// 	{
// 		pl->dir.x = pl->dir.x * cos(rotspeed) - pl->dir.y * sin(rotspeed);
// 		pl->dir.y = algo_data.old_dir_x
// 			* sin(rotspeed) + pl->dir.y * cos(rotspeed);
// 		algo_data.old_plane_x = pl->plane.x;
// 		pl->plane.x = pl->plane.x * cos(rotspeed) - pl->plane.y * sin(rotspeed);
// 		pl->plane.y = algo_data.old_plane_x
// 			* sin(rotspeed) + pl->plane.y * cos(rotspeed);
// 	}
// }