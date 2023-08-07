/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:46:21 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/08/06 16:40:37 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../includes/libft.h"
# include "../includes/mlx.h"
// # include "basics.h"
// # include "elements.h"
// # include "scene.h"
// # include "parse.h"

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <time.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

# ifndef THREADS
#  define THREADS 1
# endif

# define OPEN_ERROR -1
# define CLOSE_ERROR -2
# define PARSE_ERROR -3
# define MLX_ERROR -4
# define MALLOC_ERROR -5

# define REFLEC 1
# define DEPTH 1

# define ALBEDO 0.3
# define EPSILON 1e-4

/*
** Keycodes and screen size LINUX and MAC
*/
# ifdef LINUX
#  define ESC		65307
#  define LEFT		65361
#  define RIGHT		65363
#  define KEY_S		115
#  define KEY_Q		113
# else
#  define ESC		53
#  define LEFT		123
#  define RIGHT		124
#  define UP		126
#  define DOWN		125
#  define KEY_A		0
#  define KEY_S		1
#  define KEY_D		2
#  define KEY_W		13
#  define KEY_Q		12
#  define KEY_E		14
#  define KEY_J		38
#  define KEY_K		40
#  define KEY_L		37
#  define KEY_I		34
#  define KEY_U		32
#  define KEY_O		31
#  define KEY_SPACE	49
#  define KEY_PLUS	69
#  define KEY_MINUS	78
# endif

typedef struct s_3D_vector {
	double	x;
	double	y;
	double	z;
}		t_3dv;
typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx;

typedef struct s_img
{
	void			*img_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	unsigned char	*data;
}					t_img;

typedef struct s_scene
{
	t_aabb	aabb;
}	t_scene;

typedef struct s_window
{
	t_mlx		*mlx;
	t_img		*img;
	t_scene		*scene;
}				t_window;

/*
* Shape types
*/

typedef enum s_shape_type {
	sphere,
	plan,
	cylinder,
	square,
	triangle,
	nein
}	t_st;

/*
* Axis aligned bounding box
*/
typedef struct s_aabb
{
	t_3dv	min;
	t_3dv	max;
}	t_aabb;

#endif
