/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_inits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:47:19 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/07 01:45:42 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../render/render.h"

void	init_col(t_rgb *col3)
{
	col3->r = 0;
	col3->g = 0;
	col3->b = 0;
	return ;
}

t_rgb	set_col(int x, int y, int z)
{
	t_rgb	col;

	col.r = x;
	col.g = y;
	col.b = z;
	return (col);
}

void	put_color(t_sc *scene, t_intx intersection, t_put_color col_info)
{
	t_rgb	color;
	t_r		r;

	if (col_info.min_t < INFINITY)
		color = *manage_light(scene, &intersection, &intersection.col);
	else
	{
		color.r = 0;
		color.g = 0;
		color.b = 0;
	}
	r.h = col_info.y;
	r.w = col_info.x;
	ft_put_pixel(scene->img->data, r, \
	rgb_to_int(color), scene->r);
}
