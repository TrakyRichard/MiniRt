/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:35:21 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/08/07 02:09:06 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "./vec/vec.h"

t_vec3	reflect(t_vec3 incident, t_vec3 normal)
{
	double	dot_product;
	t_vec3	reflected;

	dot_product = vec_dot(incident, normal);
	reflected = vec_minus(incident, vec_scale(normal, 2 * dot_product));
	return (reflected);
}
