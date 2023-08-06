/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 03:55:06 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/06 09:55:31 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

typedef struct s_manage_light
{
	t_sh	*lights;
	t_rgb	diffuse;
	t_rgb	color_l;
	t_l		*light;
	t_ray	to_light;
	double	normal_dot_light;
}	t_manage_light;

void adding_albedo(t_manage_light *el, t_b in_shadow, t_rgb *color, t_sc *scene)
{
	if (in_shadow)
		el->diffuse = set_col(0, 0, 0);
	else
		el->diffuse = col_multi_with_d(el->diffuse, ALBEDO);
	*color = mult_rgb_rgb(add_rgb_rgb(scene->a.color, el->diffuse), *color);
	min_rgb(color);
}

void check_if_shape_in_shadow(t_intx *intx, t_b *in_shadow, t_intx *shadow_intx, t_sh *shapes)
{
	while (shapes)
	{
		if (shapes->i != intx->i && intersect_shape(shadow_intx, shapes))
		{
			*in_shadow = true;
			break;
		}
		shapes = shapes->next;
	}
}

void additional_computation_for_shadow(t_manage_light *el, t_intx *intx, t_b in_shadow)
{
	if (!in_shadow)
	{
		el->normal_dot_light = ft_max_float(vec_dot(get_shape_dir(intx), el->to_light.dir), 0.0) / (distance(get_shape_org(intx), \
		el->light->pos) * (distance(get_shape_org(intx), \
		el->light->pos)));
		el->color_l = col_multi_with_d(el->light->color, el->normal_dot_light);
		el->diffuse = add_rgb_rgb(el->diffuse, el->color_l);
	}
	return ;
}

void    ft_put_pixel(unsigned char *data, int x, int y, const int color, const t_r resolution)
{
    int(*tab)[resolution.w][1]; // prepare the cast

    tab = (void *)data; // cast for change 1 dimension array to 2 dimensions
    *tab[y][x] = color; // set the pixel at the coord x,y with the color value
}

t_rgb	*manage_light(t_sc *scene, t_intx *intx, t_rgb *color)
{
	t_manage_light	el;
	t_b in_shadow;

	el.diffuse = set_col(0, 0, 0);
	el.lights = scene->l.head;
	while (el.lights)
	{
		el.light = (t_l *)(el.lights->i);
		set_ray(&el.to_light, vec_minus(el.light->pos, \
		get_shape_org(intx)), get_shape_org(intx), INFINITY);
		in_shadow = false;
		t_sh *shapes = scene->shapes.head;
		t_intx shadow_intx;
		check_if_shape_in_shadow(intx, &in_shadow, &shadow_intx, shapes);
		additional_computation_for_shadow(&el, intx, in_shadow);
		el.lights = el.lights->next;
	}
	adding_albedo(&el, in_shadow, color, scene);
	return (color);
}
