#include "minirt.h"

// Function to calculate the color at a given intersection point
t_rgb calculate_color(t_intx intersection)
{
	t_rgb color = {0, 0, 0};

	// Check the type of shape that was intersected
	switch (intersection.type)
	{
	case SPHERE:
	{
		t_sp *sphere = (t_sp *)intersection.i;
		// Perform necessary calculations using sphere properties
		// to determine the color at the intersection point

		// Example calculation:
		// Calculate the normal at the intersection point
		t_vec3 normal = normalized(vec_minus(intersection.ray.orig, sphere->center));
		// Calculate the diffuse component of the color
		double diffuse = fabs(0.5 * (normal.x + normal.y + normal.z));
		// Set the color based on the diffuse component
		color.r = (unsigned char)(sphere->color.r * diffuse);
		color.g = (unsigned char)(sphere->color.g * diffuse);
		color.b = (unsigned char)(sphere->color.b * diffuse);

		break;
	}
	case PLANE:
	{
		t_pl *plane = (t_pl *)intersection.i;
		// Perform necessary calculations using plane properties
		// to determine the color at the intersection point

		// Example calculation:
		// Calculate the normal at the intersection point
		t_vec3 normal = plane->dir;
		// Calculate the diffuse component of the color
		double diffuse = vec_dot(normal, intersection.ray.dir);
		diffuse = fmax(0, diffuse);
		// Set the color based on the diffuse component
		color.r = (unsigned char)(plane->color.r * diffuse);
		color.g = (unsigned char)(plane->color.g * diffuse);
		color.b = (unsigned char)(plane->color.b * diffuse);
		break;
	}
	case SQUARE:
	{
		t_sq *square = (t_sq *)intersection.i;
		// Perform necessary calculations using square properties
		// to determine the color at the intersection point

		// Example calculation:
		// Calculate the normal at the intersection point
		t_vec3 normal = square->dir;
		// Calculate the diffuse component of the color
		double diffuse = vec_dot(normal, intersection.ray.dir);
		diffuse = fmax(0, diffuse);
		// Set the color based on the diffuse component
		color.r = (unsigned char)(square->color.r * diffuse);
		color.g = (unsigned char)(square->color.g * diffuse);
		color.b = (unsigned char)(square->color.b * diffuse);

		break;
	}
	case CYLINDER:
	{
		t_cy *cylinder = (t_cy *)intersection.i;
		// Perform necessary calculations using cylinder properties
		// to determine the color at the intersection point

		// Example calculation:
		// Calculate the normal at the intersection point
		t_vec3 normal = vec_minus(cylinder->pos, intersection.ray.orig);
		normal = normalized(normal);
		// Calculate the diffuse component of the color
		double diffuse = vec_dot(normal, intersection.ray.dir);
		diffuse = fmax(0, diffuse);
		// Set the color based on the diffuse component
		color.r = (unsigned char)(cylinder->color.r * diffuse);
		color.g = (unsigned char)(cylinder->color.g * diffuse);
		color.b = (unsigned char)(cylinder->color.b * diffuse);

		break;
	}
	case DISK:
	{
		t_di *disk = (t_di *)intersection.i;
		// Perform necessary calculations using disk properties
		// to determine the color at the intersection point

		// Example calculation:
		// Calculate the normal at the intersection point
		t_vec3 normal = disk->dir;
		// Calculate the diffuse component of the color
		double diffuse = vec_dot(normal, intersection.ray.dir);
		diffuse = fmax(0, diffuse);
		// Set the color based on the diffuse component
		color.r = (unsigned char)(disk->color.r * diffuse);
		color.g = (unsigned char)(disk->color.g * diffuse);
		color.b = (unsigned char)(disk->color.b * diffuse);

		break;
	}
	case TRIANGLE:
	{
		t_tr *triangle = (t_tr *)intersection.i;
		// Calculate the color using the triangle's color
		color = triangle->color;
		break;
	}
	default:
		break;
	}

	return color;
}

void	ray_trace(t_sc scene)
{
	for (int y = 0; y < scene.r.h; y++)
	{
		for (int x = 0; x < scene.r.w; x++)
		{
			t_ray ray;
			ray.orig = scene.c.pos;
			/* ray.dir = normalized(vec_add(vec_add(scene.c.dir, vec_scale(scene.c.right, u * scene.c.w)), vec_scale(scene.c.up, v * scene.c.h))); */
			ray.dir = set_vect_dir_cam2(scene, x, y);
			ray.t = INFINITY;
			// Find the nearest intersection of the ray with the shapes in the scene
			t_intx intersection;
			intersection.ray = ray;
			intersection.t = INFINITY;
			double min_t = INFINITY;
			t_sh *shape = scene.shapes.head;
			while (shape != NULL)
			{
				if (intersect_shape(&intersection, shape) && intersection.t < min_t)
					min_t = intersection.t;
				shape = shape->next;
			}
			put_color(scene, intersection, min_t, x, y);
		}
	}
}

int	main(int argc, char **argv)
{
	t_sc	sc;
	int		fd;
	char	*title_window;

	check_args(argc, argv);
	init_scene(&sc);
	fd = open_file(argv[1]);
	parse(fd, &sc);
	malloc_mlx_init(&sc);
	init_img(&sc);
	close(fd);
	ray_trace(sc);
	if (argc == 2)
	{
		*title_window = ft_strjoin("miniRT - ", argv[1]);
		sc.mlx->win_ptr = mlx_new_window(sc.mlx->mlx_ptr, \
			sc.r.w, sc.r.h, title_window);
		if (!(sc.mlx->win_ptr))
			ft_error("Minilibx error");
		free(title_window);
		mlx_put_image_to_window(sc.mlx->mlx_ptr, sc.mlx->win_ptr, \
		sc.img->img_ptr, 0, 0);
		get_controls_loop(sc.mlx, &sc);
	}
	return (0);
}
