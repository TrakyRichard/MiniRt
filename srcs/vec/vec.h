/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:28:18 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/05 05:45:16 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include "../minirt.h"

void	vec_init(t_vec3 *vec3);
t_vec3	vec_add(t_vec3 u, t_vec3 v);
t_vec3	vec_multiply(t_vec3 u, t_vec3 v);
t_vec3	vec_div(t_vec3 vec, double t);
t_vec3	vec_minus(t_vec3 u, t_vec3 v);
double	vec_len_squared(t_vec3 vec);
double	vec_length(t_vec3 vec);
t_vec3	vec_scale(t_vec3 vec, double t);
t_vec3	set_vec(double x, double y, double z);
double  normalize(t_vec3 vec);
t_vec3  normalized(const t_vec3 vec);
t_vec3	vec_cross(const t_vec3 u, const t_vec3 v);
double	vec_dot(const t_vec3 u, const t_vec3 v);
t_b     are_vecs_egal(t_vec3 vec1, t_vec3 vec2);
double  distance(const t_vec3 p1, const t_vec3 p2);

#endif
