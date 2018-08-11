/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 00:14:43 by cababou           #+#    #+#             */
/*   Updated: 2018/08/11 02:54:36 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		button_clicked(int click, int x, int y, t_params *params)
{
	t_list		*element;
	t_button	*button;

	element = params->fdf_window->tabs->buttons->firstelement;
	while (element)
	{
		button = (t_button *)element->content;
		if (button->is_visible)
		{
			if (x >= button->location->x &&
				x <= button->location->x + button->size->x &&
				y >= button->location->y &&
				y <= button->location->y + button->size->y)
				if (button->click_callback(button, new_pt(x, y), click))
					return (0);
		}
		element = element->next;
	}
	return (0);
}

void	render_top_menu(t_params *p)
{
	t_list				*element;
	t_tab				*tab;
	t_button			*button;
	t_top_menu_settings	*top_menu;

	if ((top_menu = malloc(sizeof(t_top_menu_settings))) == NULL)
		exit_program(1);
	fill_rect(p, new_pt(0, 0),
	new_pt(p->fdf_window->width, 65), rgba_to_int(1, 163, 238, 0));
	mlx_string_put(p->mlx, p->fdf_window->window, 18, 21,
	rgba_to_int(135, 0, 114, 0), "FdF - cababou");
	fill_rect(p, new_pt(180, 5), new_pt(
		p->fdf_window->width - 200, 55), rgba_to_int(0, 0, 0, 220));
	element = p->fdf_window->tabs->buttons->firstelement;
	while (element)
	{
		button = (t_button *)element->content;
		render_button(p, button);
		element = element->next;
	}
}
