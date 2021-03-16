#include "cub.h"
#include "Libft/includes/libft.h" 
#include <fcntl.h>
#include <stdio.h>

//  gcc -lmlx -framework OpenGL -framework AppKit parser.c test.c get_next_line.c cub.h libmlx.dylib Libft/libft.a
void ft_struct(t_point *point , t_win *win)
{
	win->img = NULL;
	win->mlx = NULL;
	win->win = NULL;
	point->x = 0;
	point->y = 0;
	//ft_bzero(&flags, sizeof(t_flags))
}

char	**make_map(t_list **head, int size) //возращает карту двухмерный массив
{
	char	  **map = ft_calloc(size + 1, sizeof(char *));
	int		  i = -1;
	t_list	*tmp = *head;

	while (tmp)
	{
		map[++i] = tmp->content;
		tmp= tmp->next;
	}
	i = -1;
	while (map[++i])
		ft_putendl_fd(map[i]);
	return (map);
}
void map_identifier(t_all *all)
{
	t_win *win = all->win;
	t_point *point;

	while (all->map[point->x])
	{
		while (all->map[point->y])
		{
			if (all->map[point->x][point->y] == '1')
				printf("map");
				// mlx_pixel_put(all->win->mlx, all->win->win, point->x, point->y, 0xFFFFFF);
			// else if (all->map[point->x][point->y] == '0')
			// 	mlx_pixel_put(all->win->mlx, all->win->win, point->x, point->y, 0x000000);
			point->x++;
		}
		point->y++;
	}	
}

char		**read_full_map(char **argv, t_plr *plr)
{
	int      	fd;
	char	  	*line = NULL;
	t_list		*head = NULL;
	t_all		all;


	fd = open(argv[0], O_RDONLY);

	printf("my fd is %d\n", fd);
	while (get_next_line(fd, &line) > 0)
	{
		printf("kek\n");
		 if(type_identifier(line) > 0)
		 {

			ft_lstadd_back(&head, ft_lstnew(&line));
			map_identifier(&all);
		 }
	}
	//close(fd);
	ft_lstadd_back(&head, ft_lstnew(&line));
	return(make_map(&head, ft_lstsize(head)));
	
}

int main(int argc , char **argv)
{
	t_win		win;
	t_plr		plr;
	t_all		all;

	printf("k4k\n");
	if (argc < 2)
		printf("i need a map\n");
		//exit;
	if (argc > 3)
		printf("много аггументов\n");
		//exit;
	all.map = read_full_map(&argv[1], &plr);


	// ft_init_player(map, &player);
	win.mlx = mlx_init();
	win.win  = mlx_new_window(win.mlx, 640, 480 , "cub");
	win.img = mlx_new_image(win.mlx, 640, 480);
	win.addr = mlx_get_data_addr(win.img, &win.bits_per_pixel, &win.line_length, &win.endian);
//	all.plr = &plr;
	all.win = &win;
	//map_identifier(&all);
	// hook
	mlx_loop(win.mlx);
}
 int type_identifier(char *line)
 {
	 int i ;
	 i = -1;

	printf("%s\n", line);
	while(line[++i])
	{
	 if (line[i] == 'R' && line[i + 1] == ' ')
		 //return (resolution());
		 printf("R\n");
	 else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		 //return (texture());
		 printf("NO\n");
	 else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		 //return (texture());
		 printf("SO\n");
	 else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		 //return (texture());
		 printf("WE\n");
	 else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		 //return (texture());
		 printf("EA\n");
	 else if (line[i] == 'S' && line[i + 1] == ' ')
		 //return (texture());
		 printf("S\n");
	 else if (line[i] == 'F' && line[i + 1] == ' ')
		 //return (floor_texture());
		 printf("FLOOR\n");
	 else if (line[i] == 'C' && line[i + 1] == ' ')
		 //return (ceilling_texture());
		 printf("CEIL\n");
	}
	 return (0);
 }
