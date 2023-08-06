/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:20:44 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/12 19:11:50 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COL_H
# define COL_H

# include "../minirt.h"
/* Color */
void	init_col(t_rgb *vec3);
t_rgb	col_addition(t_rgb *u, t_rgb *v);
t_rgb	col_multi(t_rgb *u, t_rgb *v);
t_rgb	col_div(t_rgb vec, double t);
t_rgb	col_minus(t_rgb *u, t_rgb *v);
int	col_len_squared(t_rgb *vec);
int	rgb_length(t_rgb *vec);
t_rgb	col_multi_with_d(t_rgb vec, double t);
t_rgb	set_col(int x, int y, int z);
int	col_dot(const t_rgb *u, const t_rgb *v);
t_rgb	col_cross(const t_rgb *u, const t_rgb *v);
t_rgb mult_rgb_rgb(const t_rgb rgb, const t_rgb mult);
void put_color(t_sc scene, t_intx intersection, double min_t, int x, int y);

#endif
