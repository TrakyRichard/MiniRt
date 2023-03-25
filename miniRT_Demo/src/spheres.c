/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:37:03 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 14:38:30 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_utils
{
	float pi;
	float di;
	float dj;
	float db;
	float da;
	float i;
	float j;
} t_utils;

typedef struct s_square
{
	t_vec3 p1;
	t_vec3 p2;
	t_vec3 p3;
	t_vec3 p4;
} t_square;

t_utils init_utils()
{
	t_utils utils = {
		.pi = 3.141,
		.di = 0.04,
		.dj = 0.1,
		.db = 0,
		.da = 0,
		.i = 0,
		.j = 0
	};
	utils.db = utils.di * 2 * utils.pi;
	utils.da = utils.dj * utils.pi;
	return (utils);
}

void put_square(t_utils *s, float r, t_mesh *self)
{
	float a = (s->j - 0.5) * s->pi;
	float b = s->i * 2 * s->pi;

	t_square sq = {
		.p1 = vec3(r * cos(a) * cos(b), r * cos(a) * sin(b), r * sin(a)),
		.p2 = vec3(r * cos(a) * cos(b + s->db), r * cos(a) * sin(b + s->db), r * sin(a)),
		.p3 = vec3(r * cos(a + s->da) * cos(b + s->db), r * cos(a + s->da) * sin(b + s->db), r * sin(a + s->da)),
		.p4 = vec3(r * cos(a + s->da) * cos(b), r * cos(a + s->da) * sin(b), r * sin(a + s->da))
	};

	mesh_append(self, triangle(sq.p1, sq.p4, sq.p3));
	mesh_append(self, triangle(sq.p3, sq.p2, sq.p1));
}

void draw_sphere(double r, t_mesh *self)
{
	t_utils s = init_utils();

	while (s.i < 1.0)
	{
		s.j = 0;
		while (s.j < 1.0)
		{
			put_square(&s, r, self);
			s.j += s.dj;
		}
		s.i += s.di;
	}
}
