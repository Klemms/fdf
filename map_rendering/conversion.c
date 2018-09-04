/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 16:09:01 by cababou           #+#    #+#             */
/*   Updated: 2018/09/03 01:41:14 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	*two_d_to_iso(t_params *p, t_point *point, int factor)
{
	return (new_fpt(p, point->x - point->y, (point->x + point->y) / factor, point->z));
}

t_point	*two_d_to_three_d(t_params *p, t_point *point, int angle_1, int angle_2)
{
	int x;
	int y;

	x = point->x;
	y = point->y;
	point->x = (p->fdf_window->cos_table[constrain_angle(angle_1)] * x) - (p->fdf_window->sin_table[constrain_angle(angle_1)] * y);
	point->y = ((-p->fdf_window->sin_table[constrain_angle(angle_1)]) * p->fdf_window->sin_table[constrain_angle(angle_2)] * x) - (p->fdf_window->cos_table[constrain_angle(angle_1)] * p->fdf_window->sin_table[constrain_angle(angle_2)] * y) + (p->fdf_window->cos_table[constrain_angle(angle_2)] * point->z);
	return (point);
}

t_point	*two_d_to_three_d_2(t_params *p, t_point *point, int angle_1)
{
	return (new_fpt(p, (sqrt(2) / 2) * (point->x - point->y),
		(-(sqrt(2) / 2)) * sin(to_radians(angle_1)) * (point->x + point->y) + cos(to_radians(angle_1) * point->z), point->z));
}
