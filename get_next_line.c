/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:57:26 by tchevrie          #+#    #+#             */
/*   Updated: 2022/11/08 20:36:44 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*tl_strjoin(t_list *begin)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = malloc(sizeof(char) * (BUFFER_SIZE * ft_lstsize(begin) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (begin)
	{
		j = 0;
		while ((begin->content)[j] && j < BUFFER_SIZE)
		{
			new[i] = (begin->content)[j];
			i++;
			if ((begin->content)[j] == '\n')
				break ;
			j++;
		}
		if ((begin->content)[j] == '\n')
			break ;
		begin = begin->next;
	}
	new[i] = '\0';
	return (new);
}

int	end_of_line(char *content)
{
	size_t	i;

	i = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	clear_element(char *content, t_list **elem)
{
	size_t	i;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
	{
		if (ft_strlen(content + i) != 1)
		{
			ft_memmove(content, content + i + 1, (ft_strlen(content + i)));
			if (end_of_line(content))
				return (0);
			(*elem)->next = ft_lstnew();
			*elem = (*elem)->next;
			return (1);
		}
	}
	i = 0;
	while (i <= BUFFER_SIZE)
		content[i++] = '\0';
	return (1);
}

int	get_content(int fd, t_list *begin, t_list **current)
{
	while (read(fd, (*current)->content, BUFFER_SIZE) > 0)
	{
		if (end_of_line((*current)->content))
			break ;
		(*current)->next = ft_lstnew();
		*current = (*current)->next;
	}
	if (!(begin->content[0]))
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	*begin;
	t_list			*current;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!begin)
		begin = ft_lstnew();
	if (!begin)
		return (NULL);
	current = begin;
	if (clear_element(begin->content, &current))
		if (!get_content(fd, begin, &current))
			return (NULL);
	line = tl_strjoin(begin);
	free_elements(&begin, current);
	return (line);
}
