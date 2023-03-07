/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:47:19 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/07 04:51:11 by rkanmado         ###   ########.fr       */
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

t_rgb	set_col(double x, double y, double z)
{
	t_rgb	col;

	col.r = x;
	col.g = y;
	col.b = z;
	return (col);
}
