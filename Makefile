# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cababou <cababou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 22:06:43 by cababou           #+#    #+#              #
#    Updated: 2018/09/04 03:19:45 by cababou          ###   ########.fr        #
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
		./text.c \
		./util_nb.c \
		./events.c \
		./optimization.c \
		./ui/button.c \
		./bresenham/drawline.c \
		./bresenham/q1.c \
		./bresenham/q2.c \
		./bresenham/q3.c \
		./bresenham/q4.c \
		./bresenham/q5.c \
		./tabs/tabs.c \
		./tabs/tabs_init.c \
		./tabs/rendering.c \
		./map_rendering/renderer.c \
		./map_rendering/formatter.c \
		./map_rendering/conversion.c \
		./map_rendering/rotations.c \
		./map_rendering/image_funcs.c \
		./map_rendering/image_funcs_two.c \
		./map_rendering/colors.c \
		./get_next_line.c
	
OBJ = $(SRC:.c=.o)

LIB = ./libft

FLAG = -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
			make -C $(LIB)
			gcc -o3 $(FLAG) $(OBJ) ./libft/libft.a -o $(NAME)

%.o: %.c
			gcc -o3 -c -Wall -Wextra -Werror $< -o $@ 

clean :
			rm -rf $(OBJ)
			make clean -C $(LIB)

fclean :	clean
			rm -rf $(NAME)
			make fclean -C $(LIB)

re :		fclean all
