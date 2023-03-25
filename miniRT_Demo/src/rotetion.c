/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotetion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:25:57 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 14:28:56 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#include <math.h>

#define PI 3.14159265358979323846

typedef struct s_vec3
{
	float x;
	float y;
	float z;
} t_vec3;

typedef struct s_triangle
{
	t_vec3 a;
	t_vec3 b;
	t_vec3 c;
} t_triangle;

typedef struct s_mesh
{
	t_triangle *triangles;
	size_t size;
} t_mesh;

void rotate_x(float *y, float *z, float angle)
{
	float rad = angle * PI / 180.0;
	float cos_a = cosf(rad);
	float sin_a = sinf(rad);
	float new_y = *y * cos_a - *z * sin_a;
	float new_z = *y * sin_a + *z * cos_a;
	*y = new_y;
	*z = new_z;
}

void rotate_y(float *x, float *z, float angle)
{
	float rad = angle * PI / 180.0;
	float cos_a = cosf(rad);
	float sin_a = sinf(rad);
	float new_x = *x * cos_a + *z * sin_a;
	float new_z = -*x * sin_a + *z * cos_a;
	*x = new_x;
	*z = new_z;
}

void rotate_z(float *x, float *y, float angle)
{
	float rad = angle * PI / 180.0;
	float cos_a = cosf(rad);
	float sin_a = sinf(rad);
	float new_x = *x * cos_a - *y * sin_a;
	float new_y = *x * sin_a + *y * cos_a;
	*x = new_x;
	*y = new_y;
}

float rad_to_deg(float rad)
{
	return rad * 180.0 / PI;
}

int sign(float x)
{
	return (x >= 0) ? 1 : -1;
}

t_vec3 direction_to_angle(t_vec3 dir)
{
	float sqrt_result = sqrtf(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
	float angle_xy = atan2f(dir.y, dir.x);
	float angle_yz = acosf(dir.z / sqrt_result);
	return (t_vec3 {rad_to_deg(angle_xy), rad_to_deg(angle_yz), 0});
}

void rotate(t_mesh *mesh, float angle, int axis)
{
	size_t i;

	i = -1;
	while (++i < mesh->size)
	{
		t_triangle *triangle = &mesh->triangles[i];
		if (axis == 0)
		{
			rotate_x(&triangle->a.y, &triangle->a.z, angle);
			rotate_x(&triangle->b.y, &triangle->b.z, angle);
			rotate_x(&triangle->c.y, &triangle->c.z, angle);
		}
		else if (axis == 1)
		{
			rotate_y(&triangle->a.x, &triangle->a.z, angle);
			rotate_y(&triangle->b.x, &triangle->b.z, angle);
			rotate_y(&triangle->c.x, &triangle->c.z, angle);
		}
		else if (axis == 2)
		{
			rotate_z(&triangle->a.x, &triangle->a.y, angle);
			rotate_z(&triangle->b.x, &triangle->b.y, angle);
			rotate_z(&triangle->c.x, &triangle->c.y, angle);
		}
	}
}

