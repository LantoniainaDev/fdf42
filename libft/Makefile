# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 22:59:55 by eramanit          #+#    #+#              #
#    Updated: 2025/07/27 09:52:46 by eramanit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAG	=	-Wall -Wextra -Werror

SRC		=	ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_strlen.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
			ft_strncmp.c ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
			ft_strdup.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c

BONUS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

SRCALL	=	${SRC} ${BONUS}

NAME	=	libft.a

OBJ		=	${SRC:.c=.o}

OBJALL	=	${SRCALL:.c=.o}

%.o		:	%.c
		@${CC} ${CFLAG} -c $< -o $@

all		: ${NAME}

${NAME}	:	${OBJ}
		@ar -rsc ${NAME} ${OBJ}

bonus	:	${OBJALL}
		@ar -rsc ${NAME} ${OBJALL}	

clean	:
		@rm -f ${OBJALL}

fclean	:	clean;
		@rm -f ${NAME}

re		:	fclean all
