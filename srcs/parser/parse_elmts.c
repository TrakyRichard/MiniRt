/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elmts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:20:44 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/19 03:36:34 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_resolution(char *line, t_sc *sc)
{
	char	**split;

	split = ft_split(line, WHITE_SPACES);
	sc->r.w = ft_atoi(split[1]);
	sc->r.h = ft_atoi(split[2]);
	ft_free_dbpt(split);
}

void	parse_ambient(char *line, t_sc *sc)
{
	char	**split;

	split = ft_split(line, WHITE_SPACES);
	sc->a.ratio = ft_atof(split[1]);
	sc->a.color = col_multi_with_d(str_to_rgb(split[2]), sc->a.ratio);
	ft_free_dbpt(split);
}

void	parse_camera(char *line, t_sc *sc)
{
	char	**split;

	split = ft_split(line, WHITE_SPACES);
	sc->c.pos = str_to_vec3(split[1]);
	sc->c.dir = normalized(str_to_vec3(split[2]));
	sc->c.right = normalized(vec_cross(set_vec(0, 1, 0), sc->c.dir));
	sc->c.up = normalized(vec_cross(sc->c.right, sc->c.dir));
	sc->c.fov = ft_atof(split[3]);
	sc->c.h = 2 * tan(to_rad(sc->c.fov / 2));
	sc->c.w = sc->c.h * ((double)sc->r.w / (double)sc->r.h);
	ft_free_dbpt(split);
}

void	parse_light(char *line, t_sc *sc)
{
	char	**split;
	t_l		*l;

	l = malloc(sizeof(t_l));
	if (!l)
		ft_error("Lights allocation failled\n");
	split = ft_split(line, WHITE_SPACES);
	l->pos = str_to_vec3(split[1]);
	l->ratio = ft_atof(split[2]);
	l->color = col_multi_with_d(str_to_rgb(split[3]), l->ratio);
	ft_unshift(&sc->l, (void *)l, LIGHT);
	ft_free_dbpt(split);
}
