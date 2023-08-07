/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 00:20:41 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/07 01:54:59 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../vec/vec.h"
#include "../intersection/intersection.h"
#include "../color/col.h"
#include "../ray/ray.h"
#include "../render/render.h"

t_ray	get_ray(t_sc *scene, double x, double y)
{
	t_ray	ray;

	ray.orig = scene->c.pos;
	ray.dir = set_vect_dir_cam(&scene->c, x, y);
	return (ray);
}
