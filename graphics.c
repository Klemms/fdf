/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 23:02:59 by cababou           #+#    #+#             */
/*   Updated: 2018/02/09 20:49:19 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_window(void *mlx, t_window *window, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < window->height)
	{
		x = 0;
		while (x < window->width)
		{
			mlx_pixel_put(mlx, window->window, x, y, color);
			x++;
		}
		y++;
	}
}
