#ifndef CUB_H
# define CUB_H


#include "minilibx_mms/mlx.h"
#include "Libft/includes/libft.h" 
#include <mlx.h>
# include <unistd.h>

#define SCALE 50 // условный размер каждого квадратика в карте
# define BUFFER_SIZE 1

typedef struct	s_win //структура для окна
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_length;
	int			bits_per_pixel;
	int			endian;
}				  t_win;

typedef struct	s_point // структура для точки
{
	int			x;
	int			y;
}				 t_point;

typedef struct	s_plr //структура для игрока и луча
{
	float		x;
	float		y;
	float		dir;
	float		start;
	float		end;
}				  t_plr;

typedef struct	s_param_map
{
	int			scr_w;
	int			scr_h;
}				t_param_map;
typedef struct	s_gnl
{
	char	buf[BUFFER_SIZE + 1];
	int		count;
	char	*ptr_n;
	char	*tmp;
}				t_gnl;

typedef struct  s_data
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct	s_all // структура для всего вместе
{
	t_win		*win;
	t_plr		*plr;
	t_param_map *param_map;
	char		**map;
}				t_all;

int				get_next_line(int fd, char **line);
int				type_identifier(char *line, t_all *all);
int check_resolution(char *line, t_all *all);
 

#endif