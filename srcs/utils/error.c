/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:20:26 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/07/19 04:38:06 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	check_args(int arc, char *args[])
{
	if (arc < 2)
		ft_error("The .rt file is missing\n");
	if (arc > 3)
		ft_error("Can't take more than 2 arguments\n");
	if (arc == 3 && ft_strncmp(args[2], "--save", 6) != 0)
		ft_error("The second argument is not --save\n");
	return ;
}
