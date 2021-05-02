#include "../cub.h"
void	check_sp(t_all *all)
{
	int	k;
	int	j;

	all->sprite->sp_num = 0;
	k = 0;
	while (all->map[k])
	{
		j = 0;
		while (all->map[k][j])
		{
			if (all->map[k][j] == '2')
				all->sprite->sp_num++;
			j++;
		}
		k++;
	}
}

void	coord_sprite(t_all *all)
{
	int	i;
	int	k;
	int	j;

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
				i++;
			}
			j++;
		}
		k++;
	}
}

void	sotirovka_sprite(t_sprite *sprite)
{
	int		i;
	int		j;
	double	temp;

	i = 0;
	while (i < sprite->sp_num - 1)
	{
		j = sprite->sp_num - 1;
		while (j > i)
		{
			if (sprite->sp_dist[j] > sprite->sp_dist[j - 1])
			{
				temp = sprite->sp_dist[j - 1];
				sprite->sp_dist[j - 1] = sprite->sp_dist[j];
				sprite->sp_dist[j] = temp;
				temp = sprite->sp_order[j - 1];
				sprite->sp_order[j - 1] = sprite->sp_order[j];
				sprite->sp_order[j] = temp;
			}
			j--;
		}
		i++;
	}
}

void	cast_sprites(t_all *all)
{
	int	i;

	i = 0;
	check_sp(all);
	coord_sprite(all);
	sp_1(all);
	i = 0;
	sotirovka_sprite(all->sprite);
	while (i < all->sprite->sp_num)
	{
		sp_drawstart(all, i);
		sp_drawend(all);
		sp_color(all);
		i++;
	}
}
