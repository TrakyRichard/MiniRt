/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 01:32:06 by richard          #+#    #+#             */
/*   Updated: 2023/05/05 17:11:46 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_atof_part2(const char *str, double res, int i, int sign)
{
    int		j;
    double	dec;

    j = 0;
    dec = 0;
    while (str[i] && ft_isdigit(str[i]))
    {
        dec = dec * 10 + (str[i] - '0');
        i++;
        j++;
    }
    while (j-- > 0)
        dec /= 10;
    res += dec;
    return (res * sign);
}

double	ft_atof(const char *str)
{
    int		i;
    int		sign;
    double	res;

    i = 0;
    sign = 1;
    res = 0;
    while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
            || str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
        i++;
    if (str[i] == '-')
        sign = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] && ft_isdigit(str[i]))
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '.')
        res = ft_atof_part2(str, res, ++i, sign);
    return (res * sign);
}