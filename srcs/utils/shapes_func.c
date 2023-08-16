/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:20:26 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/08/16 02:46:23 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

/* Function to free shape to stack */
void	ft_free_shape(t_st *shape)
{
	if (shape->head == NULL)
		return ;
	while (shape->size > 0)
		ft_pop(shape);
	return ;
}

/* Function to freeze stack */
void	free_scene(t_sc *scene)
{
	if (scene->shapes.size > 0)
		ft_free_shape(&scene->shapes);
	if (scene->l.size > 0)
		ft_free_shape(&scene->l);
	return ;
}
