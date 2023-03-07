/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 05:01:52 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/07 06:14:24 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vec.h"

void	vec_init(t_vec3 *vec3)
{
	vec3->x = 0;
	vec3->y = 0;
	vec3->z = 0;
	return ;
}

t_vec3	vec_addition(t_vec3 u, t_vec3 v)
{
	t_vec3	vec;

	vec.x = u.x + v.x;
	vec.z = u.z + v.z;
	vec.y = u.y + v.y;
	return (vec);
}

t_vec3	vec_multi(t_vec3 u, t_vec3 v)
{
	t_vec3	vec;

	vec.x = u.x * v.x;
	vec.z = u.z * v.z;
	vec.y = u.y * v.y;
	return (vec);
}

t_vec3	vec_multi_with_d(t_vec3 vec, double t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;
	return (vec);
}

t_vec3	vec_div(t_vec3 vec, double t)
{
	return (vec_multi_with_d(vec, 1 / t));
}
