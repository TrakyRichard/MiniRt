/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 03:57:29 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/24 06:23:04 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minirt.h"

/* Init image and camera */
void init_mini_rt(t_mrt *mrt)
{
	mrt->ar = 16.0 / 9.0;
	mrt->iw = 400;
	mrt->ih = (int) (mrt->iw / mrt->ar);
	vec_init(&mrt->origin);
	mrt->hor = set_vec(mrt->iw, 0, 0);
	mrt->ver = set_vec(0, mrt->ih, 0);
	mrt->lower_lc = vec_minus(vec_minus(vec_minus(mrt->origin, vec_div(mrt->hor, 2)), vec_div(mrt->ver, 2)), set_vec(0, 0, mrt->fl));
}
