# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 22:28:52 by eramanit          #+#    #+#              #
#    Updated: 2025/07/27 12:36:50 by eramanit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	fdf

CC		=	cc

LIBFT	=	./libft

INC		=	./include

CFLAG	=	-Wall -Wextra -Werror

GET_NEXT_LINE = get_next_line.c get_next_line_utils.c

FDF		=	drawer.c reader.c events.c

SRC		=	main.c \
			$(addprefix get_next_line/, $(GET_NEXT_LINE)) \
			$(addprefix drawers/, $(FDF)) \

OBJ		=	$(SRC:.c=.o)

MLFLAG	=	-L./minilibx -lmlx -lXext -lX11 -lm

all		:	$(NAME)

$(NAME)	: $(SRC)
	@make -C $(LIBFT)
	@$(CC) $(CFLAG) $(SRC) -I $(INC) -I ./minilibx -L$(LIBFT) -lft $(MLFLAG) -o $(NAME)
	@echo "\033[33mFdF :: compiled\033[00m"

clean	:
	@make clean -C $(LIBFT)

fclean	:	clean
	@make fclean -C $(LIBFT)
	@rm -rf $(NAME)

re		:	fclean all

.PHONY	: all fclean clean re