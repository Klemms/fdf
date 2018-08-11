/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 16:09:01 by cababou           #+#    #+#             */
/*   Updated: 2018/08/05 23:07:25 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	*two_d_to_iso(t_point *point, int factor)
{
	return (new_fpt(point->x - point->y, (point->x + point->y) / factor, point->z));
}

t_point	*two_d_to_three_d(t_point *point, int angle_1, int angle_2)
{
	return (new_fpt((cosl(to_radians(angle_1)) * point->x) - (sinl(to_radians(angle_1)) * point->y),
		((-sinl(to_radians(angle_1))) * sinl(to_radians(angle_2)) * point->x) - (cosl(to_radians(angle_1)) * sinl(to_radians(angle_2))
		* point->y) + (cosl(to_radians(angle_2)) * point->z), point->z));
}

t_point	*two_d_to_three_d_2(t_point *point, int angle_1)
{
	return (new_fpt((sqrt(2) / 2) * (point->x - point->y),
		(-(sqrt(2) / 2)) * sin(to_radians(angle_1)) * (point->x + point->y) + cos(to_radians(angle_1) * point->z), point->z));
}
