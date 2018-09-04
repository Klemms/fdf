/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 15:09:55 by cababou           #+#    #+#             */
/*   Updated: 2018/09/04 04:05:01 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		get_color_height(t_point *start, t_point *end)
{
	if ((start->z >= -1 && start->z < 2) || (end->z >= -1 && end->z < 2))
		return (rgba_to_int(41, 188, 114, 0));
	if ((start->z >= 2 && start->z < 5) || (end->z >= 2 && end->z < 5))
		return (rgba_to_int(41, 114, 188, 0));
	if ((start->z >= 5 && start->z < 8) || (end->z >= 5 && end->z < 8))
		return (rgba_to_int(41, 41, 188, 0));
	if ((start->z >= 8 && start->z < 11) || (end->z >= 8 && end->z < 11))
		return (rgba_to_int(188, 41, 188, 0));
	if ((start->z >= 11 && start->z < 14) || (end->z >= 11 && end->z < 14))
		return (rgba_to_int(188, 41, 41, 0));
	return (rgba_to_int(255, 255, 255, 0));
}

void	zoom_map(t_params *p, int factor)
{
	if (factor != 0)
	{
		p->fdf_window->tabs->selected_tab->map_settings->size += factor;
		hide_tab(p, p->fdf_window->tabs->selected_tab);
		render_tab(p, p->fdf_window->tabs->selected_tab);
	}
}

void	render_map(t_params *p, t_tab *tab)
{
	t_list			*element;
	t_dline			*dl;
	t_map_settings	*ms;
	t_image			*image;
	t_mlx_img		*mlx_img;

	element = tab->lines->firstelement;
	ms = tab->map_settings;
	tab->map_image = mlx_new_image(p->mlx, p->fdf_window->width, p->fdf_window->height - 65);
	mlx_img = new_mlx_img(p);
	image = new_image(p, p->fdf_window->width, p->fdf_window->height - 65,
		(unsigned int *)mlx_get_data_addr(tab->map_image, &mlx_img->bits_per_pixel,
		&mlx_img->size_line, &mlx_img->endian));
	while (element)
	{
		dl = (t_dline *)element->content;
		init_line(p,
		add_fpt(two_d_to_three_d(p, rotate(p,
			set_point_color(
			set_point(tab->render_p1, (dl->start->x - ms->max_x / 2) * ms->size,
			(dl->start->y - ms->max_y / 2) * ms->size,
			1 * dl->start->z * ms->size), dl->start->color),
			set_point(tab->render_rot, ms->rot_x, ms->rot_y, ms->rot_z)),
			ms->angle_1, ms->angle_2), ms->x_position, ms->y_position, 0),
		add_fpt(two_d_to_three_d(p, rotate(p,
			set_point_color(
			set_point(tab->render_p2, (dl->end->x - ms->max_x / 2) * ms->size,
			(dl->end->y - ms->max_y / 2) * ms->size,
			1 * dl->end->z * ms->size), dl->end->color),
			set_point(tab->render_rot, ms->rot_x, ms->rot_y, ms->rot_z)),
			ms->angle_1, ms->angle_2), ms->x_position, ms->y_position, 0),
		get_color_height(dl->start, dl->end));
		line(p, image);
		element = element->next;
	}

	mlx_put_image_to_window(p->mlx, p->fdf_window->window, tab->map_image, 0, 65);
	destroy_image(p, tab->map_image, image);
	free(mlx_img);
}
