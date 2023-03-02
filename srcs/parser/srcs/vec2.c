/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 05:18:38 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/02 05:21:14 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

double	vec_len_squared(t_vec3 *vec)
{
	return ((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
}

double	length(t_vec3 *vec)
{
	return (sqrt(vec_len_squared(vec)));
}
