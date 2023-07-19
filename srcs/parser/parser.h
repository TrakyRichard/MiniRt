/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 04:20:44 by rkanmado          #+#    #+#             */
/*   Updated: 2023/07/19 03:46:56 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minirt.h"

/* Parse elements */
void	parse_resolution(char *line, t_sc *sc);
void	parse_ambient(char *line, t_sc *sc);
void	parse_camera(char *line, t_sc *sc);
void	parse_light(char *line, t_sc *sc);
void	parse_sphere(char *line, t_sc *sc);
void	parse_plane(char *line, t_sc *sc);
void	parse_square(char *line, t_sc *sc);
void	parse_cylinder(char *line, t_sc *sc);
void	parse_triangle(char *line, t_sc *sc);
void	parse_disk(char *line, t_sc *sc);

/* Parse */
void	parsing_process(char *line, t_sc *sc);
void	parse(int fd, t_sc *sc);

#endif
