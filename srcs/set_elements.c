/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:32:56 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/02/19 12:50:54 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	check_resolution(char **data)
{
	return (ft_atoi_strict(data[1]) <= 0 || ft_atoi_strict(data[2]) <= 0);
}

void	set_resolution(t_scene *scene, char **data)
{
	if (check_resolution(data))
		print_err_and_exit("resolution (R) must be 2 positive numbers", 20);
	t_couple	*resolution = malloc(sizeof(*resolution));
	resolution->w = ft_atoi_strict(data[1]);
	resolution->h = ft_atoi_strict(data[2]);
	scene->resolution = *resolution;
}

void	set_ambient_light(t_scene *scene, char **data)
{
	t_ambient_light	*ambient_light = malloc(sizeof(*ambient_light));
	ambient_light->color = *mult_rgb_double(str_to_rgb(data[2]), ft_atof(data[1]));
	scene->al = *ambient_light;
}

void	set_camera(t_scene *scene, char **data)
{
	t_camera	*camera = malloc(sizeof(*camera));
	camera->pos = str_to_vect(data[1]);
	camera->orientation = normalize(str_to_vect(data[2]));
	camera->up = new_vect(0, 1, 0);
	camera->fov = ft_atof(data[3]);
	ft_lstadd_front(&(scene->cameras), ft_lstnew(camera));
}

void	set_light(t_scene *scene, char **data)
{
	t_light		*light = malloc(sizeof(*light));
	light->pos = str_to_vect(data[1]);
	light->color = *mult_rgb_double(str_to_rgb(data[3]), ft_atof(data[2]) * 255);
	ft_lstadd_front(&(scene->lights), ft_lstnew(light));
}
