/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interset_triangles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:28:13 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 14:04:03 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int det_check(double det, double u, double v) {
    if (det > EPSILON) {
        if (u < 0.0 || u > det)
            return 0;
        if (v < 0.0 || (u + v) > det)
            return 0;
    } else if (det < -EPSILON) {
        if (u > 0.0 || u < det)
            return 0;
        if (v > 0.0 || (u + v) < det)
            return 0;
    } else {
        return 0;
    }
    return 1;
}

int intersect_triangle(t_ray ray, t_triangle tri, double *t, double *u, double *v) {
    t_vec3 edge1 = sub(tri.b, tri.a);
    t_vec3 edge2 = sub(tri.c, tri.a);
    t_vec3 pvec = cross(ray.direction, edge2);
    double det = dot(edge1, pvec);
    if (det > -EPSILON && det < EPSILON) {
        return 0;
    }
    double inv_det = 1.0 / det;
    t_vec3 tvec = sub(ray.origin, tri.a);
    *u = dot(tvec, pvec) * inv_det;
    if (*u < 0.0 || *u > 1.0) {
        return 0;
    }
    t_vec3 qvec = cross(tvec, edge1);
    *v = dot(ray.direction, qvec) * inv_det;
    if (*v < 0.0 || (*u + *v) > 1.0) {
        return 0;
    }
    *t = dot(edge2, qvec) * inv_det;
    return 1;
}

int intersect_triangles(t_ray ray, t_triangle *tris, int num_tris, double *t_min, double *u_min, double *v_min) {
    int hit = 0;
    double t, u, v;
    *t_min = INFINITY;
    while(num_tris--) {
		if (intersect_triangle(ray, *tris, &t, &u, &v) && t > EPSILON && t < *t_min) {
			*t_min = t;
			*u_min = u;
			*v_min = v;
			hit = 1;
		}
		tris++;
	}
}
