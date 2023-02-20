/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:37:32 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/02/19 12:51:03 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void hexDump(char *desc, void *addr, int len) {
    int i = -16;
    unsigned char buff[17] = {0};
    unsigned char *pc = (unsigned char*)addr;

    // Output description if given.
    if (desc != NULL) {
        printf ("%s:\n", desc);
    }

    // Start processing bytes.
    while (i < len - 1) {
        if (i % 16 == -1) {
            printf("  %04x ", i + 1);
        }
        printf(" %02x", pc[i + 1]);
        if (pc[i + 1] < 0x20 || pc[i + 1] > 0x7e) {
            buff[(i + 1) % 16] = '.';
        } else {
            buff[(i + 1) % 16] = pc[i + 1];
        }
        if ((i + 1) % 16 == 0) {
            printf("  %s\n", buff);
            memset(buff, 0, sizeof(buff));
        }
        i++;
    }

    // Pad out last line if not exactly 16 characters.
    if ((i % 16) != 0) {
        while ((i % 16) != 0) {
            printf("   ");
            i++;
        }
        printf("  %s\n", buff);
    }
}

int main() {
    int fd = open("Screenshot 2020-02-21 20/09/01.bmp", O_RDONLY);
    char *memory = malloc((3*4 * 4 + 54) * sizeof(char));
    read(fd, memory, 3*4 * 4 + 54);
    printf("%s\n",memory);
    hexDump("memory", memory, 3*4 * 4 + 54);
    free(memory);

    fd = open("Screenshot 2020-02-21 20/18/12.bmp", O_RDONLY);
    memory = malloc((3*4 * 4 + 54) * sizeof(char));
    read(fd, memory, 3*4 * 4 + 54);
    printf("%s\n",memory);
    hexDump("\nmemory", memory, 3*4 * 4 + 54);
    free(memory);
}
