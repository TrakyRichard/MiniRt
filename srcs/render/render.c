/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:47:19 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/13 18:45:12 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../vec/vec.h"
#include "../intersection/intersection.h"
#include "../color/col.h"
#include "../ray/ray.h"

t_vec3	set_vect_dir_cam(const t_c *cam, const double i, const double j)
{
	t_vec3	dir;

	dir = vec_add(vec_add(cam->dir, vec_scale(cam->right, i * cam->w)), \
	vec_scale(cam->up, j * cam->h));
	return (normalized(dir));
}

t_vec3 cam2world(const t_c *cam, const t_vec3 *dir)
{
	t_vec3 world_dir;

	world_dir.x = dir->x * cam->right.x + dir->y * cam->up.x + dir->z * cam->dir.x;
	world_dir.y = dir->x * cam->right.y + dir->y * cam->up.y + dir->z * cam->dir.y;
	world_dir.z = dir->x * cam->right.z + dir->y * cam->up.z + dir->z * cam->dir.z;
	
	return normalized(world_dir);
}

t_vec3	set_vect_dir_cam3(t_sc *sc, int u, int v)
{
	t_vec3	vect_dir;
	double	x;
	double	y;
	double	z;
	double	aspect_ratio;

		// Assuming FOV is in degrees
	double fov_degrees = sc->c.fov;
	double fov_radians = to_rad(fov_degrees); // Convert FOV to radians
	double half_fov_radians = fov_radians * 0.5;

	// Calculate the camera scale based on the FOV
	float scale = tan(half_fov_radians);

	aspect_ratio = (double)sc->r.w / (double)sc->r.h;
	x = (2.0 * (u + 0.5) / (double)sc->r.w - 1.0) * scale * aspect_ratio;
	y = (1.0 - 2.0 * (v + 0.5) / (double)sc->r.h) * scale;
	z = FOCAL_DIST;

	vect_dir = set_vec(x, y, z);
	t_vec3 world_dir = cam2world(&sc->c, &vect_dir);
	return normalized(world_dir);
}


t_vec3	set_vect_dir_cam2(t_sc *sc, int u, int v)
{
	t_vec3	vect_dir;
	double	a;
	double	b;
	double	c;
	int		max;

	a = u + 0.5 - (sc->r.w) * 0.5;
	b = v + 0.5 - (sc->r.h) * 0.5;
    if (sc->r.w > sc->r.h)
        max = sc->r.w;
	else
		max = sc->r.h;
	c = max / (2 * tan((to_rad(sc->c.fov)) / 180.0));
	vect_dir.x = 1 * a + 0 * b + 0 * c;
	vect_dir.y = 0 * a + 1 * b + 0 * c;
	vect_dir.z = 0 * a + 0 * b + 1 * c;
	return (normalized(vect_dir));
}

typedef struct s_ray_trace
{
	t_ray	ray;
	double	min_t;
	t_sh	*shape;
	t_intx	intersection;
	t_r		p;
}	t_ray_trace;

void	tracing_process(t_sc *scene, t_ray_trace *el)
{
	el->min_t = INFINITY;
	el->shape = scene->shapes.head;
	el->ray.orig = scene->c.pos;
	el->ray.dir = set_vect_dir_cam2(scene, el->p.w, el->p.h);
	el->ray.t = INFINITY;
	el->intersection.ray = el->ray;
	el->intersection.t = INFINITY;
	while (el->shape != NULL)
	{
		if (intersect_shape(&el->intersection, el->shape) \
		&& el->intersection.t < el->min_t)
			el->min_t = el->intersection.t;
		el->shape = el->shape->next;
	}
	put_color(scene, el->intersection, \
	set_put_color(el->min_t, el->p.w, el->p.h));
}

void	ray_trace(t_sc scene)
{
	t_ray_trace	el;

	el.p.w = 0;
	el.p.h = 0;
	while (el.p.h < scene.r.h)
	{
        el.p.w = 0;
		while (el.p.w < scene.r.w)
		{
			tracing_process(&scene, &el);
			el.p.w++;
		}
		el.p.h++;
	}
}
