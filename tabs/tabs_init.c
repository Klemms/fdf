/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabs_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 02:44:56 by cababou           #+#    #+#             */
/*   Updated: 2018/09/03 03:16:03 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		tab_button_click(t_params *p, t_button *button, t_point *loc, int click)
{
	t_tab			*tab;
	t_list			*element;

	(void)loc;
	(void)click;
	element = p->fdf_window->tabs->tab_list->firstelement;
	while (element != NULL)
	{
		tab = (t_tab *)element->content;
		if (tab->menu_linked_button == button->identifier)
		{
			hide_tab(p, p->fdf_window->tabs->selected_tab);
			p->fdf_window->tabs->selected_tab = tab;
			render_tab(p, tab);
			return (0);
		}
		element = element->next;
	}
	return (0);
}

void	init_tab_button(t_params *p, t_tab *tab, int tabs)
{
	t_button	*button;

	button = create_button(p, tab->tab_name, new_pt(p, 185 * tabs, 10),
		new_pt(p, rgba_to_int(255, 139, 0, 0), rgba_to_int(135, 0, 114, 0)));
	make_button(p, button, p->fdf_window->tabs->buttons, tab_button_click);
	tab->menu_linked_button = button->identifier;
}

void	init_tabs(t_params *p, int argc, char **argv)
{
	int			i;
	t_tab		*tab;
	char		**temp_array;

	if ((p->fdf_window->tabs = malloc(sizeof(t_tabs))) == NULL ||
		(p->fdf_window->tabs->buttons = lstcontainer_new()) == NULL ||
		(p->fdf_window->tabs->tab_list = lstcontainer_new()) == NULL)
		exit_program(p, 1);
	i = 1;
	while (i < argc)
	{
		if ((tab = malloc(sizeof(t_tab))) == NULL)
			exit_program(p, 1);
		tab->identifier = p->next_indentifier++;
		temp_array = ft_strsplit(argv[i], '/');
		tab->tab_name = ft_strdup(temp_array[strsplit_size(temp_array) - 1]);
		free_strsplit(temp_array);
		tab->point_list = parse_file(p, argv[i]);
		ft_putstr(argv[i]);
		ft_putendl(is_file_valid(tab->point_list) ? " is valid" : " is invalid");
		tab->position = new_pt(p, 0, 66);
		tab->map_settings = make_map_settings(p, tab->point_list);
		tab->size = new_pt(p, p->fdf_window->width, p->fdf_window->height - 65);
		tab->map_image = NULL;
		tab->lines = make_lines(p, tab->point_list);
		tab->render_p1 = new_fpt(p, 0, 0, 0);
		tab->render_p2 = new_fpt(p, 0, 0, 0);
		tab->render_rot = new_fpt(p, 0, 0, 0);
		if ((tab->buttons = lstcontainer_new()) == NULL)
			exit_program(p, 1);
		lstcontainer_add(p->fdf_window->tabs->tab_list, tab);
		init_tab_button(p, tab, i);
		if (i == 1)
			p->fdf_window->tabs->selected_tab = tab;
		i++;
	}
}
