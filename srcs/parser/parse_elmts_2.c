/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elmts_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:20:44 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/16 03:13:18 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "parser.h"
#include "../vec/vec.h"
#include "../ray/ray.h"

t_b	parse_sphere(char *line, t_sc *sc)
{
	t_sp	*sp;
	char	**split;
	char	**split_semi_colon;
	size_t	length;

	split_semi_colon = ft_split(line, ";");
	split = ft_split(split_semi_colon[0], WHITE_SPACES);
	length = split_length(split);
	if (length < 4)
		return (ft_split_error("Sphere format is wrong\n", split, line));
	sp = malloc(sizeof(t_sp));
	if (!sp)
		return (ft_error("Spheres allocation failled\n"));
	sp->center = str_to_vec3(split[1]);
	sp->radius = ft_atof(split[2]);
	sp->color = str_to_rgb(split[3]);
	ft_unshift(&sc->shapes, (void *)sp, SPHERE);
	ft_free_dbpt(split);
	ft_free_dbpt(split_semi_colon);
	return (true);
}

t_b	parse_plane(char *line, t_sc *sc)
{
	t_pl	*pl;
	char	**split;
	char	**split_semi_colon;
	size_t	length;

	split_semi_colon = ft_split(line, ";");
	split = ft_split(split_semi_colon[0], WHITE_SPACES);
	length = split_length(split);
	if (length < 4)
		return (ft_split_error("Plane format is wrong\n", split, line));
	pl = malloc(sizeof(t_pl));
	if (!pl)
		return (ft_error("Planes allocation failled\n"));
	pl->pos = str_to_vec3(split[1]);
	pl->dir = normalized(str_to_vec3(split[2]));
	pl->color = str_to_rgb(split[3]);
	ft_unshift(&sc->shapes, (void *)pl, PLANE);
	ft_free_dbpt(split);
	return (true);
}

t_b	parse_square(char *line, t_sc *sc)
{
	t_sq	*sq;
	char	**split;
	char	**split_semi_colon;
	size_t	length;

	split_semi_colon = ft_split(line, ";");
	split = ft_split(split_semi_colon[0], WHITE_SPACES);
	split = ft_split(line, WHITE_SPACES);
	length = split_length(split);
	if (length < 5)
		return (ft_split_error("Square format is wrong\n", split, line));
	sq = malloc(sizeof(t_sq));
	if (!sq)
		return (ft_error("Squares allocation failled\n"));
	sq->pos = str_to_vec3(split[1]);
	sq->dir = normalized(str_to_vec3(split[2]));
	sq->side_size = ft_atof(split[3]);
	sq->color = str_to_rgb(split[4]);
	ft_unshift(&sc->shapes, (void *)sq, SQUARE);
	return (true);
}

t_b	parse_cylinder(char *line, t_sc *sc)
{
	char	**split;
	char	**split_semi_colon;
	t_cy	*cy;
	size_t	length;

	split_semi_colon = ft_split(line, ";");
	split = ft_split(split_semi_colon[0], WHITE_SPACES);
	length = split_length(split);
	if (length < 6)
		return (ft_split_error("Cylinder format is wrong\n", split, line));
	cy = malloc(sizeof(t_cy));
	if (!cy)
		return (ft_error("Cylinders allocation failled\n"));
	cy->pos = str_to_vec3(split[1]);
	cy->dir = normalized(str_to_vec3(split[2]));
	cy->radius = ft_atof(split[3]) / 2;
	cy->height = ft_atof(split[4]);
	cy->color = str_to_rgb(split[5]);
	ft_unshift(&sc->shapes, (void *)cy, CYLINDER);
	return (true);
}

t_b	parse_triangle(char *line, t_sc *sc)
{
	char	**split;
	char	**split_semi_colon;
	t_tr	*tr;
	size_t	length;

	split_semi_colon = ft_split(line, ";");
	split = ft_split(split_semi_colon[0], WHITE_SPACES);
	length = split_length(split);
	if (length < 5)
		return (ft_split_error("Triangle format is wrong\n", split, line));
	tr = malloc(sizeof(t_tr));
	if (!tr)
		return (ft_error("Triangles allocation failled\n"));
	tr->pos1 = str_to_vec3(split[1]);
	tr->pos2 = str_to_vec3(split[2]);
	tr->pos3 = str_to_vec3(split[3]);
	tr->color = str_to_rgb(split[4]);
	ft_unshift(&sc->shapes, (void *)tr, TRIANGLE);
	return (true);
}
