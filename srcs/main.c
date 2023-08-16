/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:25:14 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/08/16 03:15:25 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/miniRT.h"

#include "minirt.h"
#include "./vec/vec.h"
#include "./intersection/intersection.h"
#include "./color/col.h"
#include "./ray/ray.h"
#include "./render/render.h"
#include "./parser/parser.h"

int	rgb_to_int(const t_rgb rgb)
{
	return (((rgb.r & 0xFF) << 16) | ((rgb.g & 0xFF) << 8) | (rgb.b & 0xFF));
}

void	quit_if_parsing_failed(t_sc *sc)
{
	t_b	is_done;

	is_done = true;
	if (sc->r.h == 0 || sc->r.w == 0)
		is_done = ft_error("Resolution not found");
	if (sc->a.ratio == 0)
		is_done = ft_error("Ambient light not found");
	if (sc->a.color.r == -1 || sc->a.color.g == -1 || sc->a.color.b == -1)
		is_done = ft_error("Ambient light color not found");
	if (sc->shapes.size == 0)
		is_done = ft_error("No shapes found");
	if (sc->c.fov == 0)
		is_done = ft_error("Camera FOV not found");
	if (sc->l.size == 0)
		is_done = ft_error("No lights found");
	if (is_done == false)
		exit(1);
}

void	init_scene_and_window(t_sc *sc, int fd)
{
	init_scene(sc);
	if (parse(fd, sc) == false)
		exit(EXIT_FAILURE);
	quit_if_parsing_failed(sc);
	malloc_mlx_init(sc);
	init_img(sc);
	return ;
}

int	main(int argc, char **argv)
{
	t_sc	sc;
	int		fd;
	char	*title_window;

	check_args(argc, argv);
	fd = open_file(argv[1]);
	init_scene_and_window(&sc, fd);
	close(fd);
	ray_trace(sc);
	if (argc == 2)
	{
		title_window = ft_strjoin("miniRT - ", argv[1]);
		sc.mlx->win_ptr = mlx_new_window(sc.mlx->mlx_ptr, \
			sc.r.w, sc.r.h, title_window);
		if (!(sc.mlx->win_ptr))
			ft_error("Minilibx error");
		free(title_window);
		mlx_put_image_to_window(sc.mlx->mlx_ptr, sc.mlx->win_ptr, \
		sc.img->img_ptr, 0, 0);
		get_controls_loop(sc.mlx, &sc);
	}
	free_scene(&sc);
	return (0);
}
