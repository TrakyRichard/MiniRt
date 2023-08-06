#include "minirt.h"

t_vec3 reflect(t_vec3 incident, t_vec3 normal)
{
    // Calculate the reflected ray direction vector
    // Formula: reflected = incident - 2 * dot(incident, normal) * normal
    double dot_product = vec_dot(incident, normal);
    t_vec3 reflected = vec_minus(incident, vec_scale(normal, 2 * dot_product));

    return reflected;
}
