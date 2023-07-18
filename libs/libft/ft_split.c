/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:45:25 by jjesberg          #+#    #+#             */
/*   Updated: 2023/06/22 14:05:36 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **ft_free_dbpt(char **tab)
{
	unsigned int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}
int is_charset(char c, char *chrs)
{
	int i;

	i = 0;
	while (chrs[i])
	{
		if (c == chrs[i])
			return (1);
		i++;
	}
	return (0);
}
int ft_get_next_str(char **str, char *chrs, int *wordlen)
{
	int i;

	i = 0;
	*str = *str + *wordlen;
	*wordlen = 0;
	while (**str && is_charset(**str, chrs))
		(*str)++;
	while ((*str)[i])
	{
		if (is_charset((*str)[i], chrs))
			return (0);
		(*wordlen)++;
		i++;
	}
	i = 0;
	return (0);
}



int ft_count_words(char const *s, char *chrs)
{
	char last;
	int i;
	int j;

	i = 0;
	j = 0;
	last = chrs[0];
	while (s[i] != '\0')
	{
		if (is_charset(last, chrs) && is_charset(s[i], chrs) == 0)
			j++;
		last = s[i];
		i++;
	}
	return (j);
}

char **ft_split(char const *s, char *chrs)
{
	char **tab;
	char *next_str;
	int next_str_len;
	int i;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, chrs) + 1));
	if (!(tab))
		return (NULL);
	i = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (i < ft_count_words(s, chrs))
	{
		ft_get_next_str(&next_str, chrs, &next_str_len);
		tab[i] = (char *)malloc(sizeof(char) * (next_str_len + 1));
		if (!(tab[i]))
			return (ft_free_dbpt(tab));
		ft_strlcpy(tab[i], next_str, next_str_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
