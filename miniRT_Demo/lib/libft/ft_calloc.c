/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:00:25 by jjesberg          #+#    #+#             */
/*   Updated: 2023/03/23 17:30:44 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	i;

	arr = malloc(size * nmemb);
	i = 0;
	if (!arr)
		return (NULL);
	while (i < nmemb * size)
	{
		((char *)arr)[i] = 0;
		i++;
	}
	return (arr);
}
