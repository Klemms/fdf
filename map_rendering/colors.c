/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 02:19:42 by cababou           #+#    #+#             */
/*   Updated: 2018/09/04 03:19:04 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		calc_gradient(int color1, int color2, double stage)
{
	int		color;
	int		r;
	int		g;
	int		b;

	r = (int)(((color1 >> 16) & 0xFF) +
			(((color2 >> 16) & 0xFF) - ((color1 >> 16) & 0xFF)) * stage) << 16;
	g = (int)(((color1 >> 8) & 0xFF) +
			(((color2 >> 8) & 0xFF) - ((color1 >> 8) & 0xFF)) * stage) << 8;
	b = (int)((color1 & 0xFF) +
			((color2 & 0xFF) - (color1 & 0xFF)) * stage);
	color = r | g | b;
	return (color);
}
