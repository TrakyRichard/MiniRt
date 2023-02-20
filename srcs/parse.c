/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:05:37 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/02/19 12:50:39 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void *init_scene(t_scene *scene)
{
	scene->resolution = (t_resolution){ 0, 0 };
	scene->al = (t_ambient_light){ 0, (t_color){ 0, 0, 0 } };
	scene->cameras = ft_lstnew(NULL);
	scene->lights = ft_lstnew(NULL);
	scene->spheres = ft_lstnew(NULL);
	scene->planes = ft_lstnew(NULL);
	scene->squares = ft_lstnew(NULL);
	scene->cylinders = ft_lstnew(NULL);
	scene->triangles = ft_lstnew(NULL);
	return (scene);
}

bool check_line(const char *line, char **data, const char *type, const int nb_elements)
{
	bool is_valid = false;
	if (!ft_strcmp(data[0], type))
	{
		is_valid = ft_in_charset(line[ft_strlen(type)], WHITE_SPACES) &&
			(ft_tab_size(data) == nb_elements);
	}
	return is_valid;
}

t_scene *parse(int fd)
{
	t_scene *scene = malloc(sizeof(*scene));
	if (!scene)
		print_err_and_exit("Malloc failed", MALLOC_ERROR);

	init_scene(scene);
	char *line;
	int ret;
	char **data;

	while ((ret = get_next_line(&line, fd)) == 1)
	{
		data = ft_split_set((*line ? line : "iamcheating"), WHITE_SPACES);
		if (check_line(line, data, "R", NB_ELEM_RESOLUTION) && !scene->resolution.w)
			set_resolution(scene, data);
		else if (check_line(line, data, "A", NB_ELEM_AL) && !scene->al.ratio)
			set_ambient_light(scene, data);
		else if (check_line(line, data, "c", NB_ELEM_CAMERA))
			set_camera(scene, data);
		else if (check_line(line, data, "l", NB_ELEM_LIGHT))
			set_light(scene, data);
		else if (check_line(line, data, "sp", NB_ELEM_SPHERE))
			set_sphere(scene, data);
		else if (check_line(line, data, "pl", NB_ELEM_PLANE))
			set_plane(scene, data);
		else if (check_line(line, data, "sq", NB_ELEM_SQUARE))
			set_square(scene, data);
		else if (check_line(line, data, "cy", NB_ELEM_CYLINDER) || check_line(line, data, "cy", NB_ELEM_CYLINDER + 1))
			set_cylinder(scene, data);
		else if (check_line(line, data, "tr", NB_ELEM_TRIANGLE))
			set_triangle(scene, data);
		else if (!ft_is_from_charset(line, WHITE_SPACES))
			print_err_and_exit("Parse error", PARSE_ERROR);

		free(line);
		free(data);
	}

	if (ret == -1)
		print_err_and_exit(strerror(errno), errno);

	return scene;
}

t_scene *get_scene(const int argc, char *argv[])
{
	t_scene *scene = NULL;
	int fd = 0;
	if (argc == 3 && !ft_strcmp(argv[2], "--save"))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			print_err_and_exit(strerror(errno), errno);
		scene = parse(fd);
		close(fd);
	}
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			print_err_and_exit(strerror(errno), errno);
		scene = parse(fd);
		close(fd);
	}
	else
		print_err_and_exit("Usage: ./miniRT <scene.rt> [--save]", USAGE_ERROR);
	return scene;
}

