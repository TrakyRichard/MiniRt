/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:02:11 by jjesberg          #+#    #+#             */
/*   Updated: 2023/03/23 17:33:58 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;

	slen = ft_strlen(s);
	if ((char) c == '\0')
		return ((char *) s + slen);
	while (slen--)
	{
		if (*(s + slen) == (char) c)
			return ((char *) s + slen);
	}
	return (0);
}
