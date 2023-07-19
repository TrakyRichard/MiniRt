/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 03:55:06 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/19 04:10:07 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

/**
 * Set the color based on lights, the normal at the
 * intersection point, and any obstacles.
 * @param scene     Pointer to the scene structure
 * @param intx    Pointer to the intx structure containing
 * intersection information
 * @param color     Pointer to the current color
 * @param pixel     Pixel coordinates
 * @return          Pointer to the modified color
 **/

typedef struct s_manage_light
{
	t_sh	*lights;
	t_rgb	diffuse;
	t_rgb	color_l;
	t_l		*light;
	t_ray	to_light;
	double	normal_dot_light;
}	t_manage_light;

t_rgb	*manage_light(const t_sc *scene, t_intx *intx, t_rgb *color)
{
	t_manage_light	el;

	el.diffuse = set_col(0, 0, 0);
	el.lights = scene->l.head;
	while (el.lights)
	{
		el.light = (t_l *)(el.lights->i);
		set_ray(&el.to_light, intx->ray.dir, vec_minus(el.light->pos, \
		intx->ray.orig), INFINITY);
		el.normal_dot_light = ft_max_float(vec_dot(get_shape_ray(intx->i, \
		intx->type).dir, el.to_light.dir), 0.0) / (distance(intx->ray.orig, \
		el.light->pos) * (distance(intx->ray.orig, \
		el.light->pos)));
		el.color_l = col_multi_with_d(el.light->color, el.normal_dot_light);
		el.diffuse = add_rgb_rgb(*color, el.color_l);
		el.lights = el.lights->next;
	}
	el.diffuse = col_multi_with_d(el.diffuse, ALBEDO);
	*color = mult_rgb_rgb(add_rgb_rgb(scene->a.color, el.diffuse), *color);
	min_rgb(color);
	return (color);
}
