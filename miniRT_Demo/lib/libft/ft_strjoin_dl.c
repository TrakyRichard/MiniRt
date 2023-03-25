/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_dl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 03:30:14 by jjesberg          #+#    #+#             */
/*   Updated: 2023/03/23 17:33:19 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_dl(char *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*arr;

	j = 0;
	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	arr = malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (NULL);
	while (j < ft_strlen(s1))
	{
		arr[j] = s1[j];
		j++;
	}
	while (i < ft_strlen(s2))
		arr[j++] = s2[i++];
	arr[j] = '\0';
	free(s1);
	return (arr);
}
