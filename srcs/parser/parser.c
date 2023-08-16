/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:20:44 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/16 03:13:28 by rkanmado         ###   ########.fr       */
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

typedef struct s_parser
{
	char	*line;
	int		count;
}	t_p;

void	init_parser(t_p *p, int fd)
{
	p->line = get_next_line(fd);
	p->count = 0;
	return ;
}

t_b	parse(int fd, t_sc *sc)
{
	t_p	p;

	init_parser(&p, fd);
	while (p.line != NULL)
	{
		if (*p.line == '\n')
			p.count++ ;
		if (p.line[0] == '#' || *p.line == '\n')
		{
			free(p.line);
			p.line = get_next_line(fd);
			continue ;
		}
		if (p.count > 3 || p.line[0] == '\0')
			break ;
		if (parsing_process(p.line, sc) == false)
		{
			free_scene(sc);
			return (ft_error("Parsing error\n"));
		}
		free(p.line);
		init_parser(&p, fd);
	}
	free(p.line);
	return (true);
}
