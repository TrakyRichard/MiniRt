/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   richard.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 05:10:28 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/07 03:51:26 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>
#include "./parser/parser.h"

/* Write the translated [0, 255] of each color component */
void	write_color(t_rgb color)
{
	printf("%d ", (int)(255.999 * color.x));
	printf("%d ", (int)(255.999 * color.y));
	printf("%d", (int)(255.999 * color.z));
	printf("\n");
	return ;
}

int	main(void)
{
	const int	img_width = 256;
	const int	img_height = 256;

	printf("P3\n%d %d\n255\n", img_width, img_height);
	for (int j = img_height; j >= 0; --j)
	{
		for (int i = 0; i < img_width; ++i)
		{
			write_color(set_vec((double)i / (img_width - 1), \
			(double)j / (img_height - 1), 0.25));
		}
	}

}
