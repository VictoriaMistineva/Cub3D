#include "cub.h"
#include "Libft/includes/libft.h" 
#include <fcntl.h>
#include <stdio.h>

// typedef struct  s_data {
//     void        *img;
//     char        *addr;
//     int         bits_per_pixel;
//     int         line_length;
//     int         endian;
// }               t_data;

// void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//     char    *dst;

//     dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//     *(unsigned int*)dst = color;
// }

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
	all->param_map->dirY = 0;
	all->param_map->dirX = 0;
	all->param_map->planeY = 0;
	all->param_map->planeX = 0;
	// all->sprite->sp_num = 0;

}

int	render_next_frame(t_all *all)
{
	mlx_clear_window(all->mlx, all->win->mlx);
	cast_rays(all);
	// draw(all);
	cast_sprites(all);
	// spriteeee(all);
	mlx_put_image_to_window(all->mlx, all->win->mlx, all->win->img, 0, 0);
	mlx_do_sync(all->mlx);
	return (0);
}

void init_tex(t_all *all)
{
	t_img		*texNO;
	t_img		*texSO;
	t_img		*texWE;
	t_img		*texEA;
	t_img		*texS;

	texNO = (t_img *)malloc(sizeof(t_img));
	texNO->img = mlx_png_file_to_image(all->mlx, all->param_map->north, &texNO->width, &texNO->height);
	texNO->addr = mlx_get_data_addr(texNO->img, &texNO->bpp, &texNO->line_len, &texNO->endian);
	all->texNO = texNO;
	texSO = (t_img *)malloc(sizeof(t_img));
	texSO->img = mlx_png_file_to_image(all->mlx, all->param_map->south, &texSO->width, &texSO->height);
	texSO->addr = mlx_get_data_addr(texSO->img, &texSO->bpp, &texSO->line_len, &texSO->endian);
	all->texSO = texSO;
	texWE = (t_img *)malloc(sizeof(t_img));
	texWE->img = mlx_png_file_to_image(all->mlx, all->param_map->west, &texWE->width, &texWE->height);
	texWE->addr = mlx_get_data_addr(texWE->img, &texWE->bpp, &texWE->line_len, &texWE->endian);
	all->texWE = texWE;
	texEA = (t_img *)malloc(sizeof(t_img));
	texEA->img = mlx_png_file_to_image(all->mlx, all->param_map->east, &texEA->width, &texEA->height);
	texEA->addr = mlx_get_data_addr(texEA->img, &texEA->bpp, &texEA->line_len, &texEA->endian);
	all->texEA = texEA;
	texS = (t_img *)malloc(sizeof(t_img));
	texS->img = mlx_png_file_to_image(all->mlx, all->param_map->sprite, &texS->width, &texS->height);
	texS->addr = mlx_get_data_addr(texS->img, &texS->bpp, &texS->line_len, &texS->endian);
	all->texS = texS;
}
int	main(int argc, char **argv)
{
	t_all		all;
	void		*mlx;
    void		*mlx_win;
	t_point		point;
	t_param_map *param_map;

	all.win = malloc(sizeof(t_win));
	all.param_map = malloc(sizeof(t_param_map));
	all.algo_data = malloc(sizeof(t_algo_data));
	all.txtr_data = malloc(sizeof(t_txtr_data));
	all.sprite = malloc(sizeof(t_sprite));
	// all.sprite->sp_cast = malloc(sizeof(t_sp_cast));

	param_map = all.param_map;
	init_stuct(&all);
	printf("argv[1] = %s\n", argv[1]);
	int      	fd = open("map.cub", O_RDONLY);
	char	  	*line = NULL;
	char 		*bigLine = NULL;

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
	printf("north path = %s", all.param_map->north);
	bigLine = ft_strjoin(bigLine, line);
	all.map = ft_split(bigLine, '\n');//проверка валидности карты
	check_player(&all);
	check_map(&all);
	free(line);
	
    all.mlx = mlx_init();
    all.win->mlx = mlx_new_window(all.mlx, param_map->scr_w, param_map->scr_h, "CUB_3D");
    all.win->img = mlx_new_image(all.mlx, param_map->scr_w, param_map->scr_h);
    all.win->addr = mlx_get_data_addr(all.win->img, &all.win->bits_per_pixel, &all.win->line_length,
                                 &all.win->endian);
	init_tex(&all);
	mlx_key_hook(all.win->mlx, move, &all);
    mlx_put_image_to_window(mlx, all.win->mlx, all.win->img, 0, 0);
	mlx_loop_hook(all.mlx, render_next_frame, &all);
    mlx_loop(all.mlx);
}
