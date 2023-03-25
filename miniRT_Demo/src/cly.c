/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cly.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:17:10 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 14:03:59 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void caps(t_vec3 *bot, t_vec3 *top, t_mesh *mmes, t_cyl *data)
{
	int i;

	i = 0;
	while (i < SECTOR)
	{
		mmes->triangles[i].p1 = bot[i];
		mmes->triangles[i].p2 = top[i];
		mmes->triangles[i].p3 = top[i + 1];
		mmes->triangles[i + SECTOR].p1 = bot[i];
		mmes->triangles[i + SECTOR].p2 = top[i + 1];
		mmes->triangles[i + SECTOR].p3 = bot[i + 1];
		i++;
	}
}

void	sectors(t_vec3 *bot, t_vec3 *top, t_mesh *mmes)
{
	t_triangle	*tri;
	int			i;

	i = 0;
	while (i < SECTOR)
	{
		tri = &mmes->triangles[i + SECTOR * 2];
		tri->p1 = bot[i];
		tri->p2 = bot[i + 1];
		tri->p3 = top[i + 1];
		tri = &mmes->triangles[i + SECTOR * 3];
		tri->p1 = bot[i];
		tri->p2 = top[i + 1];
		tri->p3 = top[i];
		i++;
	}
}

t_mesh *make_cylinder(t_cyl *data, t_vec3 center)
{
	t_mesh *mmes;
	t_vec3 *bot;
	t_vec3 *top;
	int i;

	mmes = malloc(sizeof(t_mesh));
	mmes->triangles = malloc(sizeof(t_triangle) * SECTOR * 4);
	bot = malloc(sizeof(t_vec3) * (SECTOR + 1));
	top = malloc(sizeof(t_vec3) * (SECTOR + 1));
	i = 0;
	while (i < SECTOR)
	{
		bot[i].x = data->r * cos(i * 2 * PI / SECTOR);
		bot[i].z = data->r * sin(i * 2 * PI / SECTOR);
		bot[i].y = 0;
		top[i].x = data->r * cos(i * 2 * PI / SECTOR);
		top[i].z = data->r * sin(i * 2 * PI / SECTOR);
		top[i].y = data->h;
		i++;
	}
	bot[i] = bot[0];
	top[i] = top[0];
	caps(bot, top, mmes, data);
	sectors(bot, top, mmes);
	return (mmes);
}

int fill_bottom(t_vec3 *arr, t_cyl *data, int sector_count, float top)
{
    double sector_step = 2 * PI / sector_count;
    int h = 0;
    double degree = sector_step;
    while (sector_count--)
    {
        arr[h].x = data->r * cos(degree);
        arr[h].z = data->r * sin(degree);
        arr[h].y = top;
        h++;
        degree += sector_step;
    }
    return h;
}

void cylinder(t_mesh **self, t_cyl *data, t_vec3 center)
{
    int sector_count = SECTOR;
    t_vec3 *arr = malloc(sizeof(t_vec3) * (sector_count + 1));
    t_vec3 *arr2 = malloc(sizeof(t_vec3) * (sector_count + 1));
    int h1 = fill_bottom(arr, data, sector_count, 0);
    int h2 = fill_bottom(arr2, data, sector_count, data->h);
    t_vec3 directions[3] = { vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1) };
    t_vec3 vectors[3] = { vec3(data->dir.x, 0, data->dir.z), vec3(0, 1, 0), vec3(data->dir.z, 0, -data->dir.x) };
    t_matrix matrix = build_matrix_from_vectors(directions, vectors);
    t_mesh *mesh = make_cylinder(arr, data, arr2);
    free(arr);
    free(arr2);
    transform_mesh(mesh, matrix);
    move_mesh(mesh, add(neg(vec3(0, 0, 0)), center));
    calculate_normals(mesh);
    *self = mesh;
}
