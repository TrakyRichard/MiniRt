/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   does_shape_intersect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:24:51 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/07 01:38:54 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../vec/vec.h"
#include "../intersection/intersection.h"
#include "../ray/ray.h"

t_b	does_sphere_intersect(t_ray *r, t_sp *sp)
{
	(void)r;
	(void)sp;
	return (false);
}

t_b	does_plane_intersect(t_ray *r, t_pl *pl)
{
	(void)r;
	(void)pl;
	return (false);
}

t_b	does_square_intersect(t_ray *r)
{
	(void)r;
	return (false);
}

t_b	does_cylinder_intersect(t_ray *r)
{
	(void)r;
	return (false);
}

t_b	does_triangle_intersect(t_ray *r)
{
	(void)r;
	return (false);
}
