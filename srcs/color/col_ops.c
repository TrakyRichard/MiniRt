/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 05:01:52 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/18 21:24:40 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb	col_minus(t_rgb *u, t_rgb *v)
{
	t_rgb	col;

	col.r = u->r - v->r;
	col.b = u->b - v->b;
	col.g = u->g - v->g;
	return (col);
}

t_rgb	col_addition(t_rgb *u, t_rgb *v)
{
	t_rgb	col;

	col.r = u->r + v->r;
	col.b = u->b + v->b;
	col.g = u->g + v->g;
	return (col);
}

t_rgb	col_multi(t_rgb *u, t_rgb *v)
{
	t_rgb	col;

	col.r = u->r * v->r;
	col.b = u->b * v->b;
	col.g = u->g * v->g;
	return (col);
}

t_rgb	col_multi_with_d(t_rgb col, double t)
{
	col.r *= t;
	col.g *= t;
	col.b *= t;
	return (col);
}

t_rgb	col_div(t_rgb col, double t)
{
	return (col_multi_with_d(col, 1 / t));
}

void put_color(t_sc scene, t_intx intersection, double min_t, int x, int y)
{
	t_rgb	color;
	if (min_t < INFINITY)
		color = *manage_light(&scene, &intersection, &intersection.col);
	else
	{
		color.r = 0;
		color.g = 0;
		color.b = 0;
	}
	ft_put_pixel(scene.img->data, x, y, rgb_to_int(color), scene.r);
}
