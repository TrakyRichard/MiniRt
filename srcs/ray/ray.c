/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 03:41:14 by rkanmado          #+#    #+#             */
/*   Updated: 2023/06/25 15:26:20 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	set_ray(t_ray *ray, t_vec3 dir, t_vec3 orig, double t)
{
	ray->dir = dir;
	ray->orig = orig;
	ray->t = t;
	return ;
}

t_b are_rays_egal(t_ray ray1, t_ray ray2)
{
	if (are_vecs_egal(ray1.dir, ray2.dir) && are_vecs_egal(ray1.orig, ray2.orig) && ray1.t == ray2.t)
		return (true);
	return (false);
}

void	init_ray(t_ray *ray)
{
	vec_init(&ray->dir);
	vec_init(&ray->orig);
	ray->t = RAY_T_MAX;
	return ;
}

t_vec3	ray_at(t_vec3 orig, t_vec3 dir, double t)
{
	t_vec3	newdir;

	newdir = vec_scale(dir, t);
	return (vec_add(orig, newdir));
}
