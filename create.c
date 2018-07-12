/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 23:04:16 by cababou           #+#    #+#             */
/*   Updated: 2018/07/13 01:17:31 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_window	*create_window_struct(int width, int height, char *title)
{
	t_window	*window;

	if ((window = malloc(sizeof(t_window))) == NULL)
		exit_program(1);
	window->width = width;
	window->height = height;
	window->title = title;
	return (window);
}
