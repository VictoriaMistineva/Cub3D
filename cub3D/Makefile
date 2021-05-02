SRCS =	main_utils.c \
		main.c \
		main_utils_2.c \
		screen.c \
		parser/check_f_c.c \
		parser/check_r_textur.c \
		parser/color.c \
		parser/get_next_line.c \
		parser/get_next_line_utils.c \
		parser/pars_map.c \
		parser/pars_ut.c \
		parser/pars_utils.c \
		parser/parser_type.c \
		rayscast/front.c \
		rayscast/front_utils.c \
		rayscast/key.c \
		rayscast/player.c \
		rayscast/sprite_draw.c \
		rayscast/sprite.c \
		utils/ft_bzero.c \
		utils/ft_split.c \
		utils/ft_strdup_copy.c \
		utils/ft_strdup.c \
		utils/ft_strjoin.c \
		utils/ft_strlen.c \
		utils/ft_strrchr.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -O3 -I.
LIBS			= -framework OpenGL -framework AppKit libmlx.dylib
MLX				= libmlx.dylib

NAME			= cub3D

all:			$(NAME)

$(NAME):		$(MLX) $(OBJS)
				gcc -g libmlx.dylib ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

$(MLX):
				@$(MAKE) -C minilibx_mms
				@mv minilibx_mms/$(MLX) .

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(MLX)

re:				fclean $(NAME)

.PHONY:			all clean fclean re