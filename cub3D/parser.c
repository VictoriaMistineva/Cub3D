#include "cub.h"
#include "Libft/includes/libft.h" 
#include <fcntl.h>

//  gcc -lmlx -framework OpenGL -framework AppKit parser.c test.c get_next_line.c cub.h libmlx.dylib Libft/libft.a

char	**make_map(t_list **head, int size)
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
void draw_screen(t_all *all)
{
    t_point point;
    t_window *win = all->win;
    win->img = mlx_new_image(win->mlx, 1080, 1080);
    win->addr = mlx_get_data_addr(win->img, &win->bits_per_pixel, &win->line_length, &win->endian);
    ft_bzero(&point, sizeof(t_point));
    while (all->map[point.y])
    {
        point.x = 0;
        while (all->map[point.x])
        {
            if (all->map[point.y][point.x] == '1')
                mlx_pixel_put(all->win->mlx, all->win->win, point.x, point.y, 0xFFFFFF);
            point.x++;
        }
        point.y++;
    }
    //ft_draw_player(all, all->plr);
    mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
    //mlx_destroy_image(win->mlx, win->img);
}

int		main(int argc, char **argv)
{
	int      	fd = open(argv[1], O_RDONLY);
	char	  	*line = NULL;
	t_list		*head = NULL;
		char		**map;

	while (get_next_line(fd, &line))
	{	
		(*map) = ft_strdup(*line);
		type_identifier(*map);
			free(line);
	}

		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(&head, ft_lstsize(head));
	//int map_identifier(char **line)
	// window();
}