#ifndef CUB_H
# define CUB_H

# include "minilibx_mms/mlx.h" 
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

typedef struct s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			line_length;
	int			bits_per_pixel;
	int			endian;
}				t_win;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_pm
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

typedef struct s_gl
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
	int			stepX;
	int			stepY;
	double		sideDistX;
	double		sideDistY;
	int			mapX;
	int			mapY;
	double		old_plX;
}				t_gl;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			height;
	int			width;
}				t_img;

typedef struct s_txtr_data
{
	int			text_num;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		text_pos;
	int			color;
}				t_txtr_data;

typedef struct s_gnl
{
	char		buf[BUFFER_SIZE + 1];
	int			count;
	char		*ptr_n;
	char		*tmp;
}				t_gnl;

typedef struct s_sp_cast
{
	int			order;
	double		dist;
}				t_sp_cast;

typedef struct s_sp
{
	double		x;
	double		y;
}				t_sp;

typedef struct s_sprite
{
	t_sp_cast	*sp_cast;
	t_sp		*sp;
	double		*z_buf;
	double		spriteX;
	double		spriteY;
	double		invDet;
	double		transformX;
	double		trfY;
	int			sp_ScrX;
	int			sp_H;
	int			drawStartY;
	int			drawEndY;
	int			sp_W;
	int			drawStartX;
	int			drawEndX;
	int			texX;
	int			d;
	int			texY;
	int			sp_num;
	int			color;
	int			*sp_order;
	double		*sp_dist;
}				t_sprite;

typedef struct s_all // структура для всего вместе
{
	void		*mlx;
	t_win		*win;
	t_pm		*pm;
	t_gl		*gl;
	t_txtr_data	*txtr_data;
	t_sprite	*sprite;
	t_img		*texNO;
	t_img		*texSO;
	t_img		*texWE;
	t_img		*texEA;
	t_img		*texS;
	char		**map;
	int			flag_save;
	int			file;
}				t_all;

void	init_map(t_all *all, char *line, char *bigLine);
void	init_tex_2(t_all *all);
void	init_tex(t_all *all);
void	malloc_sp(t_all *all);
int		render_next_frame(t_all *all);
void	init_struct(t_all *all);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);
void	create_screenshot(t_all *all);
void	create_screenshot2(int fd, t_all *all);
void	is_save(char **argv, t_all *all, int argc);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s, size_t n);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
void	cast_sprites(t_all *all);
void	sp_color(t_all *all);
void	sp_color_2(t_all *all, int y, int stp);
void	sp_drawend(t_all *all);
void	sp_drawstart(t_all *all, int i);
void	sp_1(t_all *all);
void	check_player(t_all *all);
int		move(int key, t_all *all);
int		cast_rays(t_all *all);
void	cr_part4(t_all *all);
void	cr_part3(t_all *all, int x);
void	cr_Y(t_all *all);
void	cr_X(t_all *all);
void	cr_part1(t_all *all, int x);
int		type_identifier(char *line, t_all *all);
int		check_num(const char *str, int num);
int		type_flags_check(t_all *all);
int		ft_atoi_pars(const char *str);
char	*printf_exit(char *str);
int		charlen(char **str);
char	**array_f(char **array);
void	set_cub(t_all *all, char **argv, int argc);
void	check_map(t_all *all);
void	check_invalid(t_all *all, int k, int j);
void	check_cell(t_all *all, int j, int k);
void	check_player_map(t_all *all);
int		get_next_line(int fd, char **line);
void	norme_gnl(char *remd, int i, int *j, char *new);
int		is_line(char *save);
int		ft_strlen2(char *str);
void	validate_color(int color);
int		create_rgb(int r, int g, int b);
int		check_texture(char *line, char **texture);
int		resolution(char *line, t_all *all);
int		celling_color(char *line, t_all *all);
int		floor_color(char *line, t_all *all);
void	free_res(char **color);
char	*return_space(char *line);
int		exiit(int key, t_all *all);

#endif