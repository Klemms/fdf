/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 23:29:48 by cababou           #+#    #+#             */
/*   Updated: 2018/09/04 04:21:23 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				is_file_valid_2(t_lstcontainer *points, t_list *tmp, int x)
{
	int		last_x;

	last_x = -1;
	while (tmp)
	{
		if (((t_point *)tmp->content)->x > x ||
		(last_x < x && ((t_point *)tmp->content)->x <= last_x))
			return (0);
		last_x = ((t_point *)tmp->content)->x;
		if (((t_point *)tmp->content)->x != x && tmp == points->lastelement)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int				is_file_valid(t_lstcontainer *points)
{
	int		x;
	t_list	*tmp;

	if (points == NULL || points->firstelement == NULL)
		return (0);
	x = -1;
	tmp = points->firstelement;
	while (tmp && ((t_point *)tmp->content)->x > x)
	{
		x = ((t_point *)tmp->content)->x;
		tmp = tmp->next;
	}
	if (x == 0)
		return (1);
	tmp = points->firstelement;
	return (is_file_valid_2(points, tmp, x));
}

t_point			*add_color(t_point *p, int color)
{
	p->color = color;
	return (p);
}

void			handle_open_error(t_params *p, char *fp, t_lstcontainer *points)
{
	ft_lstdel(points->firstelement, 1);
	free(points);
	if (errno == EACCES || errno == EFAULT)
	{
		ft_putstr("Couldn't open a file, missing permissions. (");
		ft_putstr(fp);
		ft_putendl(")");
	}
	else
	{
		ft_putstr("Couldn't open a file. (");
		ft_putstr(fp);
		ft_putendl(")");
	}
	exit_program(p, 0);
}

t_lstcontainer	*parse_file(t_params *p, char *filepath)
{
	t_lstcontainer	*points;
	int				fd;
	t_point			*pt;
	char			*tmp;
	t_lstcontainer	*l;

	if ((points = lstcontainer_new()) == NULL)
		exit_program(p, 1);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		handle_open_error(p, filepath, points);
	tmp = NULL;
	pt = new_pt(p, 0, 0);
	while ((pt->z = get_next_line(fd, &tmp)) == 1)
	{
		pt->x = 0;
		if ((l = ft_strsplit_lst(tmp, ' ', '\n', '\0')) == NULL)
			exit_program(p, 1);
		while (pt->x < lstcontainer_fastsize(l))
		{
			lstcontainer_add(points, new_fpt(p, pt->x, pt->y,
			ft_atoi((char *)ft_lstget(pt->x, l->firstelement)->content)));
			((t_point *)points->lastelement->content)->color =
			ft_hex_to_color(
			ft_strsplitone(ft_lstget(pt->x, l->firstelement)->content, ',', 1), 1);
			if (((t_point *)points->lastelement->content)->color == 0)
				((t_point *)points->lastelement->content)->color = rgba_to_int(200, 100, 100, 0);
			pt->x++;
		}
		ft_lstdel(l->firstelement, 1);
		if (lstcontainer_fastsize(l) > 0)
			pt->y++;
		free(l);
		free(tmp);
		tmp = NULL;
	}
	if (pt->z == -1)
	{
		ft_putstr("Couldn't read a file. (");
		ft_putstr(filepath);
		ft_putendl(")");
		exit_program(p, 0);
	}
	free(pt);
	return (points);
}
