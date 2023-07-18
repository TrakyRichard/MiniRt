/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elmts_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:20:44 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/09 12:52:09 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void parse_sphere(char *line, t_sc *sc)
{
    t_sp *sp;
    char **split;

    sp = malloc(sizeof(t_sp));
    if (!sp)
        ft_error("Spheres allocation failled\n");
    split = ft_split(line, WHITE_SPACES);
    sp->center = str_to_vec3(split[1]);
    sp->radius = ft_atof(split[2]);
    sp->color = str_to_rgb(split[3]);
    sp->intersect = &sphere_intersect;
    sp->does_intersect = &does_sphere_intersect;
    ft_unshift(&sc->shapes, (void *)sp, SPHERE);
}

void parse_plane(char *line, t_sc *sc)
{
    t_pl *pl;
    char **split;

    pl = malloc(sizeof(t_pl));
    if (!pl)
        ft_error("Planes allocation failled\n");
    split = ft_split(line, WHITE_SPACES);
    pl->pos = str_to_vec3(split[1]);
    pl->dir = normalized(str_to_vec3(split[2]));
    pl->color = str_to_rgb(split[3]);
    pl->intersect = &plane_intersect;
    pl->does_intersect = &does_plane_intersect;
    ft_unshift(&sc->shapes, (void *)pl, PLANE);
}

void parse_square(char *line, t_sc *sc)
{
    t_sq *sq;
    char **split;

    split = ft_split(line, WHITE_SPACES);
    sq = malloc(sizeof(t_sq));
    if (!sq)
        ft_error("Squares allocation failled\n");
    sq->pos = str_to_vec3(split[1]);
    sq->dir = normalized(str_to_vec3(split[2]));
    sq->side_size = ft_atof(split[3]);
    sq->color = str_to_rgb(split[4]);
    sq->intersect = &square_intersect;
    sq->does_intersect = &does_square_intersect;
    ft_unshift(&sc->shapes, (void *)sq, SQUARE);
}

void parse_cylinder(char *line, t_sc *sc)
{
    char **split;
    t_cy *cy;

    split = ft_split(line, WHITE_SPACES);
    cy = malloc(sizeof(t_cy));
    if (!cy)
        ft_error("Cylinders allocation failled\n");
    cy->pos = str_to_vec3(split[1]);
    cy->dir = normalized(str_to_vec3(split[2]));
    cy->radius = ft_atof(split[3]) / 2;
    cy->height = ft_atof(split[4]);
    cy->color = str_to_rgb(split[5]);
    cy->intersect = &cylinder_intersect;
    cy->does_intersect = &does_cylinder_intersect;
    ft_unshift(&sc->shapes, (void *)cy, CYLINDER);
}

void parse_triangle(char *line, t_sc *sc)
{
    char **split;
    t_tr *tr;

    split = ft_split(line, WHITE_SPACES);
    tr = malloc(sizeof(t_tr));
    if (!tr)
        ft_error("Triangles allocation failled\n");
    tr->pos1 = str_to_vec3(split[1]);
    tr->pos2 = str_to_vec3(split[2]);
    tr->pos3 = str_to_vec3(split[3]);
    tr->color = str_to_rgb(split[4]);
    tr->intersect = &triangle_intersect;
    tr->does_intersect = &does_triangle_intersect;
    ft_unshift(&sc->shapes, (void *)tr, TRIANGLE);
}

void parse_disk(char *line, t_sc *sc)
{
    char **split;
    t_di *di;

    split = ft_split(line, WHITE_SPACES);
    di = malloc(sizeof(t_di));
    if (!di)
        ft_error("Disks allocation failled\n");
    di->pos = str_to_vec3(split[1]);
    di->dir = str_to_vec3(split[2]);
    di->radius = ft_atof(split[3]) / 2;
    di->color = str_to_rgb(split[4]);
    di->intersect = &disk_intersect;
    di->does_intersect = &does_disk_intersect;
    ft_unshift(&sc->shapes, (void *)di, DISK);
}
