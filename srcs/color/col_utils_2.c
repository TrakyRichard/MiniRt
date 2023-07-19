/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_init_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:34:31 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/18 21:36:51 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_rgb	mult_rgb_rgb(const t_rgb rgb, const t_rgb mult)
{
	return (set_col(rgb.r * (mult.r / 255.), \
	rgb.g * (mult.g / 255.), rgb.b * (mult.b / 255.)));
}
