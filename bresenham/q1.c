/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 22:33:16 by cababou           #+#    #+#             */
/*   Updated: 2018/07/26 14:09:17 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "drawline.h"

void	o1(t_params *params, t_line *l)
{
	l->e = l->dx;
	l->dx = l->e * 2;
	l->dy = l->dy * 2;
	while (1)
	{
		mlx_pixel_put(params->mlx, params->fdf_window->window,
			l->x, l->y, l->color);
		if ((l->x = l->x + 1) == l->p2->x)
			break ;
		if ((l->e = l->e - l->dy) <= 0)
		{
			l->y = l->y + 1;
			l->e = l->e + l->dx;
		}
	}
}

void	o2(t_params *params, t_line *l)
{
	l->e = l->dy;
	l->dy = l->e * 2;
	l->dx = l->dx * 2;
	while (1)
	{
		mlx_pixel_put(params->mlx, params->fdf_window->window,
			l->x, l->y, l->color);
		if ((l->y = l->y + 1) == l->p2->y)
			break ;
		if ((l->e = l->e - l->dx) <= 0)
		{
			l->x = l->x + 1;
			l->e = l->e + l->dy;
		}
	}
}

void	q1(t_params *params, t_line *l)
{
	if (l->dx >= l->dy)
	{
		o1(params, l);
	}
	else
	{
		o2(params, l);
	}
}
