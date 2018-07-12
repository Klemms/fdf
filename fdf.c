/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 21:54:50 by cababou           #+#    #+#             */
/*   Updated: 2018/07/13 01:25:20 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_program(int errortype)
{
	if (errortype == 1)
		ft_putendl("Memory Error.");
	exit(errortype);
}

void	start(t_loop_params *params)
{
	if (params->fdf_window->tabs)
		render_tabs(params);
}

int		main(int argc, char **argv)
{
	void			*mlx;
	t_window		*fdf_window;
	t_loop_params	*hook_params;

	mlx = init_graphics();
	fdf_window = create_window_struct(1366, 768, "FdF - cababou");
	if (argc < 2)
		show_error_window(mlx, 100,
		"Argument missing when launching the program");
	else
	{
		init_window(mlx, fdf_window);
		hook_params = malloc(sizeof(t_loop_params));
		hook_params->mlx = mlx;
		hook_params->fdf_window = fdf_window;
		mlx_loop_hook(mlx, loop, hook_params);
		mlx_mouse_hook(fdf_window->window, mouse_clicked, hook_params);
		mlx_key_hook(fdf_window->window, key_pressed, hook_params);
		start(hook_params);
		mlx_loop(mlx);
	}
	return (0);
}
