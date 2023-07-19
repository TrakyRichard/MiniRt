/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:47:19 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/19 04:12:28 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void    ft_put_pixel(unsigned char *data, int x, int y, const int color, const t_r resolution)
{
    int(*tab)[resolution.w][1]; // prepare the cast

    tab = (void *)data; // cast for change 1 dimension array to 2 dimensions
    *tab[y][x] = color; // set the pixel at the coord x,y with the color value
}

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

void render(t_sc *scene)
{
    int x;
    int y;
    t_ray ray;
    t_rgb color;

    x = 0;
    while (x < scene->r.w)
    {
        y = 0;
        while (y < scene->r.h)
        {
            double u = (x + 0.5) / scene->r.w;
            double v = (y + 0.5) / scene->r.h;
            ray = get_ray(scene, u, v);
            color = ray_color(scene, &ray);
            ft_put_pixel(scene->img->data, x, y, rgb_to_int(color), scene->r);
            y++;
        }
        x++;
    }
    return;
}
