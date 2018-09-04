/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 21:54:50 by cababou           #+#    #+#             */
/*   Updated: 2018/09/02 00:13:45 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_program(t_params *p, int errortype)
{
	if (errortype == 0)
		ft_putendl("Exiting FdF.");
	if (errortype == 1)
		ft_putendl("Memory Error.");
	if (errortype == 2)
		ft_putendl("Failed to initialize MLX");
	if (errortype == 3)
		ft_putendl("Failed to initialize MLX window");
	mlx_destroy_window(p->mlx, p->fdf_window->window);
	free(p->mlx);
	while (1) {}
	exit(errortype);
	return (0);
}

void	start(t_params *params, int argc, char **argv)
{
	make_cos_table(params);
	make_sin_table(params);
	if ((params->fdf_window->line = malloc(sizeof(t_line))) == NULL)
		exit_program(params, 1);
	init_tabs(params, argc, argv);
	if (params->fdf_window->tabs)
	{
		render_top_menu(params);
		if (params->fdf_window->tabs->selected_tab)
		{
			hide_tab(params, params->fdf_window->tabs->selected_tab);
			render_tab(params, params->fdf_window->tabs->selected_tab);
		}
	}
}

void	make_hooks(void *mlx, t_window *fdf_window, t_params *hook_params)
{
	mlx_loop_hook(mlx, loop, hook_params);
	mlx_do_key_autorepeaton(mlx);
	mlx_hook(fdf_window->window,
		KeyPress, KeyPressMask, key_pressed, hook_params);
	mlx_hook(fdf_window->window,
		ButtonPress, ButtonPressMask, mouse_pressed, hook_params);
	mlx_hook(fdf_window->window,
		ButtonRelease, ButtonReleaseMask, mouse_released, hook_params);
	mlx_hook(fdf_window->window,
		DestroyNotify, NoEventMask, exit_program, NULL);
	mlx_hook(fdf_window->window,
		MotionNotify, PointerMotionMask, mouse_motion, hook_params);
	mlx_hook(fdf_window->window, Expose, ExposureMask, redraw, hook_params);
}

int		main(int argc, char **argv)
{
	void		*mlx;
	t_window	*fdf_window;
	t_params	*hook_params;

	mlx = NULL;
	fdf_window = NULL;
	mlx = init_graphics(NULL);
	if (argc < 2)
		show_error_window(NULL, mlx, 100,
		"Argument missing when launching the program");
	else
	{
		fdf_window = create_window_struct(NULL, 1366, 768, "FdF - cababou");
		fdf_window->window = NULL;
		init_window(NULL, mlx, fdf_window);
		if ((hook_params = malloc(sizeof(t_params))) == NULL)
			exit_program(hook_params, 1);
		hook_params->next_indentifier = 6000;
		hook_params->mlx = mlx;
		hook_params->fdf_window = fdf_window;
		start(hook_params, argc, argv);
		make_hooks(mlx, fdf_window, hook_params);
		mlx_loop(mlx);
	}
	return (0);
}
