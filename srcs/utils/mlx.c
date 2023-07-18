/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:20:26 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/07/01 10:02:44 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int close_function(t_sc *sc)
{
    mlx_clear_window(sc->mlx->mlx_ptr, sc->mlx->win_ptr);
    mlx_destroy_window(sc->mlx->mlx_ptr, sc->mlx->win_ptr);
    // free(mlx);
    exit(0);
}

int key_function(const int keycode, t_sc *sc)
{
    // clock_t start, end;
    printf("%i\n", keycode);
    if (keycode == ESC || keycode == KEY_Q)
        close_function(sc);
    else if (keycode == LEFT)
    {
        mlx_clear_window(sc->mlx->mlx_ptr, sc->mlx->win_ptr);
        mlx_put_image_to_window(sc->mlx->mlx_ptr, sc->mlx->win_ptr, sc->img->img_ptr, 0, 0);
    }
    else if (keycode == RIGHT)
    {
        mlx_clear_window(sc->mlx->mlx_ptr, sc->mlx->win_ptr);
        // mlx_put_image_to_window(w->mlx->mlx_ptr, w->mlx->win_ptr, w->img2->img_ptr, 0, 0);
    }
    if (keycode == KEY_S)
    {
        // start = clock();
        // save_bmp(screenshot_datetime(), img->data, r->resolution);
        // end = clock();
        // printf("save_img:\t%fs\n",((double) (end - start)) / CLOCKS_PER_SEC);
    }
    return (0);
}

void malloc_mlx_init(t_sc *sc)
{
    if (!(sc->mlx = malloc(sizeof(*sc->mlx))))
        ft_error("Malloc failed");
    if (!(sc->mlx->mlx_ptr = mlx_init()))
        ft_error("Minilibx error");
    return;
}

void init_img(t_sc *sc)
{
    int w;
    int h;

    if (!(sc->img = malloc(sizeof(*sc->img))))
        ft_error("Malloc failed");
    w = 1080;
    h = 720;
    // mlx_get_screen_size(mlx->mlx_ptr, &w, &h);
    if (w > sc->r.w)
        sc->r.w = w;
    if (h > sc->r.h)
        sc->r.h = h;
    if (!(sc->img->img_ptr = mlx_new_image(sc->mlx->mlx_ptr, sc->r.w, sc->r.h)))
        ft_error("Minilibx error");
    if (!(sc->img->data = (unsigned char *)mlx_get_data_addr(sc->img->img_ptr, &(sc->img->bits_per_pixel), &(sc->img->size_line), &(sc->img->endian))))
        ft_error("Minilibx error");
    return;
}

void get_controls_loop(t_mlx *mlx, t_sc *sc)
{
    mlx_hook(mlx->win_ptr, 17, 1L << 17, close_function, sc);
    mlx_key_hook(mlx->win_ptr, key_function, sc);
    mlx_loop(mlx->mlx_ptr);
}
