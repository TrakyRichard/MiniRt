/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:19:52 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 14:21:22 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_th
{
	t_gen			*gen;
	pthread_t		thread;
	pthread_mutex_t	*mutex;
	int				h;
	int				w;
	int				id;
}				t_th;

typedef struct s_render_utils
{
	int		i;
	int		j;
	int		h;
	double	u;
	double	v;
	t_ray	ray_s;
	t_hit	optimum;
	t_vec3	v_color;
}				t_render_utils;

void	*render(void *p)
{
	t_th			*t;
	t_render_utils	util;

	t = (t_th *)p;
	util.j = t->h - t->id - 1;
	util.ray_s.origin = t->gen->cam.origin;
	while (util.j >= 0)
	{
		util.v = ((double)(util.j)) / (t->h - 1);
		util.i = -1;
		while (++util.i < t->w)
		{
			util.u = ((double)(util.i)) / (t->w - 1);
			util.ray_s.direction = direction(t->gen->cam, util.u, util.v);
			util.optimum = ray_color(t->gen, util.ray_s);
			pthread_mutex_lock(t->mutex);
			write_color(t->gen, util.optimum,
				vec3(t->w - util.i, t->h - util.j, 0), 1);
			pthread_mutex_unlock(t->mutex);
			util.h++;
		}
		util.j -= 10;
	}
	return (NULL);
}

void	pre_render(t_gen *gen, int h, int w)
{
	t_th			t[10];
	pthread_mutex_t	m;
	int				i;

	pthread_mutex_init(&m, NULL);
	i = 0;
	while (i < 10)
	{
		t[i].gen = gen;
		t[i].h = h;
		t[i].w = w;
		t[i].id = i;
		t[i].mutex = &m;
		pthread_create(&t[i].thread, NULL, &render, &t[i]);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		pthread_join(t[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&m);
}
