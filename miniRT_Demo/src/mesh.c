/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:33:14 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 14:58:33 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct	s_mesh
{
	int			size;
	t_triangle	*triangles;
}				t_mesh;

t_mesh	*mesh(void)
{
	t_mesh	*mesh;

	mesh = malloc(sizeof(t_mesh));
	mesh->size = 0;
	mesh->triangles = NULL;
	return (mesh);
}

void	mesh_append(t_mesh *self, t_triangle const triangle)
{
	t_triangle const	*temp;
	int					i;

	if (!self)
		return ;
	temp = self->triangles;
	self->triangles = malloc(sizeof(t_triangle) * (self->size + 1));
	if (!self->triangles)
	{
		self->triangles = temp;
		return ;
	}
	i = 0;
	while (i < self->size)
	{
		self->triangles[i] = temp[i];
		i++;
	}
	self->triangles[i] = triangle;
	free(temp);
	self->size++;
}

void	move_mesh(t_mesh *mesh, t_vec3 const to)
{
	int	i;

	i = 0;
	while (i < mesh->size)
	{
		mesh->triangles[i].a = add(mesh->triangles[i].a, to);
		mesh->triangles[i].b = add(mesh->triangles[i].b, to);
		mesh->triangles[i].c = add(mesh->triangles[i].c, to);
		i++;
	}
}
