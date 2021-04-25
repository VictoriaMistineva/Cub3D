#include "cub.h"

// int key_press(int key, t_all *all)
// {
// 	if(key = KEY_ESC)
// 	{
// 		exit(0); // доделать
// 	}

// 	if((move(key, all)) == 0)
// 	{
// 		//перезапись всех функций
// 	}
// }






void	key_w_or_key_s(t_all *all, double movespeed, int key)
{
	if (key == KEY_W)
	{
		// printf("%c\n", all->map[(int)all->param_map->posY][(int)(all->param_map->posX + all->param_map->dirX * movespeed)]);
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
				[(int)(all->param_map->posX - all->param_map->planeX * movespeed)] == '0')
			all->param_map->posX -= all->param_map->planeX * movespeed;
		if (all->map[(int)(all->param_map->posY + all->param_map->planeY
					* movespeed)][(int)(all->param_map->posX)] == '0')
			all->param_map->posY += all->param_map->planeY * movespeed;
	}
	if (key == KEY_D)
	{
		if (all->map[(int)(all->param_map->posY)]
				[(int)(all->param_map->posX + all->param_map->planeX * movespeed)] == '0')
			all->param_map->posX += all->param_map->planeX * movespeed;
		if (all->map[(int)(all->param_map->posY - all->param_map->planeY
					* movespeed)][(int)(all->param_map->posX)] == '0')
			all->param_map->posY -= all->param_map->planeY * movespeed;
	}
}
void	key_left_or_key_right(
		int key, t_all *all, double rotspeed)
{
	if (key == KEY_RIGHT)
	{
		all->param_map->oldDirX = all->param_map->dirX;
		all->param_map->dirX = all->param_map->dirX * cos(-rotspeed)
			- all->param_map->dirY * sin(-rotspeed);
		all->param_map->dirY = all->param_map->oldDirX * sin(-rotspeed)
			+ all->param_map->dirY * cos(-rotspeed);
		all->algo_data->old_plane_x = all->param_map->planeX;
		all->param_map->planeX = all->param_map->planeX * cos(-rotspeed)
			- all->param_map->planeY * sin(-rotspeed);
		all->param_map->planeX = all->algo_data->old_plane_x
			* sin(-rotspeed) + all->param_map->planeY * cos(-rotspeed);
	}
	if (key == KEY_LEFT)
	{
		all->param_map->oldDirX = all->param_map->dirX;
		all->param_map->dirX = all->param_map->dirX * cos(rotspeed) - all->param_map->dirY * sin(rotspeed);
		all->param_map->dirY = all->param_map->oldDirX
			* sin(rotspeed) + all->param_map->dirY * cos(rotspeed);
		all->algo_data->old_plane_x = all->param_map->planeX;
		all->param_map->planeX = all->param_map->planeX * cos(rotspeed) - all->param_map->planeY * sin(rotspeed);
		all->param_map->planeY = all->algo_data->old_plane_x
			* sin(rotspeed) + all->param_map->planeY * cos(rotspeed);
	}
}

int		move(int key, t_all *all)
{
	double	movespeed;
	double	rotspeed;

	movespeed = 2.0;
	rotspeed = 0.09;
	printf("\nold posX = %f\nold posY = %f\n", all->param_map->posX, all->param_map->posY);
	if (key == KEY_W || key == KEY_S)
		key_w_or_key_s(all, movespeed, key);
	if (key == KEY_A|| key == KEY_D)
		key_a_or_key_d(all, movespeed, key);
	printf("New posX = %f\nNew posY = %f\n", all->param_map->posX, all->param_map->posY);
	if (key == KEY_LEFT || key == KEY_RIGHT)
		key_left_or_key_right(key, all, rotspeed);
	return (1);
}
