# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhurt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 18:39:06 by lhurt             #+#    #+#              #
#    Updated: 2017/01/23 18:39:08 by lhurt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc

FLAG =		-Wall -Wextra -Werror -o

LX =		-lmlx

MINLX =		./minilibx

INC =		-I $(MINLX)

LIB =		-L $(MINLX)

OPENGL =	-framework OpenGl

APPKIT =	-framework AppKit

LIBFT =		libft

COMP =		make -C $(LIBFT) re

COMPC =		make -C $(LIBFT) clean

COMPF =		make -C $(LIBFT) fclean

NAME =		a.out

SRCS =		$(LIBFT)/libft.a \
			main.c	\

THREAD =	-lpthread

all: 	$(NAME)

$(NAME):
		@$(COMP)
		@$(CC) $(INC) $(LIB) $(LX) $(OPENGL) $(APPKIT) $(FLAG) $(NAME) $(SRCS) $(THREAD)
		@echo "$(NAME) & $(LIBFT).a: has been created."

clean:
		@$(COMPC)
		@echo "$(LIBFT) has been cleaned."

fclean:	clean
		@$(COMPF)
		@/bin/rm -f $(NAME)
		@echo "$(NAME) & $(LIBFT).a: has been erased."

re: 	fclean all

.PHONY: all clean fclean re
