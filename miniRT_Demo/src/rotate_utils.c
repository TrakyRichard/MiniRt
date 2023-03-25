/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:21:39 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 14:23:08 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "minirt.h"

void rotate_x(double *y, double *z, double angle)
{
double rad;
double cos_a;
double sin_a;
double new_y;
double new_z;

rad = angle * M_PI / 180.0;
cos_a = cos(rad);
sin_a = sin(rad);
new_y = *y * cos_a - *z * sin_a;
new_z = *y * sin_a + *z * cos_a;
*y = new_y;
*z = new_z;
}

void rotate_y(double *x, double *z, double angle)
{
double rad;
double cos_a;
double sin_a;
double new_x;
double new_z;

rad = angle * M_PI / 180.0;
cos_a = cos(rad);
sin_a = sin(rad);
new_x = *x * cos_a + *z * sin_a;
new_z = -*x * sin_a + *z * cos_a;
*x = new_x;
*z = new_z;
}

void rotate_z(double *x, double *y, double angle)
{
double rad;
double cos_a;
double sin_a;
double new_y;
double new_x;

rad = angle * M_PI / 180.0;
cos_a = cos(rad);
sin_a = sin(rad);
new_x = *x * cos_a - *y * sin_a;
new_y = *x * sin_a + *y * cos_a;
*x = new_x;
*y = new_y;
}
