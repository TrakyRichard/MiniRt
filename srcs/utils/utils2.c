/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 04:48:20 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/07 01:31:16 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../color/col.h"

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

t_rgb	str_to_rgb(char *str)
{
	t_rgb	rgb;
	char	**split;

	split = ft_split(str, ",");
	rgb.r = ft_atoi(split[0]);
	rgb.g = ft_atoi(split[1]);
	rgb.b = ft_atoi(split[2]);
	ft_free_dbpt(split);
	return (rgb);
}
