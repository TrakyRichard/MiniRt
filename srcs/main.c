/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:25:14 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/02/19 12:50:34 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	close_function(const t_window *w)
{
	mlx_clear_window(w->mlx->mlx_ptr, w->mlx->win_ptr);
	mlx_destroy_window(w->mlx->mlx_ptr, w->mlx->win_ptr);
	//free(mlx);
	exit(0);
}

int	key_function(const int keycode, const t_window *w)
{
	clock_t start, end;
	printf("%i\n", keycode);
	if (keycode == ESC || keycode == KEY_Q)
		close_function(w);
	else if (keycode == LEFT)
	{
		mlx_clear_window(w->mlx->mlx_ptr, w->mlx->win_ptr);
		mlx_put_image_to_window(w->mlx->mlx_ptr, w->mlx->win_ptr, w->img->img_ptr, 0, 0);
	}
	else if (keycode == RIGHT)
	{
		mlx_clear_window(w->mlx->mlx_ptr, w->mlx->win_ptr);
		//mlx_put_image_to_window(w->mlx->mlx_ptr, w->mlx->win_ptr, w->img2->img_ptr, 0, 0);
	}
	if (keycode == KEY_S)
	{
		start = clock();
		save_bmp(screenshot_datetime(), w->img->data, w->scene->resolution);
		end = clock();
		printf("save_img:\t%fs\n",((double) (end - start)) / CLOCKS_PER_SEC);
	}
	return (0);
}

t_mlx	*malloc_mlx_init(void)
{
	t_mlx		*mlx;

	mlx = malloc(sizeof(*mlx));
	if (!mlx)
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		print_err_and_exit("Minilibx error", MLX_ERROR);
	return (mlx);
}

t_img	*init_img(t_mlx *mlx, t_couple *resolution)
{
	t_img		*img;
	int			w;
	int			h;

	img = malloc(sizeof(*img));
	if (!img)
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	w = 1080;
	h = 720;
	// mlx_get_screen_size(mlx->mlx_ptr, &w, &h);
	// if (w < resolution->w)
	// 	resolution->w = w;
	// if (h < resolution->h)
	// 	resolution->h = h;
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, resolution->w, resolution->h);
	if (!img->img_ptr)
		print_err_and_exit("Minilibx error", MLX_ERROR);
	img->data = (unsigned char*)mlx_get_data_addr(img->img_ptr, &(img->bits_per_pixel), &(img->size_line), &(img->endian));
	if (!img->data)
		print_err_and_exit("Minilibx error", MLX_ERROR);
	return (img);
}

void	get_controls_loop(t_mlx *mlx, t_img *img, t_scene *scene)
{
	t_window	*window;

	window = malloc(sizeof(*window));
	if (!window)
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	window->mlx = mlx;
	window->img = img;
	window->scene = scene;
	mlx_hook(mlx->win_ptr, 17, 1L<<17, close_function, window);
	mlx_key_hook(mlx->win_ptr, key_function, window);
	mlx_loop(mlx->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_img		*img;
	t_scene		*scene;
	clock_t		start, end;

	if (argc < 2 || argc > 3)
		print_err_and_exit("Wrong number of arguments", WRONG_ARGS);
	start = clock();
	scene = parse_rt(argv[1]);
	end = clock();
	printf("parse_rt:\t%fs\n",((double) (end - start)) / CLOCKS_PER_SEC);
	mlx = malloc_mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, scene->resolution->w, scene->resolution->h, "miniRT");
	if (!mlx->win_ptr)
		print_err_and_exit("Minilibx error", MLX_ERROR);
	img = init_img(mlx, scene->resolution);
	start = clock();
	render(img, scene);
	end = clock();
	printf("render:\t\t%fs\n",((double) (end - start)) / CLOCKS_PER_SEC);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 0, 0);
	get_controls_loop(mlx, img, scene);
	return (0);
}
