/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 03:41:14 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/07 05:12:48 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	set_ray(t_ray *ray, t_vec3 dir, t_vec3 orig)
{
	ray->dir = dir;
	ray->orig = orig;
	return ;
}

void	init_ray(t_ray *ray)
{
	vec_init(&ray->dir);
	vec_init(&ray->orig);
	return ;
}

t_vec3	ray_at(t_vec3 *u, t_vec3 *v, double t)
{
	t_vec3	newdir;

	newdir = vec_multi_with_d(v, t);
	return (vec_addition(u, &newdir));
}
