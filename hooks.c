/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 04:22:34 by cababou           #+#    #+#             */
/*   Updated: 2018/07/13 01:25:12 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		loop(t_loop_params *p)
{
	//mlx_clear_window(p->mlx, p->fdf_window->window);
	return (0);
}

int		mouse_clicked(int button, int x, int y, t_loop_params *p)
{
	printf("%d # %d :: %d\n", button, x, y);
	if (button == 1)
	{
		p->fdf_window->x1line = x;
		p->fdf_window->y1line = y;
	}
	if (button == 2)
	{
		p->fdf_window->x2line = x;
		p->fdf_window->y2line = y;
		line(p, new_point(p->fdf_window->x1line, p->fdf_window->y1line, 0),
			new_point(p->fdf_window->x2line, p->fdf_window->y2line, 0),
			16711680);
	}
	return (0);
}

int		key_pressed(int key, t_loop_params *p)
{
	printf("%d", key);
	return (0);
}
