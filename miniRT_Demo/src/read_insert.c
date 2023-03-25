/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:10:57 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 14:16:03 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/read.h"

void insert_object(void *obj, void **head)
{
    void **temp = head;
    
    while (*temp != NULL)
        temp = &((*temp)->next);
        
    *temp = obj;
}

void insert_sphere(t_read *read, t_sphere *sphere)
{
    insert_object(sphere, (void **)&read->sph_head);
}

void insert_plane(t_read *read, t_plane *plane)
{
    insert_object(plane, (void **)&read->pl_head);
}

void insert_cylinder(t_read *read, t_cylinder *cylinder)
{
    insert_object(cylinder, (void **)&read->cyl_head);
}
