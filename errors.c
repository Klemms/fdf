/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 22:36:38 by cababou           #+#    #+#             */
/*   Updated: 2018/07/26 20:57:43 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	show_error_window(void *mlx, int error_type, void *content)
{
	t_window	*window;

	window = create_window_struct(750, 75, "Error");
	init_window(mlx, window);
	fill_window(mlx, window, 9868950);
	if (error_type == 100)
		mlx_string_put(mlx, window->window, 25, 25, 16777215, (char *)content);
	else
		mlx_string_put(mlx, window->window, 10, 10, 16777215,
			"An unknown error occured");
	mlx_loop(mlx);
}
