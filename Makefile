# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cababou <cababou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 22:06:43 by cababou           #+#    #+#              #
#    Updated: 2018/02/16 06:22:38 by cababou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF

SRC_C = fdf.c \
		graphinit.c \
		errors.c \
		graphics.c \
		create.c \
		util.c \
		parser.c

SRC_O = fdf.o \
		graphinit.o \
		errors.o \
		graphics.o \
		create.o \
		util.o \
		parser.o

all : compile

$(NAME) :
			gcc -c $(SRC_C)

compile : $(NAME)
			gcc -g -fsanitize=address -lmlx -framework OpenGL -framework AppKit $(SRC_O) libft/libft.a -o $(NAME)

clean :
			rm -rf $(SRC_O)

fclean :	clean
			rm -rf $(NAME)

re :		fclean all
