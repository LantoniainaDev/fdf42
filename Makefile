# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 22:28:52 by eramanit          #+#    #+#              #
#    Updated: 2025/06/20 11:51:45 by eramanit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	fdf

CC		=	cc

LIBFT	=	./libft

CFLAG	=	-Wall -Wextra -Werror

GET_NEXT_LINE = get_next_line.c get_next_line_utils.c

FDF		=	drawer.c reader.c

SRC		=	main.c \
			$(addprefix get_next_line/, $(GET_NEXT_LINE)) \
			$(addprefix drawers/, $(FDF)) \

OBJ		=	$(SRC:.c=.o)

MLFLAG	=	-L./minilibx -lmlx -lXext -lX11

all		:	$(NAME)

$(NAME)	: $(SRC)
	@make -C $(LIBFT)
	@$(CC) $(CFLAG) -L$(LIBFT) -lft $(MLFLAG) $(SRC) ./minilibx/libmlx.a ./libft/libft.a -I $(LIBFT) -o $(NAME)
	@echo "\033[33mFdF :: compiled\033[00m"

clean	:
	@make clean -C $(LIBFT)

fclean	:	clean
	@make fclean -C $(LIBFT)
	@rm -rf $(NAME)

re		:	fclean all

.PHONY	: all fclean clean re