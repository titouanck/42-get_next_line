/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:00:50 by tchevrie          #+#    #+#             */
/*   Updated: 2022/09/23 15:25:06 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*str;
	size_t			i;
	char			buffer;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (read(fd, &buffer, 1))
	{
		if (i < BUFFER_SIZE)
		{
			str[i] = buffer;
			i++;
		}
		if (buffer == '\n')
			break ;
	}
	if (i == 0)
	{
		free(str);
		return (NULL);
	}
	str[i] = '\0';
	return (str);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int	fd;
	int	fd2;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	printf("%s", get_next_line(fd));
	printf("\n");
	printf("%s", get_next_line(fd));
	printf("\n");
	printf("%s", get_next_line(fd));
	printf("\n");
	printf("%s", get_next_line(fd));
	close(fd);
}
