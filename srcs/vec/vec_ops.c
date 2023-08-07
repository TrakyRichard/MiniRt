/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 05:01:52 by rkanmado          #+#    #+#             */
/*   Updated: 2023/06/25 16:34:41 by richard          ###   ########.fr       */
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

t_vec3	vec_add(t_vec3 u, t_vec3 v)
{
	t_vec3	vec;

	vec.x = u.x + v.x;
	vec.z = u.z + v.z;
	vec.y = u.y + v.y;
	return (vec);
}

t_vec3	vec_multiply(t_vec3 u, t_vec3 v)
{
	t_vec3	vec;

	vec.x = u.x * v.x;
	vec.z = u.z * v.z;
	vec.y = u.y * v.y;
	return (vec);
}

t_vec3	vec_scale(t_vec3 vec, double t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;
	return (vec);
}

t_vec3	vec_div(t_vec3 vec, double t)
{
	if (t == 0)
		return (vec);
	return (vec_scale(vec, 1 / t));
}
