/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:40:47 by rkanmado          #+#    #+#             */
/*   Updated: 2023/03/02 05:20:26 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minirt.h"
# include <math.h>

void	vec_init(t_vec3 *vec3);
void	vec_addition(t_vec3 *vec, t_vec3 *to_add);
void	vec_multi(t_vec3 *vec, t_vec3 *to_multi);
void	vec_div(t_vec3 *vec, t_vec3 *to_div);
void	vec_minus(t_vec3 *vec, t_vec3 *to_minus);
double	vec_len_squared(t_vec3 *vec);
double	length(t_vec3 *vec);

#endif
