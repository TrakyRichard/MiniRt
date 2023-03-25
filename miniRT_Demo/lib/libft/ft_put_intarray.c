/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_intarray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:48:26 by jjesberg          #+#    #+#             */
/*   Updated: 2023/03/23 17:32:29 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_put_intarray(int *array, int len)
{
	int	i;

	i = 0;
	write(1, "int array = \n", 14);
	while (i < len)
	{
		ft_putnbr_fd(array[i++], 1);
		write(1, "\n", 1);
	}
}
