/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 22:58:58 by cababou           #+#    #+#             */
/*   Updated: 2018/08/14 04:58:19 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	*rotate(t_point *point, int x_rot, int y_rot, int z_rot)
{
	return (z_rotation(y_rotation(x_rotation(point, x_rot), y_rot), z_rot));
}

t_point	*x_rotation(t_point *point, int angle)
{
	int y;

	y = point->y;
	point->y = y * cos(to_radians(angle)) - point->z * sin(to_radians(angle));
	point->z = y * sin(to_radians(angle)) + point->z * cos(to_radians(angle));
	return (point);
	/*return (new_fpt(
		point->x,
		point->y * cos(to_radians(angle)) - point->z * sin(to_radians(angle)),
		point->y * sin(to_radians(angle)) + point->z * cos(to_radians(angle))));*/
}

t_point	*y_rotation(t_point *point, int angle)
{
	int x;

	x = point->x;
	point->x = point->z * sin(to_radians(angle)) + x * cos(to_radians(angle));
	point->z = point->z * cos(to_radians(angle)) - x * sin(to_radians(angle));
	return (point);
	/*return (new_fpt(
		point->z * sin(to_radians(angle)) + point->x * cos(to_radians(angle)),
		point->y,
		point->z * cos(to_radians(angle)) - point->x * sin(to_radians(angle))));*/
}

t_point	*z_rotation(t_point *point, int angle)
{
	int x;

	x = point->x;
	point->x = x * cos(to_radians(angle)) - point->y * sin(to_radians(angle));
	point->y = x * sin(to_radians(angle)) + point->y * sin(to_radians(angle));
	return (point);
	/*return (new_fpt(
		point->x * cos(to_radians(angle)) - point->y * sin(to_radians(angle)),
		point->x * sin(to_radians(angle)) + point->y * sin(to_radians(angle)),
		point->z));*/
}
