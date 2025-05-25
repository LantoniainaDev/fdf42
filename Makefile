# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 22:28:52 by eramanit          #+#    #+#              #
#    Updated: 2025/05/25 05:40:47 by eramanit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	fdf

CC		=	cc

LIBFT	=	./libft

CFLAG	=	-Wall -Wextra -Werror

SRC		=	main.c

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