/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:31:15 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/02/19 12:50:49 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

unsigned char	*file_header_bmp(int filesize)
{
	unsigned char	*bmpfileheader;
	
	int i = -1;
	int values[] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
	
	if(!(bmpfileheader = (unsigned char*) malloc(14 * sizeof(unsigned char))))
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	while (++i < 14)
		bmpfileheader[i] = (unsigned char)values[i];
	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);
	return (bmpfileheader);
}

unsigned char	*info_header_bmp(t_couple resolution)
{
	unsigned char	*bmpinfoheader;

	int i = -1;
	int values[] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 32,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};

	if(!(bmpinfoheader = (unsigned char*) malloc(40 * sizeof(unsigned char))))
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	while (++i < 40)
		bmpinfoheader[i] = (unsigned char)values[i];
	bmpinfoheader[4] = (unsigned char)(resolution.w);
	bmpinfoheader[5] = (unsigned char)(resolution.w >> 8);
	bmpinfoheader[6] = (unsigned char)(resolution.w >> 16);
	bmpinfoheader[7] = (unsigned char)(resolution.w >> 24);
	bmpinfoheader[8] = (unsigned char)(resolution.h);
	bmpinfoheader[9] = (unsigned char)(resolution.h >> 8);
	bmpinfoheader[10] = (unsigned char)(resolution.h >> 16);
	bmpinfoheader[11] = (unsigned char)(resolution.h >> 24);
	return (bmpinfoheader);
}

void	write_data(int f, const unsigned char *data, t_couple resolution)
{
	int line = resolution.h;

	while (line-- > 0)
		write(f, data + resolution.w * line * 4, resolution.w * 4);
}

void	save_bmp(const char *filename, const unsigned char *data, const t_couple resolution)
{
	int				filesize;
	int				f;
	unsigned char	*bmpfileheader;
	unsigned char	*bmpinfoheader;

	filesize = 14 + 40 + 3 * resolution.w * resolution.h;
	f = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0755);
	bmpfileheader = file_header_bmp(filesize);
	write(f, bmpfileheader, 14);
	free(bmpfileheader);
	bmpinfoheader = info_header_bmp(resolution);
	write(f, bmpinfoheader, 40);
	free(bmpinfoheader);
	write_data(f, data, resolution);
	close(f);
}
