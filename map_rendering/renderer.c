/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 15:09:55 by cababou           #+#    #+#             */
/*   Updated: 2018/08/14 05:08:31 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

#include <time.h>

int		get_color_height(t_point *point)
{
	if (point->z >= -1 && point->z < 2)
		return (rgba_to_int(41, 188, 114, 0));
	if (point->z >= 2 && point->z < 5)
		return (rgba_to_int(41, 114, 188, 0));
	if (point->z >= 5 && point->z < 8)
		return (rgba_to_int(41, 41, 188, 0));
	if (point->z >= 8 && point->z < 11)
		return (rgba_to_int(188, 41, 188, 0));
	if (point->z >= 11 && point->z < 14)
		return (rgba_to_int(188, 41, 41, 0));
	return (rgba_to_int(255, 255, 255, 0));
}

void	zoom_map(t_params *p, int factor)
{
	if (factor != 0)
	{
		p->fdf_window->tabs->selected_tab->map_settings->size += factor;
		hide_tab(p, p->fdf_window->tabs->selected_tab);
		render_tab(p, p->fdf_window->tabs->selected_tab);
	}
}

void	render_map(t_params *p, t_tab *tab, int render_type)
{
	t_list			*element;
	t_dline			*dl;
	t_map_settings	*ms;
	t_image			*image;
	t_mlx_img		*mlx_img;

	


	element = tab->lines->firstelement;
	ms = tab->map_settings;
	tab->map_image = mlx_new_image(p->mlx, p->fdf_window->width, p->fdf_window->height - 65);
	mlx_img = new_mlx_img();
	image = new_image(p->fdf_window->width, p->fdf_window->height - 65,
		(int *)mlx_get_data_addr(tab->map_image, &mlx_img->bits_per_pixel,
		&mlx_img->size_line, &mlx_img->endian));

	
	/*clock_t start = clock(), diff;*/
	while (element)
	{
		dl = (t_dline *)element->content;
		line(p, image,
		add_fpt(two_d_to_three_d(rotate(
		new_fpt((dl->start->x - ms->max_x / 2) * ms->size,
			(dl->start->y - ms->max_y / 2) * ms->size,
			1 * dl->start->z * ms->size), ms->rot_x, ms->rot_y, ms->rot_z),
			ms->angle_1, ms->angle_2), ms->x_position, ms->y_position, 0),
		add_fpt(two_d_to_three_d(rotate(
		new_fpt((dl->end->x - ms->max_x / 2) * ms->size,
			(dl->end->y - ms->max_y / 2) * ms->size,
			1 * dl->end->z * ms->size), ms->rot_x, ms->rot_y, ms->rot_z),
			ms->angle_1, ms->angle_2), ms->x_position, ms->y_position, 0),
		get_color_height(dl->end));
		element = element->next;
	}
	/*diff = clock() - start;
	long msec = diff * 1000000 / CLOCKS_PER_SEC;
	printf("Time taken %lu\n", msec);
	fflush(stdout);*/

	mlx_put_image_to_window(p->mlx, p->fdf_window->window, tab->map_image, 0, 65);
	destroy_image(p, tab->map_image, image);

	/*free(dl->start);
	free(dl->end);
	free(dl);*/

}
