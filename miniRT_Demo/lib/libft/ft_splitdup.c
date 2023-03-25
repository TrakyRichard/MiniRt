/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:56:24 by jjesberg          #+#    #+#             */
/*   Updated: 2023/03/23 17:32:56 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_splitdup(char **s)
{
	char	**new;
	int		len;
	int		i;

	i = 0;
	if (!s || !s[0])
		return (NULL);
	len = ft_splitlen(s);
	new = malloc(sizeof(char *) * (len + 1));
	while (i < len && s[i])
	{
		new[i] = ft_strdup(s[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
