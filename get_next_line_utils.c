/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:51:51 by tchevrie          #+#    #+#             */
/*   Updated: 2022/09/30 16:27:18 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_list	*ft_lstnew(void)
{
	t_list	*new;
	size_t	i;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	i = 0;
	while (i <= BUFFER_SIZE)
	{
		(new->content)[i] = '\0';
		i++;
	}
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	long	i;

	if (dst < src)
	{
		i = 0;
		while ((size_t)i < len)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i++;
		}
		return (dst);
	}
	else
	{
		i = len - 1;
		while (i >= 0)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i--;
		}
		return (dst);
	}
}

void	free_elements(t_list **begin, t_list *current)
{
	t_list	*next;

	while ((*begin) && (*begin) != current)
	{
		next = (*begin)->next;
		free((*begin)->content);
		free(*begin);
		*begin = next;
	}
}
