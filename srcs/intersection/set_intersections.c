/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_intersections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 22:07:57 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/18 22:07:59 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_b	set_sphere_intx(t_intx *intx, t_sp *sp, double t, t_b res)
{
	intx->t = t;
	intx->i = sp;
	intx->type = SPHERE;
	intx->col = sp->color;
	return (res);
}
