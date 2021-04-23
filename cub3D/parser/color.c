#include "cub.h"

int	create_rgb(int r, int g, int b)
{
	int t;

	t = 0;
	return(t << 24 | r << 16 | g << 8 | b);
}
void	validate_color(int color)
{
	if (color < 0 || color > 255)
		printf_exit("Error\nНевалидный цвет потолка или пола");
}


