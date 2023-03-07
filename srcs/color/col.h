/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:20:44 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/07 04:22:54 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COL_H
# define COL_H

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_rgb;

/* Color */
void	col_init(t_rgb *vec3);
t_rgb	col_addition(t_rgb *u, t_rgb *v);
t_rgb	col_multi(t_rgb *u, t_rgb *v);
t_rgb	col_div(t_rgb *vec, double t);
t_rgb	col_minus(t_rgb *u, t_rgb *v);
double	col_len_squared(t_rgb *vec);
double	length(t_rgb *vec);
t_rgb	col_multi_with_d(t_rgb *vec, double t);
t_rgb	set_col(double x, double y, double z);

#endif
