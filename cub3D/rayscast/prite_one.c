#include "../cub.h"

// int		sprite(t_sp_cast *sp_cast, int start, int stop)
// {
// 	int		k;
// 	int		i;
// 	int		j;
// 	t_sp_cast tmp;

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
// void sotirovka_sprite(t_sprite *sprite)
// {
// 	int i;
// 	i = 0;
// 	// if(sprite->sp_cast) //утички
// 	sprite->sp_cast = malloc(sizeof(t_sprite) * sprite->sp_num);
// 	while(i < sprite->sp_num)
// 	{
// 		sprite->sp_cast[i].dist = sprite->sp_dist[i];
// 		sprite->sp_cast[i].order = sprite->sp_order[i];
// 		i++;
// 	}
// 	quick_sort(sprite->sp_cast, 0, sprite->sp_num - 1);
// 	i = 0;
// 	while(i < sprite->sp_num) // восстанавливаем в обратном порядке, чтобы перейти от самого дальнего к ближайшему
// 	{
// 		sprite->sp_dist[i] = sprite->sp_cast[sprite->sp_num - i - 1].order;
// 		sprite->sp_order[i] = sprite->sp_cast[sprite->sp_num - i - 1].dist;
// 		i++;
// 	}
	
// }
// void	sort_order(t_pair *orders, int amount)
// {
// 	t_pair	tmp;

// 	for (int i = 0; i < amount; i++)
// 	{
// 		for (int j = 0; j < amount - 1; j++)
// 		{
// 			if (orders[j].first > orders[j + 1].first)
// 			{
// 				tmp.first = orders[j].first;
// 				tmp.second = orders[j].second;
// 				orders[j].first = orders[j + 1].first;
// 				orders[j].second = orders[j + 1].second;
// 				orders[j + 1].first = tmp.first;
// 				orders[j + 1].second = tmp.second;
// 			}
// 		}
// 	}
// }

// void sprite_sort(int *order, double *dist, int amount)
// {
// 	t_pair	*sprite;
//     int i;

//     i = 0;
// 	sprite = (t_pair*)malloc(sizeof(t_pair) * amount);
// 	while (i < amount)
// 	{
// 		sprite[i].first = dist[i];
// 		sprite[i].second = order[i];
//         i++;
// 	}
// 	sort_order(sprite, amount);
// 	for (int i = 0; i < amount; i++)
// 	{
// 		dist[i] = sprite[amount - i - 1].first;
// 		order[i] = sprite[amount - i - 1].second;
// 	}
// 	free(sprite);

// }