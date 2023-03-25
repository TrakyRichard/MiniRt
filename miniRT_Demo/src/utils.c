/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:39:18 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 14:40:07 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double to_radians(double degree)
{
    return (degree * PI / 180.0);
}

double max(double x, double y)
{
    return (x > y ? x : y);
}

void avoid_norm(t_triangle *tri, t_vec3 *bot, t_vec3 *top, int i)
{
    tri->a = top[i + 1];
    tri->c = bot[i + 1];
}

int key(int keycode, t_gen *gen)
{
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(gen->mlx, gen->win);
        exit(0);
    }
    return (0);
}

int xbutton(t_gen *gen)
{
    mlx_destroy_window(gen->mlx, gen->win);
    exit(0);
}
