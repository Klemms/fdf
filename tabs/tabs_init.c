/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabs_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 02:44:56 by cababou           #+#    #+#             */
/*   Updated: 2018/08/14 05:30:54 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		tab_button_click(t_button *button, t_point *loc, int click)
{
	ft_putendl(button->button_text);
	return (0);
}

void	init_tab_button(t_params *p, t_tab *tab, int tabs)
{
	t_button	*button;

	button = create_button(tab->tab_name, new_pt(300, 5), new_pt(180, 55),
		new_pt(rgba_to_int(255, 139, 0, 0), rgba_to_int(135, 0, 114, 0)));
	make_button(p, button, p->fdf_window->tabs->buttons, tab_button_click);
	tab->menu_linked_button = button->identifier;
}

void	init_tabs(t_params *p, int argc, char **argv)
{
	int			i;
	t_list		*element;
	t_tab		*tab;

	if ((p->fdf_window->tabs = malloc(sizeof(t_tabs))) == NULL ||
		(p->fdf_window->tabs->buttons = lstcontainer_new()) == NULL ||
		(p->fdf_window->tabs->tab_list = lstcontainer_new()) == NULL)
		exit_program(1);
	i = 1;
	while (i < argc)
	{
		if ((tab = malloc(sizeof(t_tab))) == NULL)
			exit_program(1);
		tab->identifier = p->next_indentifier++;
		tab->tab_name = ft_strdup(argv[i]);
		tab->point_list = parse_file(argv[i]);
		tab->position = new_pt(0, 66);
		tab->map_settings = make_map_settings(p, tab->point_list);
		tab->size = new_pt(p->fdf_window->width, p->fdf_window->height - 65);
		tab->black_background = fill_img(p, new_pt(p->fdf_window->width,
			p->fdf_window->height - 65), rgba_to_int(25, 25, 25, 0));
		tab->map_image = NULL;
		tab->lines = make_lines(p, tab->point_list);
		if ((tab->buttons = lstcontainer_new()) == NULL)
			exit_program(1);
		lstcontainer_add(p->fdf_window->tabs->tab_list, tab);
		init_tab_button(p, tab, argc - 1);
		if (i == 1)
			p->fdf_window->tabs->selected_tab = tab;
		i++;
	}
}
