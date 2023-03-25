/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:11:39 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 14:51:26 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_cam(t_gen *gen, t_image img)
{
	double	theta;
	double	h;
	t_vec3	w;
	t_vec3	u;
	t_vec3	v;

	theta = to_radians(img.fow);
	h = tan(theta / 2);
	gen->cam.v_h = 2.0 * h;
	gen->cam.v_w = img.aspect_ratio * gen->cam.v_h;
	w = unit_vector(sub(img.origin, img.dir));
	u = unit_vector(cross(img.vup, w));
	v = cross(w, u);

	// Set the position of the camera as the origin of the scene.
	gen->cam.origin = img.origin;

	// Calculate the horizontal and vertical vectors of the camera's field of view.
	gen->cam.horizontal = mpv(u, gen->cam.v_w);
	gen->cam.vertical = mpv(v, gen->cam.v_h);

	// Calculate the lower left corner of the camera's view frustum.
	gen->cam.lower_left = sub(gen->cam.origin, dvd(gen->cam.horizontal, 2));
	gen->cam.lower_left = sub(gen->cam.lower_left, dvd(gen->cam.vertical, 2));
	gen->cam.lower_left = sub(gen->cam.lower_left, mpv(w, gen->cam.fl));

	// Set the window size based on the aspect ratio of the image.
	gen->cam.win_x = 1920;
	gen->cam.win_y = (int)(gen->cam.win_x / img.aspect_ratio);

	// Set the camera's focal length.
	gen->cam.fl = 1.0;
}
