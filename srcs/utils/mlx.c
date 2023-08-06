/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:20:26 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/08/05 15:30:29 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int close_function(t_sc *sc)
{
	mlx_clear_window(sc->mlx->mlx_ptr, sc->mlx->win_ptr);
	mlx_destroy_window(sc->mlx->mlx_ptr, sc->mlx->win_ptr);
	exit(0);
}

int key_function(const int keycode, t_sc *sc)
{
	printf("%i\n", keycode);
	if (keycode == ESC || keycode == KEY_Q)
		close_function(sc);
	else if (keycode == LEFT)
	{
		mlx_clear_window(sc->mlx->mlx_ptr, sc->mlx->win_ptr);
		mlx_put_image_to_window(sc->mlx->mlx_ptr, sc->mlx->win_ptr, \
		sc->img->img_ptr, 0, 0);
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

void	malloc_mlx_init(t_sc *sc)
{
	if (!(sc->mlx = malloc(sizeof(*sc->mlx))))
		ft_error("Malloc failed");
	if (!(sc->mlx->mlx_ptr = mlx_init()))
		ft_error("Minilibx error");
	return ;
}

void	init_img(t_sc *sc)
{
	sc->img = malloc(sizeof(*sc->img));
	if (!(sc->img))
		ft_error("Malloc failed");
	sc->img->img_ptr = mlx_new_image(sc->mlx->mlx_ptr, sc->r.w, sc->r.h);
	if (!(sc->img->img_ptr))
		ft_error("Minilibx error");
	sc->img->data = (unsigned char *)mlx_get_data_addr(sc->img->img_ptr, \
	&(sc->img->bits_per_pixel), &(sc->img->size_line), &(sc->img->endian));
	if (!(sc->img->data))
		ft_error("Minilibx error");
	return ;
}

void	get_controls_loop(t_mlx *mlx, t_sc *sc)
{
	mlx_hook(mlx->win_ptr, 17, 1L << 17, close_function, sc);
	mlx_key_hook(mlx->win_ptr, key_function, sc);
 	mlx_loop(mlx->mlx_ptr);
}
