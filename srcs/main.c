/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:25:14 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/08/07 01:52:27 by rkanmado         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_sc	sc;
	int		fd;
	char	*title_window;

	check_args(argc, argv);
	init_scene(&sc);
	fd = open_file(argv[1]);
	parse(fd, &sc);
	malloc_mlx_init(&sc);
	init_img(&sc);
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
	return (0);
}
