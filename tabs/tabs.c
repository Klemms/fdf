/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 00:14:43 by cababou           #+#    #+#             */
/*   Updated: 2018/07/13 01:26:29 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	init_tabs(t_window *window)
{
	if ((window->tabs = malloc(sizeof(t_tabs))) == NULL)
		exit_program(1);
	window->tabs->tab_list = lstcontainer_new();
}

void	render_tabs(t_loop_params *params)
{
	ft_putendl("Rendering Tabs...");
	fill_rect(params, new_point(25, 37, 0), new_point(500, 500, 0), rgba_to_int(255, 0, 0, 1));
}
