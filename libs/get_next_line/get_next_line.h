/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: richard <richard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 09:55:06 by richard          #+#    #+#             */
/*   Updated: 2023/05/05 16:24:11 by richard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(char *s);
int		get_nl_idx_gnl(char *ptr);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	cpystr_increment_gnl(char *s1, char *s2, size_t *num);

#endif