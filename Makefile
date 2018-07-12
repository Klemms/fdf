# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cababou <cababou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 22:06:43 by cababou           #+#    #+#              #
#    Updated: 2018/07/10 00:42:10 by cababou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF

SRC =	./fdf.c \
		./graphinit.c \
		./errors.c \
		./graphics.c \
		./create.c \
		./util.c \
		./parser.c \
		./hooks.c \
		./color.c \
		./bresenham/drawline.c \
		./bresenham/q1.c \
		./bresenham/q2.c \
		./bresenham/q3.c \
		./bresenham/q4.c \
		./bresenham/q5.c \
		./tabs/tabs.c
	
OBJ = $(SRC:.c=.o)

LIB = ./libft

FLAG = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJ)
			make -C $(LIB)
			gcc $(FLAG) $(OBJ) ./libft/libft.a -o $(NAME)

%.o: %.c
			gcc -c $(FLAG) $< -o $@ 

clean :
			rm -rf $(OBJ)
			make clean -C $(LIB)

fclean :	clean
			rm -rf $(NAME)
			make fclean -C $(LIB)

re :		fclean all
