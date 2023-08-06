/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shape_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 03:48:43 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/19 03:52:59 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_ray	get_sphere_ray(t_sp *sp, t_ray *normal)
{
	normal->orig = sp->center;
	normal->dir = normalized(vec_minus(normal->orig, sp->center));
	return (*normal);
}

t_ray	get_plane_ray(t_pl *pl, t_ray *normal)
{
	normal->orig = pl->pos;
	normal->dir = pl->dir;
	return (*normal);
}

t_ray	get_square_ray(t_sq *sq, t_ray *normal)
{
	normal->orig = sq->pos;
	normal->dir = normalized(sq->dir);
	return (*normal);
}

t_ray	get_cylinder_ray(t_cy *cy, t_ray *normal)
{
	normal->orig = cy->pos;
	normal->dir = normalized(vec_minus(normal->orig, cy->pos));
	return (*normal);
}

t_ray	get_disk_ray(t_di *di, t_ray *normal)
{
	normal->orig = di->pos;
	normal->dir = normalized(vec_minus(normal->orig, di->pos));
	return (*normal);
}
