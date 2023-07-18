/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:24:51 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/12 18:57:13 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void init_int(t_intx *intx)
{
    init_col(&intx->col);
    init_ray(&intx->ray);
    intx->t = 0;
    // TODO: Init the p_shape
}

t_intx set_int(t_ray r, t_rgb rgb, double t)
{
    t_intx intx;

    intx.col = set_col(rgb.r, rgb.g, rgb.b);
    set_ray(&intx.ray, r.dir, r.orig, t);
    // set_shape(intx.p_shape);
    intx.t = t;

    return (intx);
}

void default_intx(t_intx *intx)
{
    init_col(&intx->col);
    init_ray(&intx->ray);
    intx->t = RAY_T_MAX;
    intx->i = NULL;
    intx->type = NEIN;
}

t_intx default_intx_with_ray(t_ray *r)
{
    t_intx intx;

    default_intx(&intx);
    set_ray(&intx.ray, r->dir, r->orig, r->t);
    return (intx);
}

t_b intersected(t_intx intx)
{
    return (intx.i != NULL && intx.type != NEIN);
}

t_vec3 position(t_intx intx, double t)
{
    return ray_at(intx.ray.orig, intx.ray.dir, t);
}

t_b intersect_shape(t_intx *intx, t_sh *sh)
{
    t_b intersect = false;
    switch (sh->type)
    {
    case SPHERE:
        intersect = sphere_intersect(intx, (t_sp *)sh->i);
        break;
    case PLANE:
        intersect = plane_intersect(intx, (t_pl *)sh->i);
        break;
    case SQUARE:
        intersect = square_intersect(intx, (t_sq *)sh->i);
        break;
    case CYLINDER:
        intersect = cylinder_intersect(intx, (t_cy *)sh->i);
        break;
    case DISK:
        intersect = disk_intersect(intx, (t_di *)sh->i);
        break;
    case TRIANGLE:
        intersect = triangle_intersect(intx, (t_tr *)sh->i);
        break;
    default:
        break;
    }
    return (intersect);
}