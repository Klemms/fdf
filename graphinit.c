/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 21:56:22 by cababou           #+#    #+#             */
/*   Updated: 2018/07/10 00:40:18 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*init_graphics(void)
{
	void	*mlx;

	mlx = mlx_init();
	return (mlx);
}

void	init_window(void *mlx, t_window *window)
{
	window->window = mlx_new_window(
		mlx,
		window->width,
		window->height,
		window->title);
	init_tabs(window);
}
