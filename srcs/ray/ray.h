/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:24:51 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/06 15:28:57 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "../minirt.h"

void	set_ray(t_ray *ray, t_vec3 dir, t_vec3 orig, double t);
void	init_ray(t_ray *ray);
t_vec3	ray_at(t_vec3 orig, t_vec3 dir, double t);
t_b		are_rays_egal(t_ray ray1, t_ray ray2);
t_ray	get_sphere_ray(t_sp *sp, t_ray *normal);
t_ray	get_plane_ray(t_pl *pl, t_ray *normal);
t_ray	get_square_ray(t_sq *sq, t_ray *normal);
t_ray	get_cylinder_ray(t_cy *cy, t_ray *normal);
t_ray	get_disk_ray(t_di *di, t_ray *normal);
t_ray	get_triangle_ray(t_tr *tr, t_ray *normal);
t_ray	get_shape_ray(void *info, t_shtype type);
t_vec3	get_shape_dir(t_intx *intx);
t_vec3	get_shape_org(t_intx *intx);

#endif
