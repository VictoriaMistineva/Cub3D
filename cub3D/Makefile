NAME =	libftprintf.a

#CFLAG =	-Wall -Werror -Wextra

# INCD =	-I includes/ -I Libft/includes
INCD =	-I /. -I Libft/includes

HEAD =	cub.h

# SRCD =	src/
SRCD =	/.

OBJD = 	obj/

LIBFT =	Libft/libft.a

# SRC =	ft_printf.c \
# 		ftp_apply_type.c \
# 		ftp_utils.c \
# 		ftp_di.c \
# 		ftp_c.c \
# 		ftp_p.c \
# 		ftp_u.c \
# 		ftp_s.c \
# 		ftp_xX.c \
# 		ftp_parser.c

SRCD = parser.c \
		test.c


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

$(OBJD)%.o: $(SRCD)%.c $(HEAD)
	@gcc $(CFLAG) -o $@ -c $< $(INCD)
	@printf "💜\x1b[35mCompile: "
	@printf $(notdir $@)
	@printf "\x1b[0m\n"

$(OBJD):
	@mkdir -p $@

$(LIBFT):
	@make -C $(dir $(LIBFT))

clean:
	@make -C $(dir $(LIBFT)) clean
	@rm -rf $(OBJD)

fclean: clean
	@make -C $(dir $(LIBFT)) fclean
	@rm -f $(NAME)

re: fclean all