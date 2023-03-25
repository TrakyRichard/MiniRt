/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 05:01:52 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/24 19:29:50 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec3	vec_minus(t_vec3 u, t_vec3 v)
{
	t_vec3	vec;

	vec.x = u.x - v.x;
	vec.z = u.z - v.z;
	vec.y = u.y - v.y;
	return (vec);
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
