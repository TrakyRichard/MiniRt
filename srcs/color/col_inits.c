/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_inits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:47:19 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/24 19:28:02 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	col_init(t_rgb *col3)
{
	col3->r = 0;
	col3->g = 0;
	col3->b = 0;
	return ;
}

t_rgb	set_col(double x, double y, double z)
{
	t_rgb	col;

	col.r = x;
	col.g = y;
	col.b = z;
	return (col);
}
