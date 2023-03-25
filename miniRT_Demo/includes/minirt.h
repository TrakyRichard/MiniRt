/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:50:33 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 15:17:53 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define PI 3.1415926
# define MYRAND_MAX 0xFFFF
# define IMAX 2147483647
# define EPSILON 0.000001
# define SECTOR 40
# define KEY_ESC 53


# include "read.h"
#include <math.h>

typedef struct s_object t_object;

typedef struct s_point
{
	t_vec3			center;
	double			brightness;
	t_vec3			color;
}					t_point;

typedef struct s_img
{
	int				width;
	int				height;
	double			a_ratio;

}					t_img;

typedef struct s_cyl
{
	t_vec3			origin;
	t_vec3			color;
	t_vec3			dir;
	double			r;
	double			h;
	double			size;

}					t_cyl;

typedef struct s_ray
{
	t_vec3			origin;
	t_vec3			direction;
}					t_ray;

typedef struct s_triangle
{
	t_vec3			a;
	t_vec3			b;
	t_vec3			c;
	t_vec3			normal;
}					t_triangle;

typedef struct s_mesh
{
	t_triangle		*triangles;
	int				size;
}					t_mesh;

typedef struct s_object
{
	char			*name;
	t_mesh			*mesh;
	t_vec3			center;
	t_vec3			direction;
	t_vec3			color;
}					t_object;

typedef struct s_scene
{
	t_object		object;
	struct s_scene	*next;
	struct s_scene	*prev;
}					t_scene;

typedef struct s_cam
{
	double			v_h;
	double			v_w;
	double			fl;
	t_vec3			origin;
	t_vec3			horizontal;
	t_vec3			vertical;
	t_vec3			lower_left;
	int				win_x;
	int				win_y;
}					t_cam;

typedef struct s_gen
{
	t_cam			cam;
	t_point			light;
	t_vec3			ambient_color;
	double			ambient_ratio;
	t_vec3			ambient_salt;
	t_scene			*scene;
	void			*mlx;
	void			*win;
}					t_gen;

typedef struct s_th
{
	pthread_t		thread;
	pthread_mutex_t	*mutex;
	int				id;
	t_gen			*gen;
	int				h;
	int				w;
}	t_th;

typedef struct s_hit
{
	double			t;
	void			*obj;
	t_vec3			p;
	t_vec3			normal;
	t_vec3			color;
	int				front_face;
	double			u;
	double			v;
}					t_hit;

typedef struct s_image
{
	double			aspect_ratio;
	t_vec3			origin;
	t_vec3			dir;
	t_vec3			vup;
	float			fow;
	float			fl;
}					t_image;

typedef struct s_elements
{
	t_vec3			edge1;
	t_vec3			edge2;
	t_vec3			tvec;
	t_vec3			pvec;
	t_vec3			qvec;
	double			det;
	double			inv_det;
}					t_elements;

typedef struct s_render_utils
{
	int				i;
	int				j;
	int				h;
	double			u;
	double			v;
	int				end;
	int				till;
	t_vec3			curcol;
	t_vec3			optimum;
	t_vec3			temp;
	t_ray			ray_s;
}					t_render_utils;

typedef struct s_utils
{
	float pi;
	float di;
	float dj;
	float db;
	float da;
	float i;
	float j;
} t_utils;

typedef struct s_square
{
	t_vec3 p1;
	t_vec3 p2;
	t_vec3 p3;
	t_vec3 p4;
} t_square;

//camera

void	init_cam(t_gen *gen, t_image img);

//cly

void	caps(t_vec3 *bot, t_vec3 *top, t_mesh *mmes, t_cyl *data);
void	sectors(t_vec3 *bot, t_vec3 *top, t_mesh *mmes);
t_mesh 	*make_cylinder(t_cyl *data, t_vec3 center);
int		fill_bottom(t_vec3 *arr, t_cyl *data, int sector_count, float top);
void	cylinder(t_mesh **self, t_cyl *data, t_vec3 center);

//interset_triangles

int det_check(double det, double u, double v);
int intersect_triangle(t_ray ray, t_triangle tri, double *t, double *u, double *v);
int intersect_triangles(t_ray ray, t_triangle *tris, int num_tris, double *t_min, double *u_min, double *v_min);

//lights

t_vec3 point_light(t_gen *gen, t_hit *h, t_point light, t_vec3 color);

//main

void init_img(t_image *img);
void add_objects(t_gen *gen, t_read *read);
void init_light(t_gen *gen, t_read *read);
void initialize_generation(t_generation *generation, t_file_contents *file_contents, t_image *image);
int main(int argc, char **argv);

//mesh

t_mesh	*mesh(void);
void	mesh_append(t_mesh *self, t_triangle const triangle);
void	move_mesh(t_mesh *mesh, t_vec3 const to);

//objects_two

t_triangle	triangle(t_vec3 v1, t_vec3 v2, t_vec3 v3);
void	plane(t_mesh **self, t_cyl *data, t_vec3 center);
t_object	object(char *name, t_vec3 center, t_vec3 color, t_cyl data);

//objects

t_scene *scene_obj(t_object object);
void scene_add_back(t_scene **self, t_scene *newscn);
void calculate_normals(t_mesh *mesh);
t_cyl cyldata(double radius, double height, double size, t_vec3 dir);

//ray

t_ray	cr_ray(t_vec3 origin, t_vec3 direction);
t_vec3	ray_on_at(t_ray ray, double t);
t_vec3	ray_color(t_gen *gen, t_ray ray);

//raytrace

double	reverse_equation(t_ray ray, t_vec3 point);
void	put_info(double *tmin, t_hit *hit, t_scene *temp, int i);
int	check_intersections(t_scene *temp, t_ray ray, t_hit *hit);
int	shadow_ray(t_vec3 l, t_scene *temp, t_ray ray, void *not);

//rendering

void	*render(void *p);
void	pre_render(t_gen *gen, int h, int w);

//rotate_utils

void rotate_x(double *y, double *z, double angle);
void rotate_y(double *x, double *z, double angle);
void rotate_z(double *x, double *y, double angle);

//rotetion

void rotate_x(float *y, float *z, float angle);
void rotate_y(float *x, float *z, float angle);
void rotate_z(float *x, float *y, float angle);
float rad_to_deg(float rad);
int sign(float x);
t_vec3 direction_to_angle(t_vec3 dir);
void rotate(t_mesh *mesh, float angle, int axis);

//scene_works

void add_object_to_scene(t_gen *gen, t_object obj);
void add_cylinder_to_scene(t_gen *gen, t_vec3 center, t_vec3 color, t_cylinder cyl_data);
void add_sphere_to_scene(t_gen *gen, t_vec3 center, t_vec3 color, t_sphere sph_data);
void add_plane_to_scene(t_gen *gen, t_vec3 center, t_vec3 color, t_plane pln_data);

//spheres

t_utils init_utils();
void put_square(t_utils *s, float r, t_mesh *self);
void draw_sphere(double r, t_mesh *self);

//utils

double to_radians(double degree);
double max(double x, double y);
void avoid_norm(t_triangle *tri, t_vec3 *bot, t_vec3 *top, int i);
int key(int keycode, t_gen *gen);
int xbutton(t_gen *gen);

//write_ppm

double clamp(double num, double low, double high);
int rgb_to_int(int r, int g, int b);
void write_color(t_gen *gen, t_vec3 px_color, t_vec3 xy, int samples);

#endif