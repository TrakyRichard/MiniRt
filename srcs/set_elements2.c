/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elements2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:35:23 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/02/19 12:50:59 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void set_object(t_scene *scene, char **strs, char *type)
{
	if (!ft_strcmp(type, "sp"))
	{
		t_sphere *sphere;

		if (!(sphere = malloc(sizeof(*sphere))))
			print_err_and_exit("Malloc failed", MALLOC_ERROR);
		sphere->pos = str_to_vect(strs[1]);
		double radius = ft_atof(strs[2]);
		sphere->radius2 = radius * radius;
		sphere->color = str_to_rgb(strs[3]);
		sphere->reflec = 0;
		if (strs[4])
			sphere->reflec = ft_atof(strs[4]);
		ft_lstadd_front(&(scene->spheres), ft_lstnew(sphere));
	}
	else if (!ft_strcmp(type, "pl"))
	{
		t_plane *plane;

		if (!(plane = malloc(sizeof(*plane))))
			print_err_and_exit("Malloc failed", MALLOC_ERROR);
		plane->pos = str_to_vect(strs[1]);
		plane->normal = normalize(str_to_vect(strs[2]));
		plane->color = str_to_rgb(strs[3]);
		ft_lstadd_front(&(scene->planes), ft_lstnew(plane));
	}
	else if (!ft_strcmp(type, "cy"))
	{
		t_cylinder *cy;

		if (!(cy = malloc(sizeof(*cy))))
			print_err_and_exit("Malloc failed", MALLOC_ERROR);
		cy->pos = str_to_vect(strs[1]);
		cy->dir = normalize(str_to_vect(strs[2]));
		double radius = ft_atof(strs[3]) / 2;
		cy->radius2 = radius * radius;
		cy->height = ft_atof(strs[4]);
		cy->pos2 = add_vect(cy->pos, multi_vect(cy->dir, cy->height));
		cy->color = str_to_rgb(strs[5]);
		if (strs[6])
			cy->is_closed = ft_atoi_strict(strs[6]);
		else
			cy->is_closed = 1;
		ft_lstadd_front(&(scene->cylinders), ft_lstnew(cy));
	}
	else if (!ft_strcmp(type, "sq"))
	{
		t_square *square;

		if (!(square = malloc(sizeof(*square))))
			print_err_and_exit("Malloc failed", MALLOC_ERROR);
		square->pos = str_to_vect(strs[1]);
		square->normal = normalize(str_to_vect(strs[2]));
		square->height = ft_atof(strs[3]);
		square->color = str_to_rgb(strs[4]);
		set_square_points(scene, square);
		ft_lstadd_front(&(scene->squares), ft_lstnew(square));
	}
	else if (!ft_strcmp(type, "tr"))
	{
		t_triangle *triangle;

		if (!(triangle = malloc(sizeof(*triangle))))
			print_err_and_exit("Malloc failed", MALLOC_ERROR);
		triangle->v0 = str_to_vect(strs[1]);
		triangle->v1 = str_to_vect(strs[2]);
		triangle->v2 = str_to_vect(strs[3]);
		triangle->color = str_to_rgb(strs[4]);
		ft_lstadd_front(&(scene->triangles), ft_lstnew(triangle));
	}
	else
	{
		print_err_and_exit("Invalid object type", PARSE_ERROR);
	}
}
