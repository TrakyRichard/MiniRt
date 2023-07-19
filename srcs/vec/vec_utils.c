/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 05:18:38 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/19 04:49:44 by rkanmado         ###   ########.fr       */
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
	t_vec3	origin;
	t_vec3	normal;
	double	denom;
	double	cross;

	origin = set_vec(0, 0, 0);
	denom = distance(origin, u) * distance(origin, v);
	cross = denom * sinf(acos(vec_dot(u, v) / denom));
	normal = set_vec(u.y * v.z - u.z * v.y, u.x * v.z - \
	u.z * v.x, u.y * v.x - u.x * v.y);
	return (vec_scale(normal, cross));
}

double	normalize(t_vec3 vec)
{
	double	len;

	len = vec_length(vec);
	vec = vec_div(vec, len);
	return (len);
}

/* t_vec3  normalized(t_vec3 vec)
{
	t_vec3 new_vec;
	double len;

	new_vec = set_vec(vec.x, vec.y, vec.z);
	len = vec_length(new_vec);
	new_vec = vec_div(new_vec, len);
	return (new_vec);
}
 */

t_vec3	normalized(const t_vec3 vect)
{
	double	length;

	length = distance(set_vec(0,0,0), vect);
	return (set_vec(vect.x / length, vect.y / length, vect.z / length));
}
