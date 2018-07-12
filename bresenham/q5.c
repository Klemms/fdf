/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q5.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 23:40:57 by cababou           #+#    #+#             */
/*   Updated: 2018/07/09 23:50:14 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "drawline.h"

void	l1(t_loop_params *params, t_line *l)
{
	while ((l->x = l->x + 1) != l->p2->x)
	{
		mlx_pixel_put(params->mlx, params->fdf_window->window,
			l->x, l->y, l->color);
	}
}

void	l2(t_loop_params *params, t_line *l)
{
	while ((l->x = l->x - 1) != l->p2->x)
	{
		mlx_pixel_put(params->mlx, params->fdf_window->window,
			l->x, l->y, l->color);
	}
}

void	l3(t_loop_params *params, t_line *l)
{
	while ((l->y = l->y + 1) != l->p2->y)
	{
		mlx_pixel_put(params->mlx, params->fdf_window->window,
			l->x, l->y, l->color);
	}
}

void	l4(t_loop_params *params, t_line *l)
{
	while ((l->y = l->y - 1) != l->p2->y)
	{
		mlx_pixel_put(params->mlx, params->fdf_window->window,
			l->x, l->y, l->color);
	}
}
