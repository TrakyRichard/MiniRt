/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 03:16:26 by jjesberg          #+#    #+#             */
/*   Updated: 2023/03/23 17:31:09 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_ispath(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd >= 0)
		close(fd);
	else
		return (0);
	return (1);
}
