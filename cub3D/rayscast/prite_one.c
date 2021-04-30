#include "../cub.h"

int		sprite(t_sp_cast *sp_cast, int start, int stop)
{
	int		k;
	int		i;
	int		j;
	t_sp_cast bu;

	k = start;
	i = start + 1;
	j = start + 1;
	while (j < stop + 1)
	{
		if (sp_cast[j].dist <= sp_cast[k].dist)
		{
			bu = sp_cast[j];
			sp_cast[j] = sp_cast[i];
			sp_cast[i] = bu;
			i++;
		}
		j++;
	}
	bu = sp_cast[k];
	sp_cast[k] =sp_cast[i - 1];
	sp_cast[i - 1] = bu;
	k = i - 1;
	return (k);
}

void	quick_sort(t_sp_cast *sp_cast, int start, int stop)
{
	int index;

	if (start < stop)
	{
		index = sprite(sp_cast, start, stop);
		quick_sort(sp_cast, start, index - 1);
		quick_sort(sp_cast, index + 1, stop);
	}
}
void sotirovka_sprite(t_sprite *sprite)
{
	int i;
	i = 0;

	// if(sprite->sp_cast) //утички
	// sprite->sp_cast = (t_sprite *)malloc(sizeof(t_sprite) * sprite->sp_num);
	while(i < sprite->sp_num)
	{
		sprite->sp_cast[i].dist = sprite->sp_dist[i];
		sprite->sp_cast[i].order = sprite->sp_order[i];
		i++;
	}
	quick_sort(sprite->sp_cast, 0, sprite->sp_num - 1);
	i = 0;
	while(i < sprite->sp_num) // восстанавливаем в обратном порядке, чтобы перейти от самого дальнего к ближайшему
	{
		sprite->sp_dist[i] = sprite->sp_cast[sprite->sp_num - i - 1].order;
		sprite->sp_order[i] = sprite->sp_cast[sprite->sp_num - i - 1].dist;
		i++;
	}
	
}