/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:24:51 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/23 13:25:06 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "../minirt.h"

typedef struct s_ray
{
	t_vec3	orig;
	t_vec3	dir;
}	t_ray;

void	set_ray(t_ray *ray, t_vec3 dir, t_vec3 orig);
void	init_ray(t_ray *ray);
t_vec3	ray_at(t_vec3 *u, t_vec3 *v, double t);

#endif
