/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_funcs_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 02:54:26 by cababou           #+#    #+#             */
/*   Updated: 2018/08/14 04:20:31 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	destroy_image(t_params *p, void *image, t_image *img)
{
	mlx_destroy_image(p->mlx, image);
	free(img);
}
