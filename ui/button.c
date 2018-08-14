/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 00:48:06 by cababou           #+#    #+#             */
/*   Updated: 2018/08/11 04:40:34 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_button	*create_button(char *text, t_point *loc, t_point *size, t_point *co)
{
	t_button *button;

	if ((button = malloc(sizeof(t_button))) == NULL)
		exit_program(1);
	button->button_text = text;
	button->location = loc;
	button->size = size;
	button->color = co->x;
	button->text_color = co->y;
	button->is_visible = 1;
	button->status = 0;
	return (button);
}

void		make_button(t_params *p, t_button *button, t_lstcontainer *cnt,
			int (*callback)(t_button *button, t_point *click_loc, int click))
{
	button->click_callback = callback;
	button->identifier = p->next_indentifier++;
	lstcontainer_add(cnt, button);
}

void		render_button(t_params *p, t_button *b)
{
	fill_rect(p, b->location, b->size, b->color);
	mlx_string_put(p->mlx, p->fdf_window->window,
	b->location->x + b->size->x / 2 - textsize(b->button_text) / 2,
	b->location->y + 15, b->text_color, b->button_text);
}