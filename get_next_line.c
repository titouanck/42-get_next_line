/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:30:09 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/11 15:57:12 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fdList	*find_fdbegin(int fd, int clean)
{
	static t_fdList		*fd_list;
	t_fdList			*current;

	if (!fd_list)
		fd_list = ftlst_new_fd(fd);
	if (!fd_list)
		return (NULL);
	current = fd_list;
	while (current->next_fd && current->fd != fd)
		current = current->next_fd;
	if (clean)
		fd_list = clean_fd_list(fd_list, current);
	else if (current->fd != fd)
	{
		current->next_fd = ftlst_new_fd(fd);
		current = current->next_fd;
	}
	return (current);
}

static int	read_file(int fd, t_bufferList *current, t_bufferList *begin)
{
	if (begin && (begin->content[0]) && !end_of_line(begin->content))
	{
		begin->next = ftlst_new_buffer();
		current = begin->next;
	}
	if (end_of_line(begin->content))
		return (1);
	while (read(fd, current->content, BUFFER_SIZE) > 0)
	{
		if (end_of_line(current->content))
			break ;
		current->next = ftlst_new_buffer();
		current = current->next;
	}
	if (!(begin->content[0]))
		return (0);
	return (1);
}

static char	*join_buffers(t_bufferList *current)
{
	char			*line;
	size_t			i;
	size_t			j;

	line = malloc(count_memory(current));
	if (!line)
		return (NULL);
	i = 0;
	while (current && current->content)
	{
		j = 0;
		while ((current->content)[j] && (i == 0 || line[i - 1] != '\n'))
			line[i++] = (current->content)[j++];
		current = current->next;
	}
	line[i] = '\0';
	return (line);
}

static void	clean_buffers(t_bufferList *current, t_fdList *current_fd)
{
	size_t			i;
	size_t			j;
	t_bufferList	*next;

	while (current->next)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
		current_fd->begin = next;
	}
	i = 0;
	while ((current->content)[i])
	{
		i++;
		if ((current->content)[i - 1] == '\n')
			break ;
	}
	j = 0;
	while ((current->content)[i])
		(current->content)[j++] = (current->content)[i++];
	while (j <= BUFFER_SIZE)
		(current->content)[j++] = '\0';
}

char	*get_next_line(int fd)
{
	t_fdList			*c_fd;
	t_bufferList		*begin;
	char				*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	c_fd = find_fdbegin(fd, 0);
	if (!c_fd)
		return (NULL);
	begin = c_fd->begin;
	if (read_file(fd, begin, begin))
		line = join_buffers(begin);
	else
		line = NULL;
	clean_buffers(begin, c_fd);
	if (c_fd->begin && c_fd->begin->content && !((c_fd->begin->content)[0]))
	{
		free(c_fd->begin->content);
		free(c_fd->begin);
		find_fdbegin(fd, 1);
		free(c_fd);
	}
	return (line);
}
