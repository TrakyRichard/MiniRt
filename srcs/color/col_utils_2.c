/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:34:31 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/07 01:12:37 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "./col.h"

t_rgb	mult_rgb_rgb(const t_rgb rgb, const t_rgb mult)
{
	return (set_col(rgb.r * (mult.r / 255.), \
	rgb.g * (mult.g / 255.), rgb.b * (mult.b / 255.)));
}

t_put_color	set_put_color(double min_t, int width, int height)
{
	t_put_color	pc;

	pc.min_t = min_t;
	pc.x = width;
	pc.y = height;
	return (pc);
}
