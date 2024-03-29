/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 05:01:52 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/24 19:08:10 by rkanmado         ###   ########.fr       */
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


