/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:04:01 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/25 09:39:41 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	write_color(t_rgb color)
{
	printf("%d ", (int)(255.999 * color.r));
	printf("%d ", (int)(255.999 * color.g));
	printf("%d", (int)(255.999 * color.b));
	printf("\n");
	return ;
}

t_rgb	ray_color(t_ray *ray)
{
	t_vec3	unit_direction = unit_vector(ray->dir);
	double	t = 0.5 * (unit_direction.y + 1.0);
	t_rgb a = col_multi_with_d(set_col(1.0, 1.0, 1.0), 1.0 - t);
	t_rgb b = col_multi_with_d(set_col(0.5, 0.7, 1.0), t);

	return (col_addition(&a, &b));
}

void	render(t_mrt *mrt)
{
	int	j;
	int	i;

	printf("P3\n%d %d\n255\n", mrt->iw, mrt->ih);
	j = mrt->ih - 1;
	i = 0;
	while (--j >= 0)
	{
		while (++i < mrt->iw)
		{
			double u = (double)i / (mrt->iw - 1);
			double v = (double)j / (mrt->ih - 1);
			init_ray(&mrt->ray);
			set_ray(&mrt->ray, vec_minus(vec_addition(vec_addition \
					(mrt->lower_lc, vec_multi_with_d(mrt->hor, u)), \
					vec_multi_with_d(mrt->ver, v)), mrt->origin), mrt->origin);
			t_rgb rgb = ray_color(&mrt->ray);
			write_color(rgb);
		}
	}
}
