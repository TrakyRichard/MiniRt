/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:18:25 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/02/19 12:50:25 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_rgb	*int_to_rgb(const int r, const int g, const int b)
{
	t_rgb	*rgb;

	rgb = malloc(sizeof(*rgb));
	if (rgb == NULL)
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
	return (rgb);
}

t_rgb	char_to_rgb(const char *r, const char *g, const char *b)
{
	t_rgb	rgb;

	rgb.r = ft_atoi(r);
	rgb.g = ft_atoi(g);
	rgb.b = ft_atoi(b);
	return (rgb);
}

int	rgb_to_int(const t_rgb rgb)
{
	return(rgb.r << 16 | rgb.g << 8 | rgb.b);
}

t_rgb	*mult_rgb_rgb(const t_rgb rgb, const t_rgb mult)
{
	double mult_r = mult.r / 255.0;
	double mult_g = mult.g / 255.0;
	double mult_b = mult.b / 255.0;

	return (int_to_rgb(rgb.r * mult_r, rgb.g * mult_g, rgb.b * mult_b));
}

t_rgb	*mult_rgb_double(const t_rgb rgb, const double mult)
{
	return (int_to_rgb(rgb.r * mult, rgb.g * mult, rgb.b * mult));
}

t_rgb	*add_rgb_rgb(const t_rgb rgb, const t_rgb add)
{
	return (int_to_rgb(rgb.r + add.r, rgb.g + add.g, rgb.b + add.b));
}

void	min_rgb(t_rgb *color)
{
	color->r = ft_min_int(color->r, 255);
	color->g = ft_min_int(color->g, 255);
	color->b = ft_min_int(color->b, 255);
}

t_rgb	get_color(const char *type, const void *object)
{
	const t_rgb *color = NULL;

	if (!ft_strcmp(type, "sp"))
		color = &((t_sphere*)object)->color;
	else if (!ft_strcmp(type, "pl"))
		color = &((t_plane*)object)->color;
	else if (!ft_strcmp(type, "cy"))
		color = &((t_cylinder*)object)->color;
	else if (!ft_strcmp(type, "tr"))
		color = &((t_triangle*)object)->color;
	// else if (!ft_strcmp(type, "sq"))
	// 	color = &((t_square*)object)->color;

	if (color == NULL)
		print_err_and_exit("Unknown object type", ERROR);
	return *color;
}
