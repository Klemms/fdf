/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:17:02 by cababou           #+#    #+#             */
/*   Updated: 2018/08/11 04:43:12 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "drawline.h"

void			extension_1(t_params *p, t_line *l)
{
	mlx_pixel_put(p->mlx, p->fdf_window->window, l->p2->x, l->p2->y, l->color);
	if (l->dx > 0)
	{
		if ((l->dy = l->p2->y - l->p1->y))
		{
			if (l->dy > 0)
				q1(p, l);
			else
				q2(p, l);
		}
		else
			l1(p, l);
	}
	else
	{
		if ((l->dy = l->p2->y - l->y) != 0)
		{
			if (l->dy > 0)
				q3(p, l);
			else
				q4(p, l);
		}
		else
			l2(p, l);
	}
}

t_lstcontainer	*line(t_params *params, t_point *p1, t_point *p2, int color)
{
	t_line	*l;

	if ((l = malloc(sizeof(t_line))) == NULL)
		exit_program(1);
	lstcontainer_add(l->pixels, new_pixel(p1->x, p1->y, color));
	l->color = color;
	l->p1 = p1;
	l->p2 = p2;
	l->e = l->p2->x - l->p1->x;
	l->dx = l->e * 2;
	l->dy = (l->p2->y - l->p1->y) * 2;
	l->x = l->p1->x;
	l->y = l->p1->y;
	if ((l->dx = l->p2->x - l->p1->x) != 0)
		extension_1(params, l);
	else if (l->dx == 0)
	{
		if ((l->dy = l->p2->y - l->y) != 0)
		{
			if (l->dy > 0)
				l3(params, l);
			else if (l->dy < 0)
				l4(params, l);
		}
	}
}
