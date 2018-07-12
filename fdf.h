/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 22:00:07 by cababou           #+#    #+#             */
/*   Updated: 2018/07/13 01:21:38 by cababou          ###   ########.fr       */
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
# include <stdio.h>
# include <math.h>

typedef struct		s_tag
{
	char			*name;
	void			*value;
}					t_tag;

typedef struct		s_tab
{
	char			*tab_name;
}					t_tab;

typedef struct		s_tabs
{
	t_lstcontainer	*tab_list;
}					t_tabs;

typedef struct		s_window
{
	void			*window;
	int				width;
	int				height;
	char			*title;
	int				x1line;
	int				y1line;
	int				x2line;
	int				y2line;
	t_lstcontainer	*tags;
	t_tabs			*tabs;
}					t_window;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_loop_params
{
	void			*mlx;
	t_window		*fdf_window;
}					t_loop_params;

int					loop(t_loop_params *loop_params);

int					mouse_clicked(int bton, int x, int y, t_loop_params *param);

int					key_pressed(int key, t_loop_params *params);

void				exit_program(int errortype);

void				*init_graphics(void);

void				init_window(void *mlx, t_window *window);

void				show_error_window(void *mlx, int error_type, void *content);

t_window			*create_window_struct(int width, int height, char *title);

void				fill_window(void *mlx, t_window *window, int color);

char				*read_file(char *filepath);

t_lstcontainer		*parse_file(char *filepath);

t_point				*new_point(int x, int y, int z);

int					rgba_to_int(int r, int g, int b, int a);

void				line(t_loop_params *p, t_point *p_1, t_point *p_2, int c);

void				init_tabs(t_window *window);

void				render_tabs(t_loop_params *params);

void				fill_rect(t_loop_params *p, t_point *po, t_point *s, int c);

#endif
