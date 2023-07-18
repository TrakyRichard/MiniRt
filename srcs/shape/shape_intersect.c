/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:24:51 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/12 08:05:12 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

// Check if the ray is parallel or nearly parallel to the plane
// Check if the intersection is behind the ray origin or farther than the current intersection
t_b plane_intersect(t_intx *intx, t_pl *pl)
{
    double denom = vec_dot(pl->dir, intx->ray.dir);
    if (fabs(denom) < EPSILON)
        return false;
    double t = vec_dot(vec_minus(pl->pos, intx->ray.orig), pl->dir) / denom;
    if (t < EPSILON || t >= intx->t)
        return false;
    intx->t = t;
    intx->i = pl;
    intx->type = PLANE;
    intx->col = pl->color;
    return (true);
}

// Check if the ray intersects with the sphere
// Check if the intersection is within the valid range and update the intersection details

t_b sphere_intersect(t_intx *intx, t_sp *sp)
{
    t_sp_intx el;

    init_sphere_intx(&el, intx, sp);
    if (el.discriminant < 0)
        return (false);
    else if (el.discriminant == 0)
    {
        el.t1 = -el.b / (2.0 * el.a);
        el.t2 = el.t1;
    }
    else
    {
        el.t1 = (-el.b - sqrt(el.discriminant)) / (2.0 * el.a);
        el.t2 = (-el.b + sqrt(el.discriminant)) / (2.0 * el.c);
    }
    if (el.t1 > EPSILON && el.t1 < intx->t)
        return (set_sphere_intx(intx, sp, el.t1, true));
    else if (el.t2 > EPSILON && el.t2 < intx->t)
        return (set_sphere_intx(intx, sp, el.t2, true));
    return (false);
}

t_b square_intersect(t_intx *intx, t_sq *sq)
{
    t_sq_intx el;

    init_square_intx(&el, intx, sq, 1);
    if (el.t < EPSILON || el.t >= intx->t)
        return (false);
    init_square_intx(&el, intx, sq, 2);
    if (vec_dot(vec_cross(vec_minus(el.v1, el.p), vec_minus(el.v2, el.p)), sq->dir) < 0 ||
        vec_dot(vec_cross(vec_minus(el.v2, el.p), vec_minus(el.v3, el.p)), sq->dir) < 0 ||
        vec_dot(vec_cross(vec_minus(el.v3, el.p), vec_minus(el.v4, el.p)), sq->dir) < 0 ||
        vec_dot(vec_cross(vec_minus(el.v4, el.p), vec_minus(el.v1, el.p)), sq->dir) < 0)
        return (false);
    intx->t = el.t;
    intx->i = sq;
    intx->type = SQUARE;
    intx->col = sq->color;

    return (true);
}

t_b cylinder_intersect(t_intx *intx, t_cy *cy)
{
    t_cy_intx el;

    init_cylinder_intx(&el, intx, cy, 1);
    if (el.discriminant < 0)
        return (false);
    init_cylinder_intx(&el, intx, cy, 2);
    if (el.t1 > EPSILON && el.t1 < intx->t)
        el.t = el.t1;
    else if (el.t2 > EPSILON && el.t2 < intx->t)
        el.t = el.t2;
    else
        return (false);
    init_cylinder_intx(&el, intx, cy, 3);
    if (el.height < 0 || el.height > cy->height)
        return (false);
    intx->t = el.t;
    intx->i = cy;
    intx->type = CYLINDER;
    intx->col = cy->color;
    return (true);
}

/* Intersect triangle with 3 points */
t_b triangle_intersect(t_intx *intx, t_tr *tr)
{
    t_tr_intx el;
    init_triangle_intx(&el, intx, tr, 1);
    if (fabs(el.det) < EPSILON)
        return (false);
    init_triangle_intx(&el, intx, tr, 2);
    if (el.u < 0 || el.u > 1)
        return (false);
    init_triangle_intx(&el, intx, tr, 3);
    if (el.v < 0 || el.u + el.v > 1)
        return (false);
    init_triangle_intx(&el, intx, tr, 4);
    if (el.t < EPSILON || el.t > intx->t)
        return (false);
    intx->t = el.t;
    intx->i = tr;
    intx->type = TRIANGLE;
    intx->col = tr->color;
    return (true);
}

/* Intersect with a disk */
t_b disk_intersect(t_intx *intx, t_di *di)
{
    t_di_intx el;

    init_disk_intx(&el, intx, di, 1);
    if (el.t < EPSILON || el.t > intx->t)
        return false;
    init_disk_intx(&el, intx, di, 2);

    if (el.dist_squared > di->radius * di->radius)
        return false;

    // Calculate the normal vector of the di (which is the same as the direction vector)
    intx->t = el.t;
    intx->i = di;
    intx->type = DISK;
    intx->col = di->color;

    return true;
}
