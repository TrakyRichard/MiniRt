/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   does_shape_intersect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:24:51 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/19 04:13:51 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_b does_sphere_intersect(t_ray *r, t_sp *sp)
{
	t_vec3 sub;
	double a;
	double b;
	double c;
	double discriminant;
	double t1;
	double t2;

	sub = vec_minus(r->orig, sp->center);
	a = vec_dot(r->dir, r->dir);
	b = 2 * vec_dot(r->dir, sub);
	c = vec_dot(sub, sub) - sp->radius * sp->radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (false);
	t1 = (-b + sqrt(discriminant)) / (2 * a);
	if (t1 > RAY_T_MIN && t1 < r->t)
		return (true);
	t2 = (-b - sqrt(discriminant)) / (2 * a);
	if (t2 > RAY_T_MIN && t2 < r->t)
		return (true);
	return (false);
}

t_b does_plane_intersect(t_ray *r, t_pl *pl)
{
	double dDotN;
	t_vec3 sub;

	dDotN = vec_dot(r->dir, pl->dir);

	if (dDotN == 0)
		return (false);
	else
	{
		double t;

		sub = vec_minus(pl->pos, r->orig);
		t = vec_dot(sub, pl->dir) / dDotN;
		if (t <= RAY_T_MIN || t >= r->t)
			return (false);
		else
			return (true);
	}
}

t_b does_square_intersect(t_ray *r)
{
	(void)r;
	return (false);
}

t_b does_cylinder_intersect(t_ray *r)
{
	(void)r;
	return (false);
}

t_b does_triangle_intersect(t_ray *r)
{
	(void)r;
	return (false);
}

t_b does_disk_intersect(t_ray *r)
{
	(void)r;
	return (false);
}
