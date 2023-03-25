/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:29:52 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 14:04:07 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3 point_light(t_gen *gen, t_hit *h, t_point light, t_vec3 color)
{
    double intensity = 0.0;
    double distance = length(sub(light.center, h->p));
    
    // Calculate the distance attenuation
    if (light.attenuation != 0.0)
    {
        intensity = 1.0 / (light.attenuation * distance * distance + 1.0);
    }
    else
    {
        intensity = 1.0;
    }
    
    // Calculate the diffuse lighting contribution
    t_vec3 to_light = normalize(sub(light.center, h->p));
    double dot_prod = max(dot(h->normal, to_light), 0.0);
    t_vec3 diffuse = mpv(color, dot_prod);
    
    // Combine the diffuse color with the light's color and brightness
    t_vec3 final_color = mpv(diffuse, intensity);
    final_color = mpv(final_color, light.color);
    final_color = mpv(final_color, light.brightness);
    
    // Add the ambient light contribution
    final_color = add(final_color, gen->ambient_color);
    
    return final_color;
}
