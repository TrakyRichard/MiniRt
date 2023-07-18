/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 05:01:52 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/12 19:10:10 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb col_minus(t_rgb *u, t_rgb *v)
{
	t_rgb col;

	col.r = u->r - v->r;
	col.b = u->b - v->b;
	col.g = u->g - v->g;
	return (col);
}

t_rgb col_addition(t_rgb *u, t_rgb *v)
{
	t_rgb col;

	col.r = u->r + v->r;
	col.b = u->b + v->b;
	col.g = u->g + v->g;
	return (col);
}

t_rgb col_multi(t_rgb *u, t_rgb *v)
{
	t_rgb col;

	col.r = u->r * v->r;
	col.b = u->b * v->b;
	col.g = u->g * v->g;
	return (col);
}

t_rgb col_multi_with_d(t_rgb col, double t)
{
	col.r *= t;
	col.g *= t;
	col.b *= t;
	return (col);
}

t_rgb col_div(t_rgb col, double t)
{
	return (col_multi_with_d(col, 1 / t));
}

void put_color(t_sc scene, t_intx intersection, double min_t, int x, int y)
{
	// Calculate the color at the intersection point
	t_rgb color;
	if (min_t < INFINITY)
	{
		color = *manage_light(&scene, &intersection, &intersection.col);
		// color = calculate_color(intersection);
	}
	else
	{
		// Set background color if no intersection found
		color.r = 0;
		color.g = 0;
		color.b = 0;
	}

	// Set the color of the current pixel in the image
	ft_put_pixel(scene.img->data, x, y, rgb_to_int(color), scene.r);
}
