/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cababou <cababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 22:40:28 by cababou           #+#    #+#             */
/*   Updated: 2018/07/09 23:42:20 by cababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWLINE_H
# define DRAWLINE_H

typedef struct	s_line
{
	t_point		*p1;
	t_point		*p2;
	int			dx;
	int			dy;
	int			x;
	int			y;
	int			e;
	int			color;
}				t_line;

void			q1(t_loop_params *params, t_line *l);

void			q2(t_loop_params *params, t_line *l);

void			q3(t_loop_params *params, t_line *l);

void			q4(t_loop_params *params, t_line *l);

void			l1(t_loop_params *params, t_line *l);

void			l2(t_loop_params *params, t_line *l);

void			l3(t_loop_params *params, t_line *l);

void			l4(t_loop_params *params, t_line *l);

#endif