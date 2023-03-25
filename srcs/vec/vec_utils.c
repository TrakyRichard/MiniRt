/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 05:18:38 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/24 19:30:15 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	vec_len_squared(t_vec3 vec)
{
	return ((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}

double	vec_length(t_vec3 vec)
{
	return (sqrt(vec_len_squared(vec)));
}

double	vec_dot(const t_vec3 u, const t_vec3 v)
{
	return ((u.x * v.x) + (u.y + v.y) + (u.z + v.z));
}

t_vec3	vec_cross(const t_vec3 u, const t_vec3 v)
{
	t_vec3	vec;

	vec.x = (u.y * v.z) - (u.z * u.y);
	vec.y = (u.z * v.x) - (u.x * v.z);
	vec.z = (u.x * v.y) - (u.y * v.z);
	return (vec);
}

t_vec3	unit_vector(t_vec3 vec)
{
	return (vec_div(vec, vec_length(vec)));
}
