/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:36:20 by jjesberg          #+#    #+#             */
/*   Updated: 2023/03/23 17:30:56 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isalnum(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) \
	|| (c >= 48 && c <= 57));
}
