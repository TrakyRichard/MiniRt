/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ppm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:40:25 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 15:15:55 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double clamp(double num, double low, double high) {
    return fmax(low, fmin(num, high));
}

int rgb_to_int(int r, int g, int b) {
    return (b + g * 256 + r * 256 * 256);
}

void write_color(t_gen *gen, t_vec3 px_color, t_vec3 xy, int samples) {
    double r = sqrt(px_color.x / samples);
    double g = sqrt(px_color.y / samples);
    double b = sqrt(px_color.z / samples);
    int color = rgb_to_int(
        clamp(r * 256, 0.0, 255.999),
        clamp(g * 256, 0.0, 255.999),
        clamp(b * 256, 0.0, 255.999)
    );
    mlx_pixel_put(gen->mlx, gen->win, xy.x, xy.y, color);
}
