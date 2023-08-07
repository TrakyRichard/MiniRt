/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 03:55:06 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/07 02:17:32 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../vec/vec.h"
#include "../intersection/intersection.h"
#include "../color/col.h"
#include "../ray/ray.h"

void	adding_albedo(t_manage_light *el, t_b in_shadow, \
t_rgb *color, t_sc *scene)
{
	if (in_shadow)
		el->diffuse = set_col(0, 0, 0);
	else
		el->diffuse = col_multi_with_d(el->diffuse, ALBEDO);
	*color = mult_rgb_rgb(add_rgb_rgb(scene->a.color, el->diffuse), *color);
	min_rgb(color);
}

void	check_if_shape_in_shadow(t_intx *intx, t_b *in_shadow, \
t_intx *shadow_intx, t_sh *shapes)
{
	while (shapes)
	{
		if (shapes->i != intx->i && intersect_shape(shadow_intx, shapes))
		{
			*in_shadow = true;
			break ;
		}
		shapes = shapes->next;
	}
}

void	additional_computation_for_shadow(t_manage_light *el, \
t_intx *intx, t_b in_shadow)
{
	if (!in_shadow)
	{
		el->normal_dot_light = ft_max_float(vec_dot(get_shape_dir(intx), \
		el->to_light.dir), 0.0) / (distance(get_shape_org(intx), \
		el->light->pos) * (distance(get_shape_org(intx), \
		el->light->pos)));
		el->color_l = col_multi_with_d(el->light->color, el->normal_dot_light);
		el->diffuse = add_rgb_rgb(el->diffuse, el->color_l);
	}
	return ;
}

void	ft_put_pixel(unsigned char *data, t_r pt, \
const int color, const t_r resolution)
{
	int	*tab;

	tab = (int *)data;
	tab[pt.h * resolution.w + pt.w] = color;
}

t_rgb	*manage_light(t_sc *scene, t_intx *intx, t_rgb *color)
{
	t_manage_light	el;
	t_b				in_shadow;
	t_sh			*shapes;
	t_intx			shadow_intx;

	in_shadow = false;
	shapes = scene->shapes.head;
	el.diffuse = set_col(0, 0, 0);
	el.lights = scene->l.head;
	while (el.lights)
	{
		el.light = (t_l *)(el.lights->i);
		set_ray(&el.to_light, vec_minus(el.light->pos, get_shape_org(intx)), \
			get_shape_org(intx), INFINITY);
		check_if_shape_in_shadow(intx, &in_shadow, &shadow_intx, shapes);
		additional_computation_for_shadow(&el, intx, in_shadow);
		el.lights = el.lights->next;
	}
	adding_albedo(&el, in_shadow, color, scene);
	return (color);
}
