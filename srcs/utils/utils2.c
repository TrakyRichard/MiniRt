/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 04:48:20 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/19 04:48:23 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	ft_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

float	ft_max_float(const float a, const float b)
{
	if (a > b)
		return (a);
	return (b);
}

t_rgb	add_rgb_rgb(const t_rgb rgb, const t_rgb add)
{
	return (set_col(rgb.r + add.r, rgb.g + add.g, rgb.b + add.b));
}

void	min_rgb(t_rgb *color)
{
	color->r = ft_min_int(color->r, 255);
	color->g = ft_min_int(color->g, 255);
	color->b = ft_min_int(color->b, 255);
}
