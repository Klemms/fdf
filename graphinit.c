/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 21:56:22 by cababou           #+#    #+#             */
/*   Updated: 2018/09/02 00:07:19 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		redraw(t_params *p)
{
	(void) p;
	return (1);
}

void	*init_graphics(t_params *p)
{
	void	*mlx;

	if ((mlx = mlx_init()) == NULL)
		exit_program(p, 2);
	return (mlx);
}

void	init_window(t_params *p, void *mlx, t_window *window)
{
	if ((window->window = mlx_new_window(
		mlx,
		window->width,
		window->height,
		window->title)) == NULL)
		exit_program(p, 3);
}
