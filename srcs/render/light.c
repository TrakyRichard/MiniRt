#include "../minirt.h"


/**
 * Set the color based on lights, the normal at the intersection point, and any obstacles.
 * @param scene     Pointer to the scene structure
 * @param intx    Pointer to the intx structure containing intersection information
 * @param color     Pointer to the current color
 * @param pixel     Pixel coordinates
 * @return          Pointer to the modified color
 **/
t_rgb *manage_light(const t_sc *scene, t_intx *intx, t_rgb *color)
{
    t_sh *lights = scene->l.head;
    t_rgb diffuse;

    diffuse = set_col(0, 0, 0);
    while (lights)
    {
        // void *obstacle = NULL;
        t_l *light = (t_l *)(lights->i);
        t_ray to_light;
        set_ray(&to_light, intx->ray.dir, vec_minus(light->pos, intx->ray.orig), INFINITY);

        double normal_dot_light = ft_max_float(vec_dot(get_shape_ray(intx->i, intx->type).dir, to_light.dir), 0.0) / (distance(intx->ray.orig, light->pos) * (distance(intx->ray.orig, light->pos)));
        t_rgb color_l = col_multi_with_d(light->color, normal_dot_light);
        diffuse = add_rgb_rgb(*color, color_l);

        lights = lights->next;
    }

    diffuse = col_multi_with_d(diffuse, ALBEDO);
    *color = mult_rgb_rgb(add_rgb_rgb(scene->a.color, diffuse), *color);

    min_rgb(color);

    return color;
}