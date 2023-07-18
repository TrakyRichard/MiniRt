/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:20:44 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/08 19:50:26 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void parsing_process(char *line, t_sc *sc)
{
    if (line[0] == 'R')
        parse_resolution(line, sc);
    else if (line[0] == 'A')
        parse_ambient(line, sc);
    else if (line[0] == 'c' && line[1] == 'y')
        parse_cylinder(line, sc);
    else if (line[0] == 'c' && (line[1] == ' ' || line[1] == '\t'))
        parse_camera(line, sc);
    else if (line[0] == 'l')
        parse_light(line, sc);
    else if (line[0] == 's' && line[1] == 'p')
        parse_sphere(line, sc);
    else if (line[0] == 'p' && line[1] == 'l')
        parse_plane(line, sc);
    else if (line[0] == 's' && line[1] == 'q')
        parse_square(line, sc);
    else if (line[0] == 't' && line[1] == 'r')
        parse_triangle(line, sc);
    else
        return ;
}

void parse(int fd, t_sc *sc)
{
    char *line;
    int count;

    count = 0;
    sc->shapes.does_intersect = &does_shapes_intersect;
    sc->shapes.intersect = &shapes_intersect;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (count > 3)
            break;
        if (*line == '\n')
            count++;
        if (line[0] == '#' || *line == '\n')
            continue;
        parsing_process(line, sc);
        count = 0;
        free(line);
    }
    // TODO: free line
}
