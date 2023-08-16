/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:42:20 by rkanmado          #+#    #+#             */
/*   Updated: 2023/08/16 03:07:52 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define RAY_T_MIN 0.0001
# define RAY_T_MAX 1.0e30
# define EPSILON 0.000001
# define ALBEDO 0.3
# define FOCAL_DIST 0.5

# define REFLEC 1
# define DEPTH 1

# define WHITE_SPACES " \t"

# include <stdio.h>
# include <math.h>
# include <stddef.h>
# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"

# include "../libs/libmlx/mlx.h"

typedef struct s_put_color
{
	double	min_t;
	int		x;
	int		y;
}	t_put_color;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}		t_rgb;

typedef struct s_img
{
	void			*img_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	unsigned char	*data;
}		t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}		t_mlx;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}		t_vec3;

typedef enum s_bool
{
	false,
	true,
}		t_b;

typedef struct s_ray
{
	t_vec3	orig;
	t_vec3	dir;
	double	t;
}		t_ray;

typedef enum type_of_shape
{
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	SQUARE,
	CYLINDER,
	DISK,
	TRIANGLE,
	NEIN
}		t_shtype;

typedef struct s_intersection
{
	t_ray		ray;
	double		t;
	void		*i;
	t_shtype	type;
	t_rgb		col;
}		t_intx;

typedef struct s_sphere
{
	t_vec3	center;
	double	radius;
	t_rgb	color;
}		t_sp;

typedef struct s_plane
{
	t_vec3	pos;
	t_vec3	dir;
	t_rgb	color;
}		t_pl;

typedef struct s_square
{
	t_vec3	pos;
	t_vec3	dir;
	double	side_size;
	t_rgb	color;
}		t_sq;

typedef struct s_cylinder
{
	t_vec3	pos;
	t_vec3	dir;
	t_b		is_closed;
	double	radius;
	double	height;
	t_rgb	color;
}		t_cy;

typedef struct s_disk
{
	t_vec3	pos;
	t_vec3	dir;
	double	radius;
	t_rgb	color;
}		t_di;

typedef struct s_triangle
{
	t_vec3	pos1;
	t_vec3	pos2;
	t_vec3	pos3;
	t_rgb	color;
}		t_tr;

typedef struct s_shape
{
	void			*i;
	t_shtype		type;
	struct s_shape	*next;
	struct s_shape	*prev;
}		t_sh;

typedef struct s_sphere_intersect
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	t1;
	double	t2;
}		t_sp_intx;

typedef struct s_square_intersection
{
	double	t;
	t_vec3	edge1;
	t_vec3	edge2;
	t_vec3	intersection_point;
	t_vec3	v;
	double	width;
	double	height;
	double	proj1;
	double	proj2;
}		t_sq_intx;

typedef struct s_cylinder_intersect
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t1;
	double	t2;
	double	t;
	t_vec3	p;
	t_vec3	op;
	double	height;
}		t_cy_intx;

typedef struct s_disk_intersect
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	dist_squared;
	double	t1;
	double	t2;
	double	t;
	t_vec3	p;
	t_vec3	op;
}		t_di_intx;

typedef struct s_triangle_intersection
{
	t_vec3	edge1;
	t_vec3	edge2;
	t_vec3	pvec;
	double	det;
	double	inv_det;
	t_vec3	tvec;
	double	u;
	t_vec3	qvec;
	double	v;
	double	t;
}		t_tr_intx;

typedef struct t_stack
{
	int		size;
	t_sh	*head;
	t_sh	*tail;
}		t_st;

typedef struct s_resolution
{
	int		w;
	int		h;
}		t_r;

typedef struct s_ambient
{
	double	ratio;
	t_rgb	color;
}		t_a;

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	dir;
	t_vec3	up;
	t_vec3	right;
	double	h;
	double	w;
	double	fov;
}		t_c;

typedef struct s_light
{
	t_vec3	pos;
	double	ratio;
	t_rgb	color;
}		t_l;

typedef struct s_manage_light
{
	t_sh	*lights;
	t_rgb	diffuse;
	t_rgb	color_l;
	t_l		*light;
	t_ray	to_light;
	double	normal_dot_light;
}		t_manage_light;

typedef struct s_scene
{
	t_r		r;
	t_a		a;
	t_c		c;
	t_st	l;
	t_st	shapes;
	t_mlx	*mlx;
	t_img	*img;
}		t_sc;

typedef struct s_mini_rt
{
	double	ar;
	int		iw;
	int		ih;
	double	vh;
	double	vw;
	double	fl;
	t_vec3	origin;
	t_vec3	hor;
	t_vec3	ver;
	t_vec3	lower_lc;
	t_ray	ray;
}		t_mrt;

/* # include "./vec/vec.h"
# include "./color/col.h"
# include "./ray/ray.h"
# include "./render/render.h"
# include "./parser/parser.h"
# include "./intersection/intersection.h"
# include "./shape/shape.h" */

# define ESC		65307
# define LEFT		65361
# define RIGHT		65363
# define KEY_S		115
# define KEY_Q		113

void	init_mini_rt(t_mrt *mrt);
void	render(t_sc *scene);
void	write_color(t_rgb color);
int		rgb_to_int(const t_rgb rgb);

/* Error */
t_b		ft_error(char *str);
void	check_args(int arc, char **args);

/* File */
int		open_file(char *file);
void	quit_if_parsing_failed(t_sc *sc);
/* Utils */
void	skip_spaces(char *line, int *i);
void	set_next_int(char *line, int *i, int *value);
void	set_next_double(char *line, int *i, double *value);
t_vec3	str_to_vec3(char *str);
t_rgb	str_to_rgb(char *str);
void	init_scene(t_sc *scene);
double	to_rad(double degrees);
int		ft_min_int(int a, int b);
t_rgb	add_rgb_rgb(const t_rgb rgb, const t_rgb add);
void	min_rgb(t_rgb *color);
float	ft_max_float(const float a, const float b);
size_t	split_length(char **split_array);
t_b		ft_split_error(char *str, char **split_array, char *line);

/* List Ops */
void	ft_unshift(t_st *stack, void *info, t_shtype type);
void	ft_push(t_st *stack, void *info);
void	*ft_pop(t_st *stack);
t_st	duplicate_stack(t_st *stack);
void	init_stack(t_st *stack);
t_b		shapes_intersect(t_intx *intx, t_sh *shape);
t_b		does_shapes_intersect(t_ray *ray, t_sh *shape);

/* mlx */
int		close_function(t_sc *sc);
int		key_function(const int keycode, t_sc *sc);
void	malloc_mlx_init(t_sc *sc);
void	init_img(t_sc *sc);
void	get_controls_loop(t_mlx *mlx, t_sc *sc);

/* test */
void	ray_trace(t_sc scene);
t_b		intersect_triangle(t_intx *intx, t_tr *triangle);
t_b		intersect_disk(t_intx *intx, t_di *disk);
t_b		intersect_cylinder(t_intx *intx, t_cy *cylinder);
t_b		intersect_square(t_intx *intx, t_sq *square);
t_b		intersect_plane(t_intx *intx, t_pl *plane);
t_b		intersect_sphere(t_intx *intx, t_sp *sphere);
t_rgb	calculate_color(t_intx intersection);

/* shape_function */
void	ft_free_shape(t_st *shape);
void	free_scene(t_sc *scene);

#endif
