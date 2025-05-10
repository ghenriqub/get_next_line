/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:17:01 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/05/03 19:59:37 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*next_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	ft_create_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = ft_get_line(list);
	ft_polish_list(&list);
	return (next_line);
}

void	ft_create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buffer;

	while (!ft_new_line(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (NULL == buffer)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read < 0)
		{
			free(buffer);
			ft_dealloc_list(list, NULL, NULL);
			return ;
		}
		if (char_read == 0)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		ft_append_list(list, buffer);
	}
}

void	ft_append_list(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
		return ;
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buffer = buffer;
	new_node->next = NULL;
}

char	*ft_get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (NULL);
	str_len = ft_len_newline(list);
	next_str = malloc(str_len + 1);
	if (NULL == next_str)
		return (NULL);
	ft_copy_str(list, next_str);
	return (next_str);
}

int	ft_new_line(t_list *list)
{
	int	i;

	if (NULL == list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buffer[i] && i < BUFFER_SIZE)
		{
			if (list->str_buffer[i] == '\n')
				return (1);
			++i;
		}
		list = list->next;
	}
	return (0);
}
