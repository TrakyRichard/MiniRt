/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:39:21 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/02/19 12:50:12 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

char	*screenshot_datetime()
{
	char		*res[35];
	time_t		t;
	struct tm	tm;

	t = time(NULL);
	tm = *localtime(&t);
	size_t name_length = 11;

	ft_strcpy(*res, "Screenshot YYYY-MM-DD hh:mm:ss.bmp");

	ft_memcpy(*res + name_length, ft_itoa_width(tm.tm_year + 1900, 4), 4);
	ft_memcpy(*res + name_length + (size_t) 5, ft_itoa_width(tm.tm_mon + 1, 2), 2);
	ft_memcpy(*res + name_length + (size_t) 8, ft_itoa_width(tm.tm_mday, 2), 2);
	ft_memcpy(*res + name_length + (size_t) 11, ft_itoa_width(tm.tm_hour, 2), 2);
	ft_memcpy(*res + name_length + (size_t) 14, ft_itoa_width(tm.tm_min, 2), 2);
	ft_memcpy(*res + name_length + (size_t) 17, ft_itoa_width(tm.tm_sec, 2), 2);

	return (*res);
}

bool	solve_quadratic(const t_vect point, double *x0, double *x1)
{
	double	discr;
	double	q;

	discr = point.y * point.y - 4 * point.x * point.z;

	if (discr < 0) {
		return (0);
	}

	q = (point.y > 0) ? -0.5 * (point.y + sqrt(discr)) : -0.5 * (point.y - sqrt(discr));

	*x0 = q / point.x;
	*x1 = point.z / q;

	if (*x0 > *x1) {
		ft_swap(x0, x1);
	}

	if (discr == 0 && *x0 == *x1) {
		return (1);
	}

	return (2);
}

int    ft_tab_size(char **tab)
{
    int i = 0;

    while (tab && tab[i])
        i++;

    return (i);
}
