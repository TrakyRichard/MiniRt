/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:37:57 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 14:04:25 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	cr_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray	rtn;

	rtn.origin = origin;
	rtn.direction = direction;
	return (rtn);
}

t_vec3	ray_on_at(t_ray ray, double t)
{
	return (add(ray.origin, mpv(ray.direction, t)));
}

t_vec3	ray_color(t_gen *gen, t_ray ray)
{
	t_hit	hit;
	t_ray	shadow_r;
	const double SHADOW_AMBIENT_FACTOR = 0.2;
	const double DEFAULT_COLOR_FACTOR = 0.8;

	if (check_intersections(gen->scene, ray, &hit))
	{
		shadow_r = cr_ray(hit.p, unit_vector(sub(gen->light.center, hit.p)));
		if (shadow_ray(gen->light.center, gen->scene, shadow_r, hit.obj) == 0)
		{
			return (add(point_light(gen, &hit, gen->light, hit.color),
					gen->ambient_salt));
		}
		else
		{
			return (point_light(gen, &hit, gen->light, add(mpv(hit.color, SHADOW_AMBIENT_FACTOR),
						gen->ambient_salt)));
		}
	}
	return (mpv(gen->ambient_color, DEFAULT_COLOR_FACTOR));
}
