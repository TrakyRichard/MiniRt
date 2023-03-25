/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:01:18 by jjesberg          #+#    #+#             */
/*   Updated: 2023/03/23 17:33:09 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	size;
	char	*arr;

	size = ft_strlen(src);
	arr = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	if (!arr)
	{
		return (NULL);
	}
	while (src[i])
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
