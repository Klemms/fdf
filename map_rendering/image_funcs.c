/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 02:54:26 by cababou           #+#    #+#             */
/*   Updated: 2018/09/03 03:13:51 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_mlx_img	*new_mlx_img(t_params *p)
{
	t_mlx_img	*mlx_img;

	if ((mlx_img = malloc(sizeof(t_mlx_img))) == NULL)
		exit_program(p, 1);
	return (mlx_img);
}

t_image		*new_image(t_params *p, int width, int height, unsigned int *img)
{
	t_image	*image;

	if ((image = malloc(sizeof(t_image))) == NULL)
		exit_program(p, 1);
	image->width = width;
	image->height = height;
	image->image = img;
	return (image);
}

void		write_pxl(t_image *img, int x, int y, int color)
{
	if (x > 0 && x < img->width && y > 0 && y < img->height)
		img->image[x + img->width * y] = color;
}

int			pxl_width(t_lstcontainer *pixels)
{
	t_list	*element;
	t_pixel	*pixel;
	int		min_x;
	int		max_x;

	element = pixels->firstelement;
	min_x = 0;
	max_x = 0;
	while (element)
	{
		pixel = (t_pixel *)element->content;
		min_x = pixel->x < min_x ? pixel->x : min_x;
		max_x = pixel->x > max_x ? pixel->x : max_x;
		element = element->next;
	}
	return (max_x - min_x);
}

int			pxl_height(t_lstcontainer *pixels)
{
	t_list	*element;
	t_pixel	*pixel;
	int		min_y;
	int		max_y;

	element = pixels->firstelement;
	min_y = 0;
	max_y = 0;
	while (element)
	{
		pixel = (t_pixel *)element->content;
		min_y = pixel->y < min_y ? pixel->y : min_y;
		max_y = pixel->y > max_y ? pixel->y : max_y;
		element = element->next;
	}
	return (max_y - min_y);
}
