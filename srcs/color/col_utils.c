/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 05:18:38 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/12 19:10:14 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	col_len_squared(t_rgb *col)
{
	return ((col->r * col->r) + (col->g * col->g) + (col->b * col->b));
}

int	rgb_length(t_rgb *col)
{
	return (sqrt(col_len_squared(col)));
}

int	col_dot(const t_rgb *u, const t_rgb *v)
{
	return ((u->r * v->r) + (u->g + v->g) + (u->b + v->b));
}

t_rgb	col_cross(const t_rgb *u, const t_rgb *v)
{
	t_rgb	col;

	col.r = (u->g * v->b) - (u->b * u->g);
	col.g = (u->b * v->r) - (u->r * v->b);
	col.b = (u->r * v->g) - (u->g * v->b);
	return (col);
}

t_rgb	unit_color(t_rgb *col)
{
	return (col_div(*col, rgb_length(col)));
}

t_rgb mult_rgb_rgb(const t_rgb rgb, const t_rgb mult)
{
    return (set_col(rgb.r * (mult.r / 255.), rgb.g * (mult.g / 255.), rgb.b * (mult.b / 255.)));
}