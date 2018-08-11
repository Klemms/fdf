/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 15:09:55 by cababou           #+#    #+#             */
/*   Updated: 2018/08/11 02:42:34 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		get_color_height(t_point *point)
{
	if (point->z >= -1 && point->z < 2)
		return (rgba_to_int(41, 188, 114, 0));
	if (point->z >= 2 && point->z < 5)
		return (rgba_to_int(41, 114, 188, 0));
	if (point->z >= 5 && point->z < 8)
		return (rgba_to_int(41, 41, 188, 0));
	if (point->z >= 8 && point->z < 11)
		return (rgba_to_int(188, 41, 188, 0));
	if (point->z >= 11 && point->z < 14)
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

void	render_map(t_params *p, t_tab *tab, int render_type)
{
	t_list			*element;
	t_dline			*dl;
	t_lstcontainer	*lines;
	t_map_settings	*ms;

	lines = make_lines(p, tab->point_list);
	element = lines->firstelement;
	ms = tab->map_settings;
	while (element)
	{
		dl = (t_dline *)element->content;
		line(p,
		add_fpt(two_d_to_three_d(rotate(
		new_fpt((dl->start->x - ms->max_x / 2) * ms->size,
			(dl->start->y - ms->max_y / 2) * ms->size,
			1 * dl->start->z * ms->size), ms->rot_x, ms->rot_y, ms->rot_z),
			ms->angle_1, ms->angle_2), ms->x_position, ms->y_position, 0),
		add_fpt(two_d_to_three_d(rotate(
		new_fpt((dl->end->x - ms->max_x / 2) * ms->size,
			(dl->end->y - ms->max_y / 2) * ms->size,
			1 * dl->end->z * ms->size), ms->rot_x, ms->rot_y, ms->rot_z),
			ms->angle_1, ms->angle_2), ms->x_position, ms->y_position, 0),
		get_color_height(dl->end));
		element = element->next;
	}
}
