/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 23:04:16 by cababou           #+#    #+#             */
/*   Updated: 2018/02/08 23:14:34 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_window	*create_window_struct(int width, int height, char *title)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	if (window == NULL)
		exit_program(1);
	window->width = width;
	window->height = height;
	window->title = title;
	return (window);
}
