/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:20:44 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/13 12:31:03 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "parser.h"

t_b	parsing_process(char *line, t_sc *sc)
{
	if (line[0] == 'R')
		return (parse_resolution(line, sc));
	else if (line[0] == 'A')
		return (parse_ambient(line, sc));
	else if (line[0] == 'c' && line[1] == 'y')
		return (parse_cylinder(line, sc));
	else if (ft_tolower(line[0]) == 'c' && (line[1] == ' ' || line[1] == '\t'))
		return (parse_camera(line, sc));
	else if (ft_tolower(line[0]) == 'l' && (line[1] == ' ' || line[1] == '\t'))
		return (parse_light(line, sc));
	else if (line[0] == 's' && line[1] == 'p')
		return (parse_sphere(line, sc));
	else if (line[0] == 'p' && line[1] == 'l')
		return (parse_plane(line, sc));
	else if (line[0] == 's' && line[1] == 'q')
		return (parse_square(line, sc));
	else if (line[0] == 't' && line[1] == 'r')
		return (parse_triangle(line, sc));
	else
		return (false);
}

t_b	parse(int fd, t_sc *sc)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*line == '\n')
			count++ ;
		if (line[0] == '#' || *line == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (count > 3 || line[0] == '\0')
			break ;
		if (parsing_process(line, sc) == false)
		{
			free_scene(sc);
			return (ft_error("Parsing error\n"));
		}
		count = 0;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (true);
}
