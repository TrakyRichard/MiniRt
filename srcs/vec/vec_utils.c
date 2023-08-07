/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 05:18:38 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/06 23:44:45 by rkanmado         ###   ########.fr       */
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
	return ((u.x * v.x) + (u.y * v.y) + (u.z * v.z));
}

double	distance(const t_vec3 p1, const t_vec3 p2)
{
	return (sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) \
			+ pow(p2.z - p1.z, 2)));
}

t_vec3	vec_cross(const t_vec3 u, const t_vec3 v)
{
	t_vec3	result;

	result.x = u.y * v.z - u.z * v.y;
	result.y = u.z * v.x - u.x * v.z;
	result.z = u.x * v.y - u.y * v.x;
	return (result);
}
