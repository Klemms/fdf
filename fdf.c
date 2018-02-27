/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 21:54:50 by cababou           #+#    #+#             */
/*   Updated: 2018/02/26 04:21:19 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_program(int errortype)
{
	if (errortype == 1)
		ft_putstr("Memory Error.\n");
	exit(errortype);
}

int		main(int argc, char **argv)
{
	void			*mlx;
	t_window		*fdf_window;
	t_loop_params	*loop_params;

	mlx = init_graphics();
	fdf_window = create_window_struct(1366, 768, "FdF - cababou");
	if (argc < 2)
		show_error_window(mlx, 0,
		"Argument missing when launching the program");
	else
	{
		init_window(mlx, &fdf_window);
	}
	loop_params = malloc(sizeof(t_loop_params));
	loop_params->mlx = mlx;
	loop_params->fdf_window = fdf_window;
	mlx_loop_hook(mlx, loop, loop_params);
	mlx_loop(mlx);
	return (0);
}
