// #include "cub.h"
// #include <mlx.h>

// void window(void)
// {
// 	void *mlx = NULL;
// 	void *win = NULL;
// 	int x = 100;
// 	int y = 100;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 640, 480 , "test");
// 	while(y++ < 200)
// 	{
// 		x = 100;
// 		while(x++ < 200)
// 			mlx_pixel_put(mlx, win, x, y, 0xFFFF1);
// 	}
// 	// while(y++ < 400)
// 	// {
// 	// 	x = 100;
// 	// 	while(x++ < 600)
// 	// 		mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
// 	// }
// 	mlx_loop(mlx);
// }










// void window(t_all **map)
// {
// 	void *mlx = NULL;
// 	void *win = NULL;
// 	int x = 1;
// 	int y = 1;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 640, 480 , "test");

// 	while (map[x][y])
// 	{

	
// 		if (&map[x][y] == '1')
//  			return (mlx_pixel_put(mlx, win, x, y, 0xFFFF1));
// 		else if (&map[x][y] == '0')
// 			return (mlx_pixel_put(mlx, win, x, y, 0xFFFFF));

// 	mlx_loop(mlx);
// }
//  gcc -lmlx -framework OpenGL -framework AppKit parser.c test.c get_next_line.c cub.h libmlx.dylib Libft/libft.a

// char	**make_map(t_list **head, int size) //возращает карту
// {
// 	char	  **map = ft_calloc(size + 1, sizeof(char *));
// 	int		  i = -1;
// 	t_list	*tmp = *head;

// 	while (tmp)
// 	{
// 		map[++i] = tmp->content;
// 		tmp= tmp->next;
// 	}
// 	i = -1;
// 	while (map[++i])
// 		ft_putendl_fd(map[i]);
// 	return (map);
// }
//  static void draw_screen(char **map)
// {
//     // t_point point;
//     // t_win *win = all->win;
// 	void *img = NULL;
// 	void *mlx = NULL;
// 	void *win = NULL;
// 	int x = 1;
// 	int y = 1;

  	
    //win->addr = mlx_get_data_addr(win->img, &win->bits_per_pixel, &win->line_length, &win->endian);
    //ft_bzero(&point, sizeof(t_point));

// 	mlx = mlx_init();
// 	// win = mlx_new_image(mlx, 1080, 1080);
// 	win = mlx_new_window(mlx, 640, 480 , "cub"); 

//     while (map[y])
//     {
//         x = 0;
//         while (map[x])
//         {
//             if (map[y][x] == '1')
//                 mlx_pixel_put(mlx, win, x, y, 0xFFFFF);
//             x++;
//         }
//         y++;
//     }
//     //ft_draw_player(all, all->plr);
//     // mlx_put_image_to_window(mlx, win, img, 0, 0);
//     //mlx_destroy_image(win->mlx, win->img);

// 	mlx_loop(mlx);
// }

// int		main(int argc, char **argv)
// {
// 	int      	fd = open(argv[1], O_RDONLY);
// 	char	  	*line = NULL;
// 	t_list		*head = NULL;
// 	char		**map;

// 	while (get_next_line(fd, &line))
// 	{	
// 		// map = ft_split(*line, ' ');
// 		// // //type_identifier(*map);
// 		// 	free(line);
// 		ft_lstadd_back(&head, ft_lstnew(line));
// 	}

// 		// ft_lstadd_back(&head, ft_lstnew(line));
// 	ft_lstadd_back(&head, ft_lstnew(line));
// 	make_map(&head, ft_lstsize(head));

// 	draw_screen(map);
// 	 //map_identifier(&map);
// 	//window(*map);
// }