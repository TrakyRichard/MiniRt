/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:20:26 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/07/19 04:39:22 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	init_scene(t_sc *scene)
{
	scene->a.color = (t_rgb){0, 0, 0};
	scene->a.ratio = 0;
	scene->r.h = 0;
	scene->r.w = 0;
	init_stack(&scene->l);
	init_stack(&scene->shapes);
	return ;
}
