/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:24:51 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/12 18:56:39 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
#define SHAPE_H

#include "../minirt.h"

t_b intersect(t_intx *intx, void *shape, t_shtype type);
t_b sphere_intersect(t_intx *intx, t_sp *sp);
t_b plane_intersect(t_intx *intx, t_pl *pl);
t_b square_intersect(t_intx *intx, t_sq *sq);
t_b cylinder_intersect(t_intx *intx, t_cy *cy);
t_b triangle_intersect(t_intx *intx, t_tr *tr);
t_b disk_intersect(t_intx *intx, t_di *di);

t_b does_sphere_intersect(t_ray *r, t_sp *sp);
t_b does_plane_intersect(t_ray *r, t_pl *pl);
t_b does_square_intersect(t_ray *r);
t_b does_cylinder_intersect(t_ray *r);
t_b does_triangle_intersect(t_ray *r);
t_b does_disk_intersect(t_ray *r);

#endif