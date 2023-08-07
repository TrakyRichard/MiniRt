/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_intersections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:40:23 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/07 01:35:04 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../color/col.h"
#include "../ray/ray.h"
#include "../shape/shape.h"
#include "../vec/vec.h"
#include "intersection.h"

void	init_sphere_intx(t_sp_intx *el, t_intx *intx, t_sp *sp)
{
	el->oc = vec_minus(intx->ray.orig, sp->center);
	el->a = vec_dot(intx->ray.dir, intx->ray.dir);
	el->b = 2.0 * vec_dot(intx->ray.dir, el->oc);
	el->c = vec_dot(el->oc, el->oc) - (sp->radius * sp->radius);
	el->discriminant = (el->b * el->b) - (4 * el->a * el->c);
	el->t1 = INFINITY;
	el->t2 = INFINITY;
}

void	init_square_intx(t_sq_intx *el, t_intx *intx, t_sq *sq, int level)
{
	if (level == 1)
		el->t = vec_dot(vec_minus(sq->pos, intx->ray.orig), sq->dir) \
		/ vec_dot(intx->ray.dir, sq->dir);
	if (level == 2)
	{
		el->p = vec_add(intx->ray.orig, vec_scale(intx->ray.dir, el->t));
		el->v1 = vec_minus(sq->pos, vec_scale(sq->dir, sq->side_size / 2));
		el->v2 = vec_add(sq->pos, vec_scale(sq->dir, sq->side_size / 2));
		el->v3 = vec_add(sq->pos, vec_scale(vec_cross(sq->dir, sq->dir), \
		sq->side_size));
		el->v4 = vec_minus(sq->pos, vec_scale(vec_cross(sq->dir, sq->dir), \
		sq->side_size));
	}
}

void	init_cylinder_intx(t_cy_intx *el, t_intx *intx, t_cy *cy, int level)
{
	if (level == 1)
	{
		el->oc = vec_minus(intx->ray.orig, cy->pos);
		el->a = vec_dot(intx->ray.dir, intx->ray.dir) - vec_dot(intx->ray.dir, \
		cy->dir) * vec_dot(intx->ray.dir, cy->dir);
		el->b = 2 * (vec_dot(el->oc, intx->ray.dir) - vec_dot(el->oc, cy->dir) \
		* vec_dot(intx->ray.dir, cy->dir));
		el->c = vec_dot(el->oc, el->oc) - vec_dot(el->oc, cy->dir) \
		* vec_dot(el->oc, cy->dir) - cy->radius * cy->radius;
		el->discriminant = el->b * el->b - 4 * el->a * el->c;
	}
	if (level == 2)
	{
		el->t1 = (-el->b - sqrt(el->discriminant)) / (2 * el->a);
		el->t2 = (-el->b + sqrt(el->discriminant)) / (2 * el->a);
	}
	if (level == 3)
	{
		el->p = vec_add(intx->ray.orig, vec_scale(intx->ray.dir, el->t));
		el->op = vec_minus(el->p, cy->pos);
		el->height = vec_dot(el->op, cy->dir);
	}
}

void	init_disk_intx(t_di_intx *el, t_intx *intx, t_di *di, int level)
{
	if (level == 1)
	{
		el->oc = vec_minus(intx->ray.orig, di->pos);
		el->t = vec_dot(el->oc, di->dir) / vec_dot(intx->ray.dir, di->dir);
	}
	if (level == 2)
	{
		el->p = vec_add(intx->ray.orig, vec_scale(intx->ray.dir, el->t));
		el->op = vec_minus(el->p, di->pos);
		el->dist_squared = vec_dot(el->op, el->op);
	}
}

void	init_triangle_intx(t_tr_intx *el, t_intx *intx, t_tr *tr, int level)
{
	if (level == 1)
	{
		el->edge1 = vec_minus(tr->pos2, tr->pos1);
		el->edge2 = vec_minus(tr->pos3, tr->pos1);
		el->pvec = vec_cross(intx->ray.dir, el->edge2);
		el->det = vec_dot(el->edge1, el->pvec);
	}
	if (level == 2)
	{
		el->inv_det = 1.0 / el->det;
		el->tvec = vec_minus(intx->ray.orig, tr->pos1);
		el->u = vec_dot(el->tvec, el->pvec) * el->inv_det;
	}
	if (level == 3)
	{
		el->qvec = vec_cross(el->tvec, el->edge1);
		el->v = vec_dot(intx->ray.dir, el->qvec) * el->inv_det;
	}
	if (level == 4)
		el->t = vec_dot(el->edge2, el->qvec) * el->inv_det;
}
