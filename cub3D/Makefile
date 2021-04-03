NAME =	cub3D

# CFLAG =	-Wall -Werror -Wextra
LXFLAG =  -g -lm -lmlx -framework OpenGL -framework AppKit 

MLXLIB =  libmlx.dylib

INCD =	 -I includes/ -I Libft/includes
# INCD =	-I . -I Libft/includes

HEAD =	cub.h

# SRCD =	src/
# SRCD =	.

OBJD = 	obj/

LIBFT =	Libft/libft.a

SRC = parser.c \
		get_next_line.c \





OBJ =	$(addprefix $(OBJD), $(patsubst %.c, %.o, $(SRC)))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJD) $(OBJ)
	@cp $(LIBFT) .
	@ar -rc $(notdir $(LIBFT)) $(OBJ)
	@mv $(notdir $(LIBFT)) $(NAME)
	@ranlib $(NAME)
	@printf "🐓\x1b[32mCreate: "
	@printf $@
	@printf "\x1b[0m\n"

#gcc -g  -lm -lmlx -framework OpenGL -framework AppKit  Libft/libft.a get_next_line.c parser.c | ./a.out map.cub

$(OBJD)%.o: $(SRC)%.c $(HEAD)
#	@gcc $(CFLAG) $(LXFLAG)  -o $@ -c $< $(INCD)
	@gcc $(CFLAG) $(LXFLAG) $(LIBFT) $(SRCS)
	@printf "💜\x1b[35mCompile: "
	@printf $(notdir $@)
	@printf "\x1b[0m\n"

$(OBJD):
	@mkdir -p $@

$(LIBFT):
	@make -C $(dir $(LIBFT))

run:
	gcc -g  -lmlx -lmlx -framework OpenGL -framework AppKit  Libft/libft.a get_next_line.c pars.c parser_type.c type.c
	./a.out map.cub

clean:
	@make -C $(dir $(LIBFT)) clean
	@rm -rf $(OBJD)

fclean: clean
	@make -C $(dir $(LIBFT)) fclean
	@rm -f $(NAME)

re: fclean all