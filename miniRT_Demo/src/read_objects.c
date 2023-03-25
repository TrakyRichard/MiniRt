/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:13:04 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 14:16:46 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

void read_sphere(t_read *read, char **split, int l)
{
    check_valid_divided(4, split, l);

    t_sphere *sphere = malloc(sizeof(t_sphere));
    sphere->next = NULL;

    char **xyz_split = ft_split(split[1], ',');
    check_valid_divided(3, xyz_split, l);
    sphere->xyz = split_vec(xyz_split);
    ft_free(xyz_split);

    sphere->diameter = ft_atod(split[2]);

    char **rgb_split = ft_split(split[3], ',');
    check_valid_divided(3, rgb_split, l);
    t_vec3 rgb = split_vec(rgb_split);
    sphere->rgb = vec3(rgb.x / 255, rgb.y / 255, rgb.z / 255);
    check_range(0, 1, sphere->rgb, l);
    ft_free(rgb_split);

    insert_sphere(read, sphere);
}

void read_plane(t_read *read, char **split, int l)
{
    check_valid_divided(4, split, l);

    t_plane *plane = malloc(sizeof(t_plane));
    plane->next = NULL;

    char **xyz_split = ft_split(split[1], ',');
    check_valid_divided(3, xyz_split, l);
    plane->xyz = split_vec(xyz_split);
    ft_free(xyz_split);

    char **orientation_split = ft_split(split[2], ',');
    check_valid_divided(3, orientation_split, l);
    plane->orientation = split_vec(orientation_split);
    check_range(-1, 1, plane->orientation, l);
    ft_free(orientation_split);

    char **rgb_split = ft_split(split[3], ',');
    check_valid_divided(3, rgb_split, l);
    t_vec3 rgb = split_vec(rgb_split);
    plane->rgb = vec3(rgb.x / 255, rgb.y / 255, rgb.z / 255);
    check_range(0, 1, plane->rgb, l);
    ft_free(rgb_split);

    insert_plane(read, plane);
}

void read_cylinder(t_read *read, char **split, int l)
{
    check_valid_divided(6, split, l);

    t_cylinder *cylinder = malloc(sizeof(t_cylinder));
    cylinder->next = NULL;

    char **xyz_split = ft_split(split[1], ',');
    check_valid_divided(3, xyz_split, l);
    cylinder->xyz = split_vec(xyz_split);
    ft_free(xyz_split);

    char **orientation_split = ft_split(split[2], ',');
    check_valid_divided(3, orientation_split, l);
    cylinder->orientation = split_vec(orientation_split);
    check_range(-1, 1, cylinder->orientation, l);
    ft_free(orientation_split);

    cylinder->diameter = ft_atod(split[3]);
    cylinder->height = ft_atod(split[4]);

    char **rgb_split = ft_split(split[5], ',');
    check_valid_divided(3, rgb_split, l);
    t_vec3 rgb = split_vec(rgb_split);
    cylinder->rgb = vec3(rgb.x / 255, rgb.y / 255, rgb.z / 255);
    check_range(0, 1, cylinder->rgb, l);
    ft_free(rgb_split);

    insert_cylinder(read, cylinder);
}
