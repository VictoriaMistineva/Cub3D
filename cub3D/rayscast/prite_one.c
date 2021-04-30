#include "../cub.h"

// int		sprite(t_sp_cast *sp_cast, int start, int stop)
// {
// 	t_sp_cast tmp;
// 	int		k;
// 	int		i;
// 	int		j;
	
// 	k = start;
// 	i = start + 1;
// 	j = start + 1;
// 	while (j < stop + 1)
// 	{
// 		if (sp_cast[j].dist <= sp_cast[k].dist)
// 		{
// 			tmp = sp_cast[j];
// 			sp_cast[j] = sp_cast[i];
// 			sp_cast[i] = tmp;
// 			i++;
// 		}
// 		j++;
// 	}
// 	tmp = sp_cast[k];
// 	sp_cast[k] = sp_cast[i - 1];
// 	sp_cast[i - 1] = tmp;
// 	k = i - 1;
// 	return (k);
// }

// void	quick_sort(t_sp_cast *sp_cast, int start, int stop)
// {
// 	int index;

// 	if (start < stop)
// 	{
// 		index = sprite(sp_cast, start, stop);
// 		quick_sort(sp_cast, start, index - 1);
// 		quick_sort(sp_cast, index + 1, stop);
// 	}
// }
void sotirovka_sprite(t_sprite *sprite)
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

