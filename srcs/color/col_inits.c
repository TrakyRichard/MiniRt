/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_inits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:47:19 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/06 09:23:22 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

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