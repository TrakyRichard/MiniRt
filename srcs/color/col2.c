/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 05:18:38 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/23 13:25:10 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	col_len_squared(t_rgb *col)
{
	return ((col->r * col->r) + (col->g * col->g) + (col->b * col->b));
}

double	rgb_length(t_rgb *col)
{
	return (sqrt(col_len_squared(col)));
}

double	dot(const t_rgb *u, const t_rgb *v)
{
	return ((u->r * v->r) + (u->g + v->g) + (u->b + v->b));
}

t_rgb	cross(const t_rgb *u, const t_rgb *v)
{
	t_rgb	col;

	col.r = (u->g * v->b) - (u->b * u->g);
	col.g = (u->b * v->r) - (u->r * v->b);
	col.b = (u->r * v->g) - (u->g * v->b);
	return (col);
}

t_rgb	unit_coltor(t_rgb *col)
{
	return (col_div(col, rgb_length(col)));
}
