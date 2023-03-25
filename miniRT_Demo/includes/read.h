/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:55:20 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 15:07:24 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include "libft.h"
# include "vec3d.h"
# include <pthread.h>
# include <fcntl.h>
# include <stdio.h>

//error codes
# define FILE_ERR 1
# define INVALID_ELEMENT_ERR 2
# define INVALID_RANGE_ERR 3
# define INVALID_ARGUMENTS_ERR 4
# define INVALID_INPUT_ERR 5
# define USAGE_ERR 6
# define INVALID_IDENTIFIER_ERR 7
# define INVALID_FILE_EXT_ERR 8

typedef struct s_sphere
{
	t_vec3				xyz;
	double				diameter;
	t_vec3				rgb;
	struct s_sphere		*next;
}						t_sphere;

typedef struct s_plane
{
	t_vec3				xyz;
	t_vec3				orientation;
	t_vec3				rgb;
	struct s_plane		*next;
}						t_plane;

typedef struct s_cylinder
{
	t_vec3				xyz;
	t_vec3				orientation;
	double				diameter;
	double				height;
	t_vec3				rgb;
	struct s_cylinder	*next;
}						t_cylinder;

typedef struct s_read
{
	double				amb_l_ratio;
	t_vec3				amb_l_rgb;
	t_vec3				cam_xyz;
	t_vec3				cam_orient;
	int					cam_fov;
	t_vec3				lg_xyz;
	double				lg_bright;
	t_vec3				lg_rgb;
	t_sphere			*sph_head;
	t_plane				*pl_head;
	t_cylinder			*cyl_head;
	char				*file;
	int					fd;
	int					amb_l_amount;
	int					cam_amount;
	int					lg_amount;
}						t_read;

//read_check

void check_rage(double min, double max, t_vec3 value, int i);
void check_valid_divided(int expected, char **split, int line_num);
void check_argument_amount(t_read *read, int i);
void is_rt(char *file_name);

//read_elements

void ambient_lightning_read(t_read *read, char **split, int l);
void camera_read(t_read *read, char **split, int l);
void light_read(t_read *read, char **split, int l);

//read_insert

void insert_object(void *obj, void **head);
void insert_sphere(t_read *read, t_sphere *sphere);
void insert_plane(t_read *read, t_plane *plane);
void insert_cylinder(t_read *read, t_cylinder *cylinder);

//read_objects

void read_sphere(t_read *read, char **split, int l);
void read_plane(t_read *read, char **split, int l);
void read_cylinder(t_read *read, char **split, int l);

//read_utils

void free_split_strings(char **strs);
void print_error(char *str, int error_code, int line_num);
t_vec3 parse_vector_from_split(char **strs);

//read

void init_read(t_read *read, char *file);
void identify(char **split, t_read *read, int l);
void read_file(t_read *read);


#endif