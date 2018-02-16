/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 22:00:07 by cababou           #+#    #+#             */
/*   Updated: 2018/02/16 06:47:44 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define READ_BUF_SIZE 64

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_window
{
	void		*window;
	int			width;
	int			height;
	char		*title;
}				t_window;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

void			exit_program(int errortype);

void			*init_graphics(void);

void			init_window(void *mlx, t_window **window);

void			show_error_window(void *mlx, int error_type, void *content);

t_window		*create_window_struct(int width, int height, char *title);

void			fill_window(void *mlx, t_window *window, int color);

char			*read_file(char *filepath);

t_list			*parse_file(char *filepath);

#endif
