/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:28:46 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/02/19 12:50:44 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_vect set_vect(const char *x, const char *y, const char *z)
{
    t_vect vect = {
        .x = ft_atof(x),
        .y = ft_atof(y),
        .z = ft_atof(z),
    };
    return vect;
}

t_vect str_to_vect(const char *str)
{
    char **tab = ft_split(str, ',');
    t_vect vect = set_vect(tab[0], tab[1], tab[2]);
    free_split(tab);
    return vect;
}

t_rgb str_to_rgb(const char *str)
{
    char **tab = ft_split(str, ',');
    t_rgb rgb = char_to_rgb(tab[0], tab[1], tab[2]);
    free_split(tab);
    return rgb;
}

double to_rad(const double angle)
{
    return angle * M_PI * 0.5;
}

t_ray new_ray(const t_vect position, const t_vect direction)
{
    t_ray ray = {
        .pos = position,
        .dir = direction,
        .t = INFINITY,
    };
    return ray;
}

t_vect set_vect_dir_cam(const t_camera *camera, const t_couple resolution, const int i, const int j)
{
    t_vect vect_dir;
    double a = j + 0.5 - (resolution.w) * 0.5;
    double b = i + 0.5 - (resolution.h) * 0.5;
    int max = resolution.w > resolution.h ? resolution.w : resolution.h;
    double c = max / (2 * tan((to_rad(camera->fov)) / 180.0));
    vect_dir.x = a;
    vect_dir.y = b;
    vect_dir.z = -c;
    vect_dir = rotate_vect(vect_dir, camera->rot);
    vect_dir = normalize(vect_dir);
    return vect_dir;
}
