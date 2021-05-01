#ifndef CUB_H
# define CUB_H


# include "minilibx_mms/mlx.h"
# include "Libft/includes/libft.h" 
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

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
	char		*addr;
	int			line_length;
	int			bits_per_pixel;
	int			endian;
}				  t_win;

typedef struct	s_point // структура для точки
{
	int			x;
	int			y;
}				 t_point;

typedef struct	s_pm
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
	double		plY;
	double		plX;
}				t_pm;

typedef struct	s_gl
{
	double		pwd;
	double		camera_x;
	int			hit;
	int			side;
	int			line_h;
	int			draw_start;
	int			draw_end;
	double		rayDirY;
	double		rayDirX;
	double		deltaDistX;
	double		deltaDistY;
	int 		stepX;
    int 		stepY;
	double 		sideDistX;
    double 		sideDistY;
	int 		mapX;
    int 		mapY;
	double		old_plX;

}				t_gl;

typedef struct	s_img 
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			height;
	int			width;
}				t_img;

typedef struct	s_txtr_data 
{
	int			text_num;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		text_pos;
	int			color;
}				t_txtr_data;

typedef struct	s_gnl
{
	char	buf[BUFFER_SIZE + 1];
	int		count;
	char	*ptr_n;
	char	*tmp;
}				t_gnl;

typedef struct s_sp_cast  //amount
{
	int order;
	double dist;
}			t_sp_cast;

typedef struct s_sp  //amount
{
	double		x;
	double		y;
}			t_sp;

typedef struct s_sprite
{
	t_sp_cast 	*sp_cast;
	t_sp		*sp;
    double      *z_buf;
    double      spriteX;
    double      spriteY;
    double      invDet;
    double      transformX;
    double      trfY;
    int         sp_ScrX;
    int         sp_H;
    int         drawStartY;
    int         drawEndY;
    int         sp_W;
    int         drawStartX;
    int         drawEndX;
    int         texX;
    int         d;
    int         texY;
    int         sp_num;
    int         color;
	int			*sp_order;
	double		*sp_dist;
}       		t_sprite;

typedef struct	s_all // структура для всего вместе
{
	void		*mlx;
	t_win		*win;
	t_pm *pm;
	t_gl	*gl;
	t_txtr_data	*txtr_data;
	t_sprite    *sprite;
	t_img		*texNO;
	t_img		*texSO;
	t_img		*texWE;
	t_img		*texEA;
	t_img		*texS;
	char		**map;
	int			flag_save;
	int			file;
}				t_all;

//utils
int		charlen(char **str);
char	*printf_exit(char *str);
int		ft_atoi_pars(const char *str);
void	validate_color(int color);
int		create_rgb(int r, int g, int b);
int		type_flags_check(t_all *all);
int		check_num(const char *str, int num);
char			**array_free(char **array);

int	get_next_line(int fd, char **line);
int	type_identifier(char *line, t_all *all);
int	resolution(char *line, t_all *all);
int	check_argument_textur(char *line, t_all *all);
int check_texture(char *line, char **texture);
void	color_floor_cell(t_all *all);

int		floor_color(char *line, t_all *all);
int		celling_color(char *line, t_all *all);
void	check_map(t_all *all);
void	check_player(t_all *all);
int	cast_rays(t_all *all);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);
int		move(int key, t_all *all);
void draw(t_all *all);

void	cast_sprites(t_all *all);
int		render_next_frame(t_all *all);
void	check_player_map(t_all *all);

void 	sotirovka_sprite(t_sprite *sprite);
void    create_screenshot(t_all *all);
void is_save(char **argv, t_all *all, int argc);
void set_cub(t_all *all, char **argv, int argc);

#endif