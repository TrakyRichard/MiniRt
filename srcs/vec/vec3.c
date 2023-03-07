/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:47:19 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/07 04:54:22 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vec.h"

t_vec3	vec_minus(t_vec3 *u, t_vec3 *v)
{
	t_vec3	vec;

	vec.x = u->x - v->x;
	vec.z = u->z - v->z;
	vec.y = u->y - v->y;
	return (vec);
}

t_vec3	set_vec(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}
