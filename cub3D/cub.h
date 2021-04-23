#ifndef CUB_H
# define CUB_H


# include "minilibx_mms/mlx.h"
# include "Libft/includes/libft.h" 
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define SCALE 50 // условный размер каждого квадратика в карте
# define PLAYER "NSEW"
# define VALID_MAP "012 NSEW"
# define BUFFER_SIZE 1

# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

# define KEY_LEFT				123
# define KEY_RIGHT				124

# define KEY_ESC				53 


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

typedef struct	s_param_map
{
	int			scr_h;
	int			scr_w;
	int			floor_r;
	int			floor_g;
	int			floor_b;
	int			ceil_r;
	int			ceil_g;
	int			ceil_b;
	int			color_ceil;
	int			color_floor;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*sprite;
	double		posY;		
	double		posX;
	double		dirY;
	double		dirX;
	double		planeY;
	double		planeX;
	double		oldDirX
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
	t_param_map *param_map;
	char		**map;
}				t_all;

//utils
int charlen(char **str);
char *printf_exit(char *str);
int	ft_atoi_pars(const char *str);
void	validate_color(int color);
int		create_rgb(int r, int g, int b);
int type_flags_check(t_all *all);
int		check_num(const char *str, int num);

int	get_next_line(int fd, char **line);
int	type_identifier(char *line, t_all *all);
int	resolution(char *line, t_all *all);
int	check_argument_textur(char *line, t_all *all);
int check_texture(char *line, char *texture);
void color_floor_cell(t_all *all);

int		floor_color(char *line, t_all *all);
int		celling_color(char *line, t_all *all);
void	check_map(t_all *all);
void	check_player(t_all *all);

#endif