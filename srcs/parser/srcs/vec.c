/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 05:01:52 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/02 05:19:13 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

void	vec_init(t_vec3 *vec3)
{
	vec3->x = 0;
	vec3->y = 0;
	vec3->z = 0;
	return ;
}

void	vec_addition(t_vec3 *vec, t_vec3 *to_add)
{
	vec->x += to_add->x;
	vec->y += to_add->y;
	vec->z += to_add->z;
	return ;
}

void	vec_multi(t_vec3 *vec, t_vec3 *to_multi)
{
	vec->x *= to_multi->x;
	vec->y *= to_multi->y;
	vec->z *= to_multi->z;
	return ;
}

void	vec_div(t_vec3 *vec, t_vec3 *to_div)
{
	vec->x /= to_div->x;
	vec->y /= to_div->y;
	vec->z /= to_div->z;
	return ;
}

void	vec_minus(t_vec3 *vec, t_vec3 *to_minus)
{
	vec->x -= to_minus->x;
	vec->y -= to_minus->y;
	vec->z -= to_minus->z;
	return ;
}
