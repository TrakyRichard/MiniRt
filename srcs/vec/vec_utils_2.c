/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 23:45:05 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/07 02:13:55 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "./vec.h"

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

	length = distance(set_vec(0, 0, 0), vect);
	if (length == 0)
		return (set_vec(0, 0, 0));
	return (set_vec(vect.x / length, vect.y / length, vect.z / length));
}
