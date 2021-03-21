#include "cub.h"
#include "Libft/includes/libft.h" 
#include <fcntl.h>
#include <stdio.h>

void            my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void		draw_scale(t_all *all, t_point point)
{
	int i;
	int j;

	i = 0;
	while (i < 100)
	{
		j = 0;
		while(j< 50)
		{
			my_mlx_pixel_put(all->win, point.x, point.y, 0x00FFFF1);
			j++;
			point.x++;
		}
		i++;
		point.y++;
	}
}


int		main(int argc, char **argv)
{
	t_all		all;
	void   		 *mlx;
    void  		  *mlx_win;
    t_win 		 img;

	t_point point;

	int      fd = open(argv[1], O_RDONLY);
	char	  *line = NULL;
	int i;
	char *bigLine = NULL;
	
	i = 0;	
	while (get_next_line(fd, &line) > 0)
	{
		if (i > 8)
		{
			bigLine = ft_strjoin(bigLine, line);
			// freee
			bigLine = ft_strjoin(bigLine, "\n");
		}
		// printf("%s\n", line);
		free(line);
		i++;
	}
	bigLine = ft_strjoin(bigLine, line);
	all.map = ft_split(bigLine, '\n');
	// printf("%s\n", map[0]);
	free(line);

	int j;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
	all.win = &img;
	// draw_screen(&all);
	// i = 0;
	// while (i <= 100)
	// {
	// 	j = 0;
	// 	while(j<= 50)
	// 	{
	// 		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
	// 		j++;
	// 	}
	// 	i++;	
	// }

    // ft_bzero(&point, sizeof(t_point));

    point.y = 0;
    while (all.map[point.y] != NULL)
    {
		point.x = 0;
		while(all.map[point.y][point.x])
		{
			if (all.map[point.y][point.x] == '1')
        		draw_scale(&all, point);
        	point.x++;
		}
	 	point.y++;
	}
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
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