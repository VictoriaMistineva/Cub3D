//#include "cub.h" 

// int type_identifier(t_all **map))
// {
// 	if (line[0] == 'R' && line[1] == ' ')
// 		return (resolution());
// 	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
// 		return (texture());	
// 	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
// 		return (texture());
// 	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
// 		return (texture());
// 	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
// 		return (texture());
// 	else if (line[0] == 'S' && line[1] == ' ')
// 		return (texture());	
// 	else if (line[0] == 'F' && line[1] == ' ' )
// 		return (floor_texture());
// 	else if (line[0] == 'C' && line[1] == ' ' )
// 		return (ceilling_texture());
// 	//eror

// 	return 0;
// }
// int map_identifier(char **line)
// {
	
// }

// int error
// int map_identifier(t_all **map )
// {	
// 	void *mlx = NULL;
// 	void *win = NULL;
// 	int x = 100;
// 	int y = 100;

// 		if (&map[x][y] == '1')
//  			return (mlx_pixel_put(mlx, win, x, y, 0xFFFF1));
// 		else if (&map[x][y] == '0')
// 			return (mlx_pixel_put(mlx, win, x, y, 0xFFFFF));
	
// 	return 1;

//  static void map_identifier(t_all *all)
// {

// 	// void *img = NULL;
// 	// void *mlx = NULL;
// 	// void *window = NULL;
// 	// int x = 1;
// 	// int y = 1;

//   	t_point point;
//     // t_window *win = all->win;

//     ft_bzero(&point, sizeof(t_point));
//     while (all->map[point.y])
//     {
//         point.x = 0;
//         while (all->map[point.x])
//         {
//             if (all->map[point.y][point.x] == '1')
//                 mlx_pixel_put(all->win->mlx, all->win->win, point.x, point.y, 0xFFFFFF);
//             point.x++;
//         }
//         point.y++;
//     }
//     //ft_draw_player(all, all->plr);
//     mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
//     //mlx_destroy_image(win->mlx, win->img);
// }

// int		read_full_map(int argc, char **argv)
// {
// 	int      	fd;
// 	char	  	*line = NULL;
// 	t_list		*head = NULL;
// 	char		**map;
// 	fd = open(argv[1], O_RDONLY) > 0;	
// 	while (get_next_line(fd, &line))
// 	{	
// 		// type_identifier(&line);
// 		// 	free(line);
// 		ft_lstadd_back(&head, ft_lstnew(line));
// 	}
// 	close(fd);
// 	ft_lstadd_back(&head, ft_lstnew(line));
// 	return(make_map(&head, ft_lstsize(head)));
// 	// remap_identifier(map);
// }

// int main(int argc , char **argv)
// {
// 	t_window	win;
// 	t_plr		plr;
// 	t_all		all;

// 	if (argc == 2)
// 		all.map = read_full_map(argv[1], &plr);
// 	else
// 		printf("i need a map");
// 	remap_identifier(map);
// 	// ft_init_player(map, &player);
// 	win.mlx = mlx_init();
// 	win.window  = mlx_new_window(win.mlx, 640, 480 , "cub");
// 	win.img = mlx_new_image(win.mlx, 640, 480);
// 	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_length, &win.endian);
// 	all.play = &play;
// 	all.win = &win;
// 	// hook
// 	mlx_loop(window.mlx);
// }