/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-j2 <maria-j2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:23:06 by maria-j2          #+#    #+#             */
/*   Updated: 2025/07/02 18:27:36 by maria-j2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd);

int main(int argc, char const **argv)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;
	if (argc != 3)
	{
		printf("Usage: %s\n [file1.txt][file2.txt]", argv[0]);
		return (1);
	}
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		printf("Error opening file1\n");
		return (1);
	}
	fd2 = open(argv[2], O_RDONLY);
	if (fd2 == -1)
	{
		printf("Error opening file2\n");
		return (1);
	}
	printf("Files opened successfully\n");
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	while (line1 != NULL || line2 != NULL)
	{
		printf("%s", line1);
		printf("%s", line2);
		free(line1);
		free(line2);
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
	}
	close(fd1);
	close(fd2);
	return 0;
}
