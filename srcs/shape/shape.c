/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:24:51 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/05 09:28:48 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

/* t_b intersect(t_intx *intx, void *shape, t_shtype type)
{
    t_b intersected;
    double t;

    intersected = false;
    t = 0;
    if (type == SPHERE)
        intersected = ((t_sp *)shape)->intersect(intx, (t_sp *)shape);
    else if (type == PLANE)
        intersected = ((t_pl *)shape)->intersect(intx, (t_pl *)shape);
    else if (type == SQUARE)
        intersected = ((t_sq *)shape)->intersect(intx);
    else if (type == CYLINDER)
        intersected = ((t_cy *)shape)->intersect(intx);
    else if (type == TRIANGLE)
        intersected = ((t_tr *)shape)->intersect(intx);
    else if (type == DISK)
        intersected = ((t_di *)shape)->intersect(intx);
    // if (intersected)
    // *intx = set_int(r, sh, sh.col, t);
    return (intersected);
}

t_b does_intersect(t_ray *ray, void *shape, t_shtype type)
{
    t_b intersected;
    double t;

    intersected = false;
    t = 0;
    if (type == SPHERE)
        intersected = ((t_sp *)shape)->does_intersect(ray, (t_sp *)shape);
    else if (type == PLANE)
        intersected = ((t_pl *)shape)->does_intersect(ray, (t_pl *)shape);
    else if (type == SQUARE)
        intersected = ((t_sq *)shape)->does_intersect(ray);
    else if (type == CYLINDER)
        intersected = ((t_cy *)shape)->does_intersect(ray);
    else if (type == TRIANGLE)
        intersected = ((t_tr *)shape)->does_intersect(ray);
    else if (type == DISK)
        intersected = ((t_di *)shape)->does_intersect(ray);
    // if (intersected)
    // *intx = set_int(r, sh, sh.col, t);
    return (intersected);
} */
/* t_b shapes_intersect(t_sc *scene)
{
    t_intx intx;
    t_b intersected;
    t_sh *head;

    intersected = false;
    head = scene->shapes.head;
    while (head)
    {
        if (intersect(&intx, head->i, head->type))
        {
            intersected = true;
            break;
        }
        head = head->next;
    }
    return (intersected);
}

t_b does_shapes_intersect(t_sc *scene)
{
    t_ray ray;
    t_b intersected;
    t_sh *head;

    intersected = false;
    head = scene->shapes.head;
    while (head)
    {
        if (does_intersect(&ray, head->i, head->type))
        {
            intersected = true;
            break;
        }
        head = head->next;
    }
    return (intersected);
}
 */