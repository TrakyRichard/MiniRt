/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:47:19 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/16 02:35:56 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../minirt.h"

t_rgb	*manage_light(t_sc *scene, t_intx *intx, t_rgb *color);
void	ft_put_pixel(unsigned char *data, t_r pt, const int color, \
const t_r resolution);
t_vec3	set_vect_dir_cam(const t_c *cam, const double i, const double j);
t_vec3	set_vect_dir_cam2(t_sc *sc, int u, int v);
t_ray	get_ray(t_sc *scene, double x, double y);
t_rgb	ray_color(t_sc *scene, t_ray *ray);
void	render(t_sc *scene);

#endif
