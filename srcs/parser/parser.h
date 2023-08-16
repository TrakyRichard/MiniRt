/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:20:44 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/13 10:31:30 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minirt.h"

/* Parse elements */
t_b parse_resolution(char *line, t_sc *sc);
t_b parse_ambient(char *line, t_sc *sc);
t_b parse_camera(char *line, t_sc *sc);
t_b parse_light(char *line, t_sc *sc);
t_b parse_sphere(char *line, t_sc *sc);
t_b parse_plane(char *line, t_sc *sc);
t_b parse_square(char *line, t_sc *sc);
t_b parse_cylinder(char *line, t_sc *sc);
t_b parse_triangle(char *line, t_sc *sc);
t_b parse_disk(char *line, t_sc *sc);

/* Parse */
t_b parsing_process(char *line, t_sc *sc);
t_b parse(int fd, t_sc *sc);

#endif
