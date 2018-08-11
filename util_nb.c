/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_nb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 04:25:25 by cababou           #+#    #+#             */
/*   Updated: 2018/08/11 02:38:42 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double			to_radians(int degrees)
{
	return (degrees * (M_PI / 180.0));
}

int		remaining_to_render(t_lstcontainer *dlines)
{
	t_list	*element;
	t_dline	*dline;
	int		remainings;

	element = dlines->firstelement;
	remainings = 0;
	while (element)
	{
		dline = (t_dline *)element->content;
		if (!dline->is_rendered)
			remainings++;
		element = element->next;
	}
	return (remainings);
}

int		highest_z(t_point *start, t_point *end)
{
	return (start->z > end->z ? start->z : end->z);
}
