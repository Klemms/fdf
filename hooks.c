/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 04:22:34 by cababou           #+#    #+#             */
/*   Updated: 2018/08/14 05:15:31 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		loop(t_params *p)
{
	if (p->fdf_window->tabs->selected_tab->map_settings->isometric_factor > 0)
	{
		if (p->fdf_window->tabs->selected_tab->map_settings->isometric_factor % 1 == 0)
		{
			p->fdf_window->tabs->selected_tab->map_settings->rot_x++;
			p->fdf_window->tabs->selected_tab->map_settings->rot_y++;
			p->fdf_window->tabs->selected_tab->map_settings->rot_z++;
			hide_tab(p, p->fdf_window->tabs->selected_tab);
			render_tab(p, p->fdf_window->tabs->selected_tab);
		}
		p->fdf_window->tabs->selected_tab->map_settings->isometric_factor++;
	}
	return (0);
}

int		mouse_clicked(int button, int x, int y, t_params *p)
{
	return (0);
}

int		mouse_pressed(int button, int x, int y, t_params *p)
{
	if (button == 4)
		zoom_map(p, 1);
	if (button == 5)
		zoom_map(p, -1);
	printf("PRESS + %d\n", button);
	fflush(stdout);
	if (button == 1 && x > 0 && x < p->fdf_window->width && y > 0 && y < p->fdf_window->height)
		p->fdf_window->left_click_pressed = 1;
	return (0);
}

int		mouse_released(int button, int x, int y, t_params *p)
{
	printf("RELEASE + %d\n", button);
	fflush(stdout);
	if (button == 1)
		p->fdf_window->left_click_pressed = 0;
	button_clicked(button, x, y, p);
	return (0);
}

int		key_pressed(int key, t_params *p)
{
	t_map_settings	*map_settings;

	map_settings = p->fdf_window->tabs->selected_tab->map_settings;
	ft_putstr("Key : ");
	ft_putnbr(key);
	ft_putendl("");
	if (key == 53)
		exit_program(0);
	if (p->fdf_window->tabs->selected_tab)
	{
		if (key == 123)
			map_settings->x_position -= 50;
		if (key == 124)
			map_settings->x_position += 50;
		if (key == 126)
			map_settings->y_position -= 50;
		if (key == 125)
			map_settings->y_position += 50;
		if (key == 69)
			map_settings->isometric_factor++;
		if (key == 78)
			map_settings->isometric_factor--;
		if (key == 35)
			map_settings->isometric_factor *= -1;

		if (key == 89)
			map_settings->rot_x++;
		if (key == 86)
			map_settings->rot_x--;

		if (key == 91)
			map_settings->rot_y++;
		if (key == 87)
			map_settings->rot_y--;

		if (key == 92)
			map_settings->rot_z++;
		if (key == 88)
			map_settings->rot_z--;

		hide_tab(p, p->fdf_window->tabs->selected_tab);
		render_tab(p, p->fdf_window->tabs->selected_tab);
	}

	printf("Pos x:%d y:%d *** Angle x:%d y:%d z:%d\n", map_settings->x_position, map_settings->y_position,
		map_settings->rot_x, map_settings->rot_y, map_settings->rot_z);
		fflush(stdout);

	return (1);
}
