/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:20:26 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/02/19 12:50:29 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	print_err_and_exit(const char *str, const int err)
{
	const int STDERR_FILENO = 2;
	char err_code_str[16];
	int i = 0;

	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(" (exit code: ", STDERR_FILENO);

	if (err < 0) {
		ft_putchar_fd('-', STDERR_FILENO);
		err = -err;
	}

	if (err == 0) {
		ft_putchar_fd('0', STDERR_FILENO);
	} else {
		while (err > 0) {
			err_code_str[i++] = (err % 10) + '0';
			err /= 10;
		}
		i--;
		while (i >= 0) {
			ft_putchar_fd(err_code_str[i], STDERR_FILENO);
			i--;
		}
	}

	ft_putstr_fd(")\n", STDERR_FILENO);
	exit(err);
}
