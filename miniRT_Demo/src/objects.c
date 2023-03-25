/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:36:11 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 14:04:22 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene *scene_obj(t_object object)
{
t_scene *rtn;

rtn = malloc(sizeof(t_scene));
rtn->next = NULL;
rtn->prev = NULL;
rtn->object = object;
return (rtn);
}

void scene_add_back(t_scene **self, t_scene *newscn)
{
t_scene *temp;

if (*self == NULL)
{
	*self = newscn;
	return ;
}
temp = *self;
while (temp->next)
	temp = temp->next;
temp->next = newscn;
newscn->prev = temp;
}

void calculate_normals(t_mesh *mesh)
{
t_vec3 ab;
t_vec3 ac;
t_vec3 norm;
int i;

i = 0;
while (i < mesh->size)
{
	ab = sub(mesh->triangles[i].a, mesh->triangles[i].b);
	ac = sub(mesh->triangles[i].a, mesh->triangles[i].c);
	norm = unit_vector(cross(ac, ab));
	mesh->triangles[i].normal = norm;
	i++;
}
}

t_cyl cyldata(double radius, double height, double size, t_vec3 dir)
{
t_cyl cyldata;

cyldata.dir = unit_vector(dir);
cyldata.r = radius;
cyldata.h = height;
cyldata.size = size;
return (cyldata);
}