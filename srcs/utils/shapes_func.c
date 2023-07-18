/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:20:26 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/07/13 07:34:29 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_b shapes_intersect(t_intx *intx, t_sh *shape)
{
    t_b intersected;

    intersected = false;
    while (shape)
    {
        if (shape->type == SPHERE && sphere_intersect(intx, (t_sp *)shape->i))
            intersected = true;
        else if (shape->type == PLANE && plane_intersect(intx, (t_pl *)shape->i))
            intersected = true;
        else if (shape->type == SQUARE && ((t_sq *)shape)->intersect(intx, (t_sq *)shape->i))
            intersected = true;
        else if (shape->type == CYLINDER && ((t_cy *)shape)->intersect(intx, (t_cy *)shape->i))
            intersected = true;
        else if (shape->type == TRIANGLE && ((t_tr *)shape)->intersect(intx, (t_tr *)shape->i))
            intersected = true;
        else if (shape->type == DISK && ((t_di *)shape)->intersect(intx, (t_di *)shape->i))
            intersected = true;
        shape = shape->next;
    }
    return (intersected);
}


/* TODO: Come and personalize this */
t_b does_shapes_intersect(t_ray *ray, t_sh *shape)
{
    t_b does_intersect;

    does_intersect = false;
    while (shape)
    {
        if (shape->type == SPHERE && ((t_sp *)shape)->does_intersect(ray, (t_sp *)shape))
            return (true);
        else if (shape->type == PLANE && ((t_pl *)shape)->does_intersect(ray, (t_pl *)shape))
            return (true);
        else if (shape->type == SQUARE && ((t_sq *)shape)->does_intersect(ray))
            return (true);
        else if (shape->type == CYLINDER && ((t_cy *)shape)->does_intersect(ray))
            return (true);
        else if (shape->type == TRIANGLE && ((t_tr *)shape)->does_intersect(ray))
            return (true);
        else if (shape->type == DISK && ((t_di *)shape)->does_intersect(ray))
            return (true);
        shape = shape->next;
    }
    return (does_intersect);
}
