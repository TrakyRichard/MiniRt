/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:17:04 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 14:18:00 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

void free_split_strings(char **strs)
{
    int i = 0;
    while (strs[i])
    {
        free(strs[i]);
        i++;
    }	
    free(strs);
}

void print_error(char *str, int error_code, int line_num)
{
    if (line_num == -1)
        printf("Error: %s\n", str);
    else
        printf("Line %d: Error: %s\n", line_num, str);
    exit(error_code);
}

t_vec3 parse_vector_from_split(char **strs)
{
    t_vec3 vec;

    vec.x = ft_atod(strs[0]);
    vec.y = ft_atod(strs[1]);
    vec.z = ft_atod(strs[2]);
    return (vec);
}
