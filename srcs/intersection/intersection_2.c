/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:02:56 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/19 05:05:21 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec3	position(t_intx intx, double t)
{
	return (ray_at(intx.ray.orig, intx.ray.dir, t));
}

t_b	intersect_shape(t_intx *intx, t_sh *sh)
{
	t_b	intersect;

	intersect = false;
	if (sh->type == SPHERE)
		intersect = sphere_intersect(intx, (t_sp *)sh->i);
	else if (sh->type == PLANE)
		intersect = plane_intersect(intx, (t_pl *)sh->i);
	else if (sh->type == SQUARE)
		intersect = square_intersect(intx, (t_sq *)sh->i);
	else if (sh->type == CYLINDER)
		intersect = cylinder_intersect(intx, (t_cy *)sh->i);
	else if (sh->type == DISK)
		intersect = disk_intersect(intx, (t_di *)sh->i);
	else if (sh->type == TRIANGLE)
		intersect = triangle_intersect(intx, (t_tr *)sh->i);
	return (intersect);
}
