/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_works.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:29:33 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 15:17:59 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_object t_object;

void add_object_to_scene(t_gen *gen, t_object obj)
{
    scene_add_back(&(gen->scene), scene_obj(obj));
}

void add_cylinder_to_scene(t_gen *gen, t_vec3 center, t_vec3 color, t_cylinder cyl_data)
{
    t_object obj = object("cylinder", center, color, cyl_data);
    add_object_to_scene(gen, obj);
}

void add_sphere_to_scene(t_gen *gen, t_vec3 center, t_vec3 color, t_sphere sph_data)
{
    t_object obj = object("sphere", center, color, sph_data);
    add_object_to_scene(gen, obj);
}

void add_plane_to_scene(t_gen *gen, t_vec3 center, t_vec3 color, t_plane pln_data)
{
    t_object obj = object("plane", center, color, pln_data);
    add_object_to_scene(gen, obj);
}
