/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 15:00:35 by cababou           #+#    #+#             */
/*   Updated: 2018/09/03 03:15:22 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	render_tab(t_params *p, t_tab *tab)
{
	t_list		*element;
	t_button	*button;

	element = tab->buttons->firstelement;
	while (element)
	{
		button = (t_button *)element->content;
		button->is_visible = 1;
		render_button(p, button);
		element = element->next;
	}
	render_map(p, tab);
}

void	hide_tab(t_params *p, t_tab *tab)
{
	t_list		*element;
	t_button	*button;

	element = tab->buttons->firstelement;
	while (element)
	{
		button = (t_button *)element->content;
		button->is_visible = 0;
		element = element->next;
	}
	(void)p;
}
