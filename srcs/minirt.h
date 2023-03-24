/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:42:20 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/24 06:23:07 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

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
}	t_mrt;

# include "./vec/vec.h"
# include "./color/col.h"
# include "./ray/ray.h"


#endif
