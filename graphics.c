/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 23:02:59 by cababou           #+#    #+#             */
/*   Updated: 2018/08/11 04:33:56 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	*new_pixel(int x, int y, int color)
{
	t_pixel	*pixel;

	if ((pixel = malloc(sizeof(t_pixel *))) == NULL)
		exit_program(1);
	pixel->point = new_pt(x, y);
	pixel->color = color;
	return (pixel);
}

void	fill_window(void *mlx, t_window *window, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < window->height)
	{
		x = 0;
		while (x < window->width)
		{
			mlx_pixel_put(mlx, window->window, x, y, color);
			x++;
		}
		y++;
	}
}

void	fill_rect(t_params *p, t_point *point, t_point *wh, int c)
{
	int i;
	int x;
	int y;

	i = 0;
	x = point->x;
	y = point->y;
	while (i < wh->x * wh->y)
	{
		mlx_pixel_put(p->mlx, p->fdf_window->window, x, y, c);
		x++;
		if (x >= point->x + wh->x)
		{
			x = point->x;
			y++;
		}
		i++;
	}
}

void	*fill_img(t_params *p, t_point *wh, int c)
{
	void		*image;
	int			*pixels;
	int			i;
	t_mlx_img	*img;

	if ((img = malloc(sizeof(t_mlx_img))) == NULL)
		exit_program(1);
	image = mlx_new_image(p->mlx, wh->x, wh->y);
	pixels = (int *)mlx_get_data_addr(image, &img->bits_per_pixel,
		&img->size_line, &img->endian);
	i = 0;
	while (i < wh->x * wh->y)
	{
		pixels[i] = c;
		i++;
	}
	return (image);
}
