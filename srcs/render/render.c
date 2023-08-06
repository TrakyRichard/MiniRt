/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:47:19 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/06 09:56:02 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec3 set_vect_dir_cam(const t_c *cam, const double i, const double j)
{
    t_vec3 dir;

    dir = vec_add(vec_add(cam->dir, vec_scale(cam->right, i * cam->w)), vec_scale(cam->up, j * cam->h));
    return normalized(dir);
}

t_vec3 set_vect_dir_cam2(t_sc sc, int u, int v)
{
    t_vec3 vect_dir;
    double a;
    double b;
    double c;
    int max;

    a = u + 0.5 - (sc.r.w) * 0.5;
    b = v + 0.5 - (sc.r.h) * 0.5;

    max = sc.r.w > sc.r.h ? sc.r.w : sc.r.h;
    c = max / (2 * tan((to_rad(sc.c.fov)) / 180.0));
    vect_dir.x = 1 * a + 0 * b + 0 * c;
    vect_dir.y = 0 * a + 1 * b + 0 * c;
    vect_dir.z = 0 * a + 0 * b + 1 * c;
    return (normalized(vect_dir));
}

t_ray get_ray(t_sc *scene, double x, double y)
{
    t_ray ray;

    ray.orig = scene->c.pos;
    ray.dir = set_vect_dir_cam(&scene->c, x, y);
    return (ray);
}

t_rgb ray_color(t_sc *scene, t_ray *ray)
{
    t_rgb color;
    t_intx intx;

    intx = default_intx_with_ray(ray);
    if (shapes_intersect(&intx, scene->shapes.head))
    {
        color = set_col(1, 200, 200);
    }
    else
    {
        color = set_col(0, 0, 0);
    }
    return (color);
}

void	ray_trace(t_sc scene)
{
	for (int y = 0; y < scene.r.h; y++)
	{
		for (int x = 0; x < scene.r.w; x++)
		{
			t_ray ray;
			ray.orig = scene.c.pos;
			/* ray.dir = normalized(vec_add(vec_add(scene.c.dir, vec_scale(scene.c.right, u * scene.c.w)), vec_scale(scene.c.up, v * scene.c.h))); */
			ray.dir = set_vect_dir_cam2(scene, x, y);
			ray.t = INFINITY;
			// Find the nearest intersection of the ray with the shapes in the scene
			t_intx intersection;
			intersection.ray = ray;
			intersection.t = INFINITY;
			double min_t = INFINITY;
			t_sh *shape = scene.shapes.head;
			while (shape != NULL)
			{
				if (intersect_shape(&intersection, shape) && intersection.t < min_t)
					min_t = intersection.t;
				shape = shape->next;
			}
			put_color(scene, intersection, min_t, x, y);
		}
	}
}

