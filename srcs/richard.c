/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   richard.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 05:10:28 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/25 06:18:08 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int	main(void)
{
	t_mrt	mrt;

	init_mini_rt(&mrt);
	render(&mrt);
}


/* Write the translated [0, 255] of each color component */
void	render_color(void)
{
	const int	img_width = 256;
	const int	img_height = 256;

	printf("P3\n%d %d\n255\n", img_width, img_height);
	for (int j = img_height; j >= 0; --j)
	{
		for (int i = 0; i < img_width; ++i)
		{
			write_color(set_col((double)i / (img_width - 1), \
			(double)j / (img_height - 1), 0.25));
		}
	}
}
