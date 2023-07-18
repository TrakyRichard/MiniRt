/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_inits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:47:19 by rkanmado          #+#    #+#             */
/*   Updated: 2023/05/05 18:10:36 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	init_col(t_rgb *col3)
{
	col3->r = 0;
	col3->g = 0;
	col3->b = 0;
	return ;
}

t_rgb	set_col(int x, int y, int z)
{
	t_rgb	col;

	col.r = x;
	col.g = y;
	col.b = z;
	return (col);
}
