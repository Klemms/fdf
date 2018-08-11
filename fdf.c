/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 21:54:50 by cababou           #+#    #+#             */
/*   Updated: 2018/08/11 04:24:23 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_program(int errortype)
{
	if (errortype == 0)
		ft_putendl("Bye.");
	if (errortype == 1)
		ft_putendl("Memory Error.");
	exit(errortype);
	return (0);
}

void	start(t_params *params, int argc, char **argv)
{
	t_list		*element;

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

int		mouse_motion(int x, int y, t_params *p)
{
	if (p->fdf_window->tabs && p->fdf_window->left_click_pressed)
	{
		p->fdf_window->tabs->selected_tab->map_settings->rot_z +=
			(p->fdf_window->last_x - x) / 2;
		p->fdf_window->tabs->selected_tab->map_settings->rot_x +=
			(p->fdf_window->last_y - y) / 2;
		hide_tab(p, p->fdf_window->tabs->selected_tab);
		render_tab(p, p->fdf_window->tabs->selected_tab);
	}
	p->fdf_window->last_x = x;
	p->fdf_window->last_y = y;
	return (0);
}

void	make_hooks(void *mlx, t_window *fdf_window, t_params *hook_params)
{
	mlx_loop_hook(mlx, loop, hook_params);
	mlx_mouse_hook(fdf_window->window, mouse_clicked, hook_params);
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
}

int		main(int argc, char **argv)
{
	void		*mlx;
	t_window	*fdf_window;
	t_params	*hook_params;

	mlx = init_graphics();
	if (argc < 2)
		show_error_window(mlx, 100,
		"Argument missing when launching the program");
	else
	{
		fdf_window = create_window_struct(1366, 768, "FdF - cababou");
		init_window(mlx, fdf_window);
		if ((hook_params = malloc(sizeof(t_params))) == NULL)
			exit_program(1);
		hook_params->next_indentifier = 6000;
		hook_params->mlx = mlx;
		hook_params->fdf_window = fdf_window;
		make_hooks(mlx, fdf_window, hook_params);
		start(hook_params, argc, argv);
		mlx_loop(mlx);
	}
	return (0);
}
