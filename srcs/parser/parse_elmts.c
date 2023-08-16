/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elmts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:20:44 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/13 12:20:31 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "parser.h"
#include "../vec/vec.h"
#include "../ray/ray.h"
#include "../color/col.h"

t_b	parse_resolution(char *line, t_sc *sc)
{
	char	**split;
	size_t	length;

	split = ft_split(line, WHITE_SPACES);
	length = split_length(split);
	if (length < 3)
		return (ft_split_error("Resolution format is wrong\n", split, line));
	sc->r.w = ft_atoi(split[1]);
	sc->r.h = ft_atoi(split[2]);
	ft_free_dbpt(split);
	return (true);
}

t_b	parse_ambient(char *line, t_sc *sc)
{
	char	**split;
	size_t	length;

	split = ft_split(line, WHITE_SPACES);
	length = split_length(split);
	if (length < 3)
		return (ft_split_error("Ambient format is wrong\n", split, line));
	sc->a.ratio = ft_atof(split[1]);
	sc->a.color = col_multi_with_d(str_to_rgb(split[2]), sc->a.ratio);
	ft_free_dbpt(split);
	return (true);
}

t_b	parse_camera(char *line, t_sc *sc)
{
	char	**split;
	size_t	length;

	split = ft_split(line, WHITE_SPACES);
	length = split_length(split);
	if (length < 4)
		return (ft_split_error("Camera format is wrong\n", split, line));
	sc->c.pos = str_to_vec3(split[1]);
	sc->c.dir = normalized(str_to_vec3(split[2]));
	sc->c.right = normalized(vec_cross(set_vec(0, 1, 0), sc->c.dir));
	sc->c.up = normalized(vec_cross(sc->c.right, sc->c.dir));
	sc->c.fov = ft_atof(split[3]);
	sc->c.h = 2 * tan(to_rad(sc->c.fov / 2));
	sc->c.w = sc->c.h * ((double)sc->r.w / (double)sc->r.h);
	ft_free_dbpt(split);
	return (true);
}

t_b	parse_light(char *line, t_sc *sc)
{
	char	**split;
	t_l		*l;
	size_t	length;

	split = ft_split(line, WHITE_SPACES);
	length = split_length(split);
	if (length < 4)
		return (ft_split_error("Light format is wrong\n", split, line));
	l = malloc(sizeof(t_l));
	if (!l)
		return (ft_error("Lights allocation failled\n"));
	l->pos = str_to_vec3(split[1]);
	l->ratio = ft_atof(split[2]) * 255;
	l->color = col_multi_with_d(str_to_rgb(split[3]), l->ratio);
	ft_unshift(&sc->l, (void *)l, LIGHT);
	ft_free_dbpt(split);
	return (true);
}

t_b	parse_disk(char *line, t_sc *sc)
{
	char	**split;
	char	**split_semi_colon;
	t_di	*di;
	size_t	length;

	split_semi_colon = ft_split(line, ";");
	split = ft_split(split_semi_colon[0], WHITE_SPACES);
	length = split_length(split);
	if (length < 5)
		return (ft_split_error("Disk format is wrong\n", split, line));
	di = malloc(sizeof(t_di));
	if (!di)
		return (ft_error("Disks allocation failled\n"));
	di->pos = str_to_vec3(split[1]);
	di->dir = str_to_vec3(split[2]);
	di->radius = ft_atof(split[3]) / 2;
	di->color = str_to_rgb(split[4]);
	ft_unshift(&sc->shapes, (void *)di, DISK);
	ft_free_dbpt(split);
	return (true);
}
