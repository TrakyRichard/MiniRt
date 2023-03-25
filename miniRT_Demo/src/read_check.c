/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:41:52 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/03/25 14:03:14 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void check_rage(double min, double max, t_vec3 value, int i)
{
	if (value.x < min || value.x > max)
		error("Error\nValue out of range", i);
	if (value.y < min || value.y > max)
		error("Error\nValue out of range", i);
	if (value.z < min || value.z > max)
		error("Error\nValue out of range", i);
}

void check_valid_divided(int expected, char **split, int line_num) {
    int num_args = 0;
    while (split[num_args]) {
        num_args++;
    }
    if (num_args != expected) {
        if (num_args < expected) {
            ft_error("Too few arguments", INVALID_ARGUMENTS_ERR, line_num);
        } else {
            ft_error("Too many arguments", INVALID_ARGUMENTS_ERR, line_num);
        }
    }
}
void check_argument_amount(t_read *read, int i)
{
	if (read->split[i] == NULL)
		error("Error\nInvalid arguments", i);
	if (read->split[i + 1] == NULL)
		error("Error\nInvalid arguments", i);
	if (read->split[i + 2] == NULL)
		error("Error\nInvalid arguments", i);
	if (read->split[i + 3] != NULL)
		error("Error\nInvalid arguments", i);
}

void is_rt(char *file_name)
{
    if (!file_name)
        ft_error("File name is null", INVALID_ARGUMENTS_ERR, -1);

    int len = strlen(file_name);

    if (len < 3 || file_name[len - 1] != 't' || file_name[len - 2] != 'r' || file_name[len - 3] != '.')
        ft_error("Invalid file extension", INVALID_FILE_EXT_ERR, -1);
}
