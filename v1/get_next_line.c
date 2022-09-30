/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:20:51 by tchevrie          #+#    #+#             */
/*   Updated: 2022/09/29 15:10:13 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	line_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	return (i);
}

char	*next_line(char *content, int line)
{
	size_t	i;
	char	*next;

	i = 0;
	while (content[i] && line > 0)
	{
		while (content[i])
			if (content[i++] == '\n')
				break ;
		line--;
	}
	if (!(content[i]))
		return (NULL);
	next = malloc(sizeof(char) * (line_len(content + i) + 1));
	if (!next)
		return (NULL);
	while (content[i])
	{
		next[line++] = content[i++];
		if (next[line - 1] == '\n')
			break ;
	}
	next[line] = '\0';
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*content = NULL;
	static int	line = 0;

	if (!content)
	{
		content = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (content)
		{
			read(fd, content, BUFFER_SIZE);
			content[BUFFER_SIZE] = '\0';
		}
	}
	if (!fd || fd == -1 || !content)
	{
		if (content)
			free(content);
		return (NULL);
	}
	return (next_line(content, line++));
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	printf("[%s]\n\n\n", get_next_line(fd));
	printf("[%s]\n\n\n", get_next_line(fd));
	printf("[%s]\n\n\n", get_next_line(fd));
	printf("[%s]\n\n\n", get_next_line(fd));
	printf("[%s]\n\n\n", get_next_line(fd));
	printf("[%s]\n\n\n", get_next_line(fd));
	printf("[%s]\n\n\n", get_next_line(fd));
	printf("[%s]\n\n\n", get_next_line(fd));
	printf("[%s]\n\n\n", get_next_line(fd));
	printf("[%s]\n\n\n", get_next_line(fd));
	printf("[%s]\n\n\n", get_next_line(fd));
	printf("[%s]\n\n\n", get_next_line(fd));
	printf("[%s]\n\n\n", get_next_line(fd));
	printf("[%s]\n\n\n", get_next_line(fd));
	printf("[%s]\n\n\n", get_next_line(fd));
	printf("[%s]\n\n\n", get_next_line(fd));
	printf("[%s]\n\n\n", get_next_line(fd));
	printf("[%s]\n\n\n", get_next_line(fd));
}
