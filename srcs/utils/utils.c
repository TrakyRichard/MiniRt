/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:20:26 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/07/19 04:48:00 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	skip_spaces(char *line, int *i)
{
	while (line[*i] == ' ' || line[*i] == '\t')
		*i += 1;
	return ;
}

double	to_rad(double degrees)
{
	return (degrees * (M_PI * 0.5));
}

void	set_next_int(char *line, int *i, int *value)
{
	*value = ft_atoi(line + *i);
	skip_spaces(line, i);
	return ;
}

void	set_next_double(char *line, int *i, double *value)
{
	*value = ft_atof(line + *i);
	skip_spaces(line, i);
	return ;
}

t_vec3	str_to_vec3(char *str)
{
	t_vec3	vec;
	char	**split;

	split = ft_split(str, ",");
	vec.x = ft_atof(split[0]);
	vec.y = ft_atof(split[1]);
	vec.z = ft_atof(split[2]);
	ft_free_dbpt(split);
	return (vec);
}

t_rgb	str_to_rgb(char *str)
{
	t_rgb	rgb;
	char	**split;

	split = ft_split(str, ",");
	rgb.r = ft_atoi(split[0]);
	rgb.g = ft_atoi(split[1]);
	rgb.b = ft_atoi(split[2]);
	ft_free_dbpt(split);
	return (rgb);
}
