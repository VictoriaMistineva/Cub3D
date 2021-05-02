#include "../cub.h"

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
