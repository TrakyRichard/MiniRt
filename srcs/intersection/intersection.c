/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:24:51 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/19 03:44:04 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	init_int(t_intx *intx)
{
	init_col(&intx->col);
	init_ray(&intx->ray);
	intx->t = 0;
}

t_intx	set_int(t_ray r, t_rgb rgb, double t)
{
	t_intx	intx;

	intx.col = set_col(rgb.r, rgb.g, rgb.b);
	set_ray(&intx.ray, r.dir, r.orig, t);
	intx.t = t;
	return (intx);
}

void	default_intx(t_intx *intx)
{
	init_col(&intx->col);
	init_ray(&intx->ray);
	intx->t = RAY_T_MAX;
	intx->i = NULL;
	intx->type = NEIN;
}

t_intx	default_intx_with_ray(t_ray *r)
{
	t_intx	intx;

	default_intx(&intx);
	set_ray(&intx.ray, r->dir, r->orig, r->t);
	return (intx);
}

t_b	intersected(t_intx intx)
{
	return (intx.i != NULL && intx.type != NEIN);
}
