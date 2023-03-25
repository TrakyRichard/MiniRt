/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:39:36 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 14:04:30 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Calculate t value of the intersection point on a ray given a point.
*/
double	reverse_equation(t_ray ray, t_vec3 point)
{
	double	t;
	double	p;

	t = dot(sub(point, ray.origin), ray.direction);
	p = dot(ray.direction, ray.direction);
	return (t / p);
}

/*
** Update hit information with new hit if it is closer than the previous closest hit.
*/
void	put_info(double *tmin, t_hit *hit, t_scene *temp, int i)
{
	if (*tmin == -1 || (hit->t < *tmin && hit->t > 0.0))
	{
		*tmin = hit->t;
		hit->normal = temp->object.mesh->triangles[i].normal;
		hit->obj = &(temp->object);
		hit->color = temp->object.color;
	}
}

/*
** Check if a ray intersects any objects in the scene, and update hit information
** with the closest intersection if one exists.
*/
int	check_intersections(t_scene *temp, t_ray ray, t_hit *hit)
{
	double	tmin;
	int		i;

	tmin = -1;
	while (temp)
	{
		i = -1;
		while (++i < temp->object.mesh->size)
		{
			// Skip triangles whose normals point away from the origin of the ray
			if (dot(temp->object.mesh->triangles[i].normal, ray.direction) >= 0.0)
				continue ;

			// Check for intersection with the triangle
			if (call_back(ray, temp->object.mesh->triangles[i], &hit->t))
				put_info(&tmin, hit, temp, i);
		}
		temp = temp->next;
	}
	if (tmin != -1)
	{
		hit->p = ray_on_at(ray, tmin);
		return (1);
	}
	return (0);
}

/*
** Check if a point is in shadow by casting a ray to the light source and checking
** if it intersects any objects in the scene before reaching the light source.
*/
int	shadow_ray(t_vec3 l, t_scene *temp, t_ray ray, void *not)
{
	t_hit	hit;
	int		i;
	double	t;

	hit.t = -1;
	while (temp)
	{
		// Skip objects that are the same as the one being tested for shadows
		if (&(temp->object) == not)
		{
			temp = temp->next;
			continue ;
		}

		i = 0;
		while (i < temp->object.mesh->size)
		{
			if (call_back(ray, temp->object.mesh->triangles[i], &(hit.t)))
			{
				if (hit.t > 0.0)
				{
					t = reverse_equation(ray, l);
					if (t > hit.t)
						return (1);
				}
			}
			i++;
		}
		temp = temp->next;
	}
	return (0);
}
