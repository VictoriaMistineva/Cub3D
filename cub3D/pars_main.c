#include "cub.h"
#include "Libft/includes/libft.h" 
#include <fcntl.h>
#include <stdio.h>

// int map_carta(t_all *all)
// {
//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
//     img.img = mlx_new_image(mlx, 1920, 1080);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//                                  &img.endian);
// 	all.win = &img;
//     point.y = 0;
//     while (all.map[point.y] != NULL)
//     {
// 		point.x = 0;
// 		while(all.map[point.y][point.x] != '\0')
// 		{
// 			if (all.map[point.y][point.x] == '1')
//         		draw_scale(&all, point);
//         	point.x++;
// 		}
// 	 	point.y++;
// 	}
//     mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//     //mlx_loop(mlx);
// }

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	draw_scale(t_all *all, t_point point)
{
	int i;
	int j;
	int start_x;
	int start_y;

	start_x = point.x * SCALE;
	start_y = point.y * SCALE;

	i = 1;
	point.y = start_y;
	while (i++ <= SCALE)
	{
		j = 1;
		point.x = start_x;
		while(j++ <= SCALE)
		{
			my_mlx_pixel_put(all->win, point.x, point.y, 0x00FFFF1);
			point.x++;
		}
		point.y++;
	}
}

void	init_stuct(t_all *all)
{
	all->param_map->scr_h = -1;
	all->param_map->scr_w = -1;
	all->param_map->floor_r = -1;
	all->param_map->floor_g = -1;
	all->param_map->floor_b = -1;
	all->param_map->ceil_r = -1;
	all->param_map->ceil_g = -1;
	all->param_map->ceil_b = -1;
	all->param_map->color_ceil= 0;
	all->param_map->color_floor= 0;
	all->param_map->north= NULL;
	all->param_map->south= NULL;
	all->param_map->east= NULL;
	all->param_map->west= NULL;
	all->param_map->sprite= NULL;
	all->param_map->posX = 0;
	all->param_map->posY = 0;
	all->param_map->posX = 0;
	all->param_map->dirY = 0;
	all->param_map->dirX = 0;
	all->param_map->planeY = 0;
	all->param_map->planeX = 0;

}

int	main(int argc, char **argv)
{
	t_all		all;
	void		*mlx;
    void		*mlx_win;
    t_win		img;
	t_point		point;
	t_param_map *param_map;

	all.win = malloc(sizeof(t_win));
	all.param_map = malloc(sizeof(t_param_map));
	param_map = all.param_map;
	init_stuct(&all);
	int      fd = open(argv[1], O_RDONLY);
	char	  *line = NULL;
	char *bigLine = NULL;

	while (get_next_line(fd, &line) > 0) 
	{
		if (type_flags_check(&all) > 0)
			type_identifier(line, &all);
		else
		{	
			bigLine = ft_strjoin(bigLine, line);
			free(line);
			line = bigLine; 
			bigLine = ft_strjoin(bigLine, "\n");
		}
		free(line);
	}
	bigLine = ft_strjoin(bigLine, line);
	all.map = ft_split(bigLine, '\n');//проверка валидности карты
	check_map(&all);
	check_player(&all);
	// printf("%s\n", map[0]);
	free(line);
	
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, param_map->scr_h, param_map->scr_w, "Hello world!");
    img.img = mlx_new_image(mlx, param_map->scr_h, param_map->scr_w);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
	//функция по 3д
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    //mlx_loop(mlx);
	// map_carta(&all);
}
