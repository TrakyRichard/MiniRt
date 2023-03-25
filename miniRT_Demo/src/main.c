/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:31:24 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 14:36:32 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Initialize the image properties
void init_img(t_image *img) {
  img->aspect_ratio = 16.0 / 9.0;
  img->dir = vec3(0, 0, 1);
  img->fl = 1.0;
  img->fow = 90;
  img->origin = vec3(0, 0, 0);
  img->vup = vec3(0, 1, 0);
}

// Add all objects to the scene based on the data read from the input file
void add_objects(t_gen *gen, t_read *read) {
  // Add all spheres
  t_sphere *sp = read->sph_head;
  while (sp) {
    add_sph(gen, sp->xyz, sp->rgb, cyldata(sp->diameter, 0, 0, vec3(0, 0, -1)));
    sp = sp->next;
  }
  // Add all planes
  t_plane *pl = read->pl_head;
  while (pl) {
    add_pln(gen, pl->xyz, pl->rgb, cyldata(0, 0, 15, pl->orientation));
    pl = pl->next;
  }
  // Add all cylinders
  t_cylinder *cl = read->cyl_head;
  while (cl) {
    add_cyl(gen, cl->xyz, cl->rgb, cyldata(cl->diameter, cl->height, 0, cl->orientation));
    cl = cl->next;
  }
}

// Initialize the lighting properties
void init_light(t_gen *gen, t_read *read) {
  // Add the ambient light if present in the input file
  if (read->amb_l_amount) {
    gen->ambient_ratio = read->amb_l_ratio;
    gen->ambient_color = read->amb_l_rgb;
    gen->ambient_salt = mpv(gen->ambient_color, 0.5 * gen->ambient_ratio);
  }
  // Add the point light if present in the input file
  if (read->lg_amount != 0) {
    gen->light.center = read->lg_xyz;
    gen->light.brightness = read->lg_bright * 10;
    gen->light.color = read->lg_rgb;
  }
  // Otherwise, set the light to be the same as the ambient light
  else if (read->amb_l_amount) {
    gen->light.center = vec3(0, 0, 0);
    gen->light.brightness = 0.05;
    gen->light.color = gen->ambient_color;
  }
}

void initialize_generation(t_generation *generation, t_file_contents *file_contents, t_image *image) {
    // Initialize the MLX connection
    generation->mlx = mlx_init();

    // Initialize the camera and image parameters
    initialize_image(image);
    initialize_camera(generation, *image);

    // Initialize the scene
    generation->scene = NULL;

    // Create the window
    generation->window = mlx_new_window(generation->mlx, generation->camera.width, generation->camera.height, "miniRT");

    // Initialize the default light
    generation->light.center = vec3(0, 0, 0);
    generation->light.brightness = 0.05;
    generation->light.color = vec3(0.01, 0.01, 0.01);

    // Initialize the ambient light
    generation->ambient_color = vec3(0.01, 0.01, 0.01);
    generation->ambient_ratio = 0.001;

    // Initialize the light sources
    initialize_light_sources(generation, file_contents);
}

int main(int argc, char **argv) {
    // Check if the program was executed with the correct number of arguments
    if (argc != 2) {
        ft_error("Usage: ./miniRT <file.rt>", USAGE_ERR, -1);
    }

    // Read the file contents from the given file
    t_file_contents file_contents;
    initialize_file_contents(&file_contents, argv[1]);
    read_file(&file_contents);

    // Initialize the generation parameters
    t_generation generation;
    t_image image;
    initialize_generation(&generation, &file_contents, &image);

    // Add the objects in the scene
    add_objects(&generation, &file_contents);

    // Render the scene
    pre_render(&generation, generation.camera.height, generation.camera.width);

    // Start the MLX event loop
    mlx_hook(generation.window, 17, 0, &handle_window_close, &generation);
    mlx_hook(generation.window, 2, 0, &handle_keyboard_input, &generation);
    mlx_loop(generation.mlx);

    // Free memory and exit the program
    free_file_contents(&file_contents);
    return 0;
}


