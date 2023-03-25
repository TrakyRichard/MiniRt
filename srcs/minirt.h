/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:42:20 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/25 06:17:32 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./vec/vec.h"
# include "./color/col.h"
# include "./ray/ray.h"
# include <stdio.h>
# include <math.h>

typedef struct s_mini_rt
{
	double	ar;
	int		iw;
	int		ih;
	double	vh;
	double	vw;
	double	fl;
	t_vec3	origin;
	t_vec3	hor;
	t_vec3	ver;
	t_vec3	lower_lc;
	t_ray	ray;
}	t_mrt;

void	init_mini_rt(t_mrt *mrt);
void	render(t_mrt *mrt);
void	write_color(t_rgb color);

#endif
