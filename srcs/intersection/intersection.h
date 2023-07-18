/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:24:51 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/12 18:54:26 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "../minirt.h"

void init_int(t_intx *intx);
t_intx set_int(t_ray r, t_rgb rgb, double t);
t_b intersected(t_intx intx);
t_vec3 position(t_intx intx, double t);
void default_intx(t_intx *intx);
t_intx default_intx_with_ray(t_ray *r);
t_b intersected(t_intx intx);
void init_sphere_intx(t_sp_intx *el, t_intx *intx, t_sp *sp);
t_b set_sphere_intx(t_intx *intx, t_sp *sp, double t, t_b res);
void init_square_intx(t_sq_intx *el, t_intx *intx, t_sq *sq, int level);
void init_cylinder_intx(t_cy_intx *el, t_intx *intx, t_cy *cy, int level);
void init_disk_intx(t_di_intx *el, t_intx *intx, t_di *di, int level);
void init_triangle_intx(t_tr_intx *el, t_intx *intx, t_tr *tr, int level);
t_b intersect_shape(t_intx *intx, t_sh *sh);

#endif