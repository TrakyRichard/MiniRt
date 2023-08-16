/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:20:26 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/08/16 02:44:40 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_b	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (false);
}

t_b	ft_split_error(char *str, char **split_array, char *line)
{
	if (line != NULL)
	{
		free(line);
	}
	if (split_array != NULL)
	{
		ft_free_dbpt(split_array);
	}
	return (ft_error(str));
}

void	check_args(int arc, char *args[])
{
	t_b		check;
	char	**split;
	size_t	length;

	check = true;
	if (arc < 2)
		check = ft_error("The .rt file is missing\n");
	if (arc == 2)
	{
		split = ft_split(args[1], ".");
		length = split_length(split);
		if (length > 1)
		{
			if (ft_strncmp(split[length - 1], "rt", 2) != 0)
				check = ft_error("The .rt file is missing\n");
		}
		else if (length == 1)
			check = ft_error("The .rt file is missing\n");
	}
	if (arc > 3)
		check = ft_error("Can't take more than 2 arguments\n");
	if (arc == 3 && ft_strncmp(args[2], "--save", 6) != 0)
		check = ft_error("The second argument is not --save\n");
	if (check == false)
		exit(EXIT_FAILURE);
}

size_t	split_length(char **split_array)
{
	size_t	length;

	length = 0;
	if (split_array)
	{
		while (split_array[length] != NULL)
		{
			length++;
		}
	}
	return (length);
}
