/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:41:57 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/02/19 12:51:09 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_vect new_vect(const double x, const double y, const double z)
{
    return (t_vect) {x, y, z};
}

double distance(const t_vect p1, const t_vect p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
}

t_vect normalize(const t_vect vect)
{
    double length = distance((t_vect){0,0,0}, vect);
    return (t_vect) {vect.x / length, vect.y / length, vect.z / length};
}

t_vect mult_mat(const double mat[3][3], const t_vect vect)
{
    double x = mat[0][0] * vect.x + mat[0][1] * vect.x + mat[0][2] * vect.x;
    double y = mat[1][0] * vect.y + mat[1][1] * vect.y + mat[1][2] * vect.y;
    double z = mat[2][0] * vect.z + mat[2][1] * vect.z + mat[2][2] * vect.z;
    return (t_vect) {x, y, z};
}

t_vect rot_vect(const t_vect vect, const double angle, const char axe)
{
    double alpha = to_rad(angle * 0.5);
    double s = sin(alpha), c = cos(alpha);
    switch(axe) {
        case 'x': return mult_mat((double[3][3]){{1,0,0}, {0,c,-s}, {0,s,c}}, vect);
        case 'y': return mult_mat((double[3][3]){{c,0,s}, {0,1,0}, {-s,0,c}}, vect);
        case 'z': return mult_mat((double[3][3]){{c,-s,0}, {s,c,0}, {0,0,1}}, vect);
        default: return (t_vect) {0, 0, 0};
    }
}

t_vect add_vect(const t_vect vect1, const t_vect vect2)
{
    return (t_vect) {vect1.x + vect2.x, vect1.y + vect2.y, vect1.z + vect2.z};
}

t_vect sub_vect(const t_vect vect1, const t_vect vect2)
{
    return (t_vect) {vect1.x - vect2.x, vect1.y - vect2.y, vect1.z - vect2.z};
}

t_vect minus_vect(const t_vect vect)
{
    return (t_vect) {-vect.x, -vect.y, -vect.z};
}

t_vect multi_vect(const t_vect vect, const double x)
{
    return (t_vect) {vect.x * x, vect.y * x, vect.z * x};
}

double dot_product(const t_vect vect1, const t_vect vect2)
{
    return vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z;
}

t_vect cross_product(const t_vect v1, const t_vect v2)
{
    double cx = v1.y * v2.z - v1.z * v2.y;
    double cy = v1.z * v2.x - v1.x * v2.z;
    double cz = v1.x * v2.y - v1.y * v2.x;
	return (t_vect) {cx, cy, cz};
}
