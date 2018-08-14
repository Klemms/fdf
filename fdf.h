/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 22:00:07 by cababou           #+#    #+#             */
/*   Updated: 2018/08/14 04:39:33 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define READ_BUF_SIZE 4096

# include <mlx.h>
# include <Tk/X11/X.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>
# include <math.h>

typedef struct		s_tag
{
	char			*name;
	void			*value;
}					t_tag;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_int
{
	int				value;
}					t_int;

typedef struct		s_dline
{
	t_point			*start;
	t_point			*end;
	t_int			*is_rendered;
}					t_dline;

typedef struct		s_pixel
{
	int				x;
	int				y;
	int				color;
}					t_pixel;

typedef struct		s_image
{
	int				width;
	int				height;
	int				*image;
}					t_image;

typedef struct		s_mlx_img
{
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_mlx_img;

typedef struct		s_top_menu_settings
{
	int				height;
	int				width;
}					t_top_menu_settings;

typedef struct		s_map_settings
{
	int				x_position;
	int				y_position;
	int				size;
	int				isometric_factor;
	int				rot_x;
	int				rot_y;
	int				rot_z;
	int				angle_1;
	int				angle_2;
	int				max_x;
	int				max_y;
	int				height;
}					t_map_settings;

typedef struct		s_button
{
	int				identifier;
	char			*button_text;
	t_point			*location;
	t_point			*size;
	int				color;
	int				text_color;
	int				is_visible;
	int				status;
	int				(*click_callback)(struct s_button *b, t_point *loc, int cl);
}					t_button;

typedef struct		s_tab
{
	char			*tab_name;
	int				identifier;
	t_lstcontainer	*point_list;
	t_lstcontainer	*buttons;
	t_point			*position;
	t_point			*size;
	t_map_settings	*map_settings;
	int				menu_linked_button;
	void			*black_background;
	void			*map_image;
	t_lstcontainer	*lines;
}					t_tab;

typedef struct		s_tabs
{
	t_lstcontainer	*tab_list;
	t_lstcontainer	*buttons;
	t_tab			*selected_tab;
}					t_tabs;

typedef struct		s_window
{
	void			*window;
	t_point			*size;
	int				width;
	int				height;
	char			*title;
	int				last_x;
	int				last_y;
	int				left_click_pressed;
	t_lstcontainer	*tags;
	t_tabs			*tabs;
	t_lstcontainer	*buttons;
}					t_window;

typedef struct		s_params
{
	void			*mlx;
	t_window		*fdf_window;
	int				next_indentifier;
}					t_params;

int					loop(t_params *params);

int					mouse_clicked(int bton, int x, int y, t_params *param);

int					key_pressed(int key, t_params *params);

int					exit_program(int errortype);

void				*init_graphics(void);

void				init_window(void *mlx, t_window *window);

void				show_error_window(void *mlx, int error_type, void *content);

t_window			*create_window_struct(int width, int height, char *title);

void				fill_window(void *mlx, t_window *window, int color);

char				*read_file(char *filepath);

t_lstcontainer		*parse_file(char *filepath);

t_point				*new_fpt(int x, int y, int z);

t_point				*new_pt(int x, int y);

t_dline				*new_line(t_point *start, t_point *end);

int					rgba_to_int(int r, int g, int b, int a);

void				line(t_params *p, t_image *img,
					t_point *p_1, t_point *p_2, int c);

void				init_tabs(t_params *params, int argc, char **argv);

void				render_top_menu(t_params *params);

void				fill_rect(t_params *p, t_point *po, t_point *s, int c);

void				*fill_img(t_params *p, t_point *wh, int c);

int					textsize(char *text);

t_button			*create_button(char *t, t_point *l, t_point *s, t_point *c);

void				make_button(t_params *p, t_button *bt, t_lstcontainer *cnt,
					int (*callback)(t_button *bt, t_point *loc, int click));

void				render_button(t_params *p, t_button *b);

int					button_clicked(int click, int x, int y, t_params *params);

void				render_tab(t_params *params, t_tab *tab);

void				hide_tab(t_params *p, t_tab *tab);

void				render_map(t_params *p, t_tab *tab, int render_type);

t_lstcontainer		*make_lines(t_params *p, t_lstcontainer *points);

t_point				*two_d_to_iso(t_point *point, int factor);

t_point				*two_d_to_three_d(t_point *point, int angle_1, int angle_2);

t_point				*two_d_to_three_d_2(t_point *point, int angle_1);

t_map_settings		*make_map_settings(t_params *p, t_lstcontainer *points);

void				zoom_map(t_params *p, int factor);

double				to_radians(int degrees);

t_point				*add_fpt(t_point *point, int x, int y, int z);

int					file_max_x(t_lstcontainer *points);

int					file_max_y(t_lstcontainer *points);

int					file_height(t_lstcontainer *points);

t_point				*rotate(t_point *point, int x_rot, int y_rot, int z_rot);

t_point				*x_rotation(t_point *point, int angle);

t_point				*y_rotation(t_point *point, int angle);

t_point				*z_rotation(t_point *point, int angle);

int					highest_z(t_point *start, t_point *end);

int					remaining_to_render(t_lstcontainer *dlines);

int					mouse_pressed(int button, int x, int y, t_params *p);

int					mouse_released(int button, int x, int y, t_params *p);

t_pixel				*new_pxl(int x, int y, int color);

int					pxl_width(t_lstcontainer *pixels);

int					pxl_height(t_lstcontainer *pixels);

void				wrt_pxl(t_image *img, int x, int y, int color);

t_image				*new_image(int width, int height, int *img);

t_mlx_img			*new_mlx_img(void);

void				destroy_image(t_params *p, void *image, t_image *img);

#endif
