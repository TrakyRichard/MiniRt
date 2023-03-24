/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:28:18 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/24 06:02:37 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

void	vec_init(t_vec3 *vec3);
t_vec3	vec_addition(t_vec3 u, t_vec3 v);
t_vec3	vec_multi(t_vec3 u, t_vec3 v);
t_vec3	vec_div(t_vec3 vec, double t);
t_vec3	vec_minus(t_vec3 u, t_vec3 v);
double	vec_len_squared(t_vec3 vec);
double	vec_length(t_vec3 vec);
t_vec3	vec_multi_with_d(t_vec3 vec, double t);
t_vec3	set_vec(double x, double y, double z);

#endif
