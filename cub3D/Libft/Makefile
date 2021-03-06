# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycordell <ycordell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 20:33:05 by ycordell          #+#    #+#              #
#    Updated: 2021/03/06 21:22:01 by ycordell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

#CFLAG =	-Wall -Werror -Wextra

INCD =	-I includes/

HEAD =	includes/libft.h

SRCD =	src/

OBJD = 	obj/

SRC =	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_putnbr_fd.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_numlen.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_lstsize.c \
				

OBJ =	$(addprefix $(OBJD), $(patsubst %.c, %.o, $(SRC)))

all: $(NAME)

$(NAME): $(OBJD) $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "🐥\x1b[32mCreate: "
	@printf $@
	@printf "\x1b[0m\n"

$(OBJD)%.o: $(SRCD)%.c $(HEAD)
	@gcc $(CFLAG) -o $@ -c $< $(INCD)
	@printf "💜\x1b[35mCompile: "
	@printf $(notdir $@)
	@printf "\x1b[0m\n"

$(OBJD):
	@mkdir -p $@

clean:
	@rm -rf $(OBJD)

fclean: clean
	@rm -f $(NAME)

re: fclean all
