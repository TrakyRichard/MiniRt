/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 05:18:38 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/06 12:17:40 by richard          ###   ########.fr       */
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
	t_vec3 result;

    result.x = u.y * v.z - u.z * v.y;
    result.y = u.z * v.x - u.x * v.z;
    result.z = u.x * v.y - u.y * v.x;
    return result;
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
	if (length == 0)
		return (set_vec(0, 0, 0));
	return (set_vec(vect.x / length, vect.y / length, vect.z / length));
}
