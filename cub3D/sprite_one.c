#include "cub.h"

// int		sprite(t_sp_cast *arr, int start, int stop)
// {
// 	int		pivot;
// 	int		i;
// 	int		j;
// 	t_sp_cast bucket;

// 	pivot = start;
// 	i = start + 1;
// 	j = start + 1;
// 	while (j < stop + 1)
// 	{
// 		if (arr[j].dist <= arr[pivot].dist)
// 		{
// 			bucket = arr[j];
// 			arr[j] = arr[i];
// 			arr[i] = bucket;
// 			i++;
// 		}
// 		j++;
// 	}
// 	bucket = arr[pivot];
// 	arr[pivot] = arr[i - 1];
// 	arr[i - 1] = bucket;
// 	pivot = i - 1;
// 	return (pivot);
// }

// void	quick_sort(t_sp_cast *sp_cast, int start, int stop)
// {
// 	int pivot_index;

// 	if (start < stop)
// 	{
// 		pivot_index = partition(arr, start, stop);
// 		quick_sort(arr, start, pivot_index - 1);
// 		quick_sort(arr, pivot_index + 1, stop);
// 	}
// }
// void sotirovka_sprite(t_sprite *sprite)
// {
// 	int i;
// 	i = 0;

// 	// if(sprite->sp_cast)
// 	sprite->sp_cast = (t_sprite *)malloc(sizeof(t_sprite) * sprite->sp_num);
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