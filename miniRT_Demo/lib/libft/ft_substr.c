/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:05:56 by jjesberg          #+#    #+#             */
/*   Updated: 2023/03/23 17:34:10 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		size;
	char		*arr;

	arr = NULL;
	j = 0;
	size = ft_strlen(s);
	if (start > size || size == 0 || len == 0)
		return (ft_strdup(""));
	if (len > size - start)
		arr = malloc(sizeof(char) * (size - start + 1));
	else if (len <= size - start)
		arr = malloc(sizeof(char) * (len + 1));
	i = start;
	if (!arr)
		return (NULL);
	while (j < len && i < ft_strlen(s))
		arr[j++] = s[i++];
	arr[j] = '\0';
	return (arr);
}
