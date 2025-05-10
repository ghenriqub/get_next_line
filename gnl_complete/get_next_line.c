/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:46:27 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/05/10 08:44:06 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_handle_nl(char *buffer, char *new_line)
{
	char	*final_line;
	int		nl_index;	
	int		i;

	nl_index = ft_locate_nl(new_line);
	if (nl_index >= 0)
	{
		i = -1;
		final_line = malloc(nl_index + 2);
		if (!final_line)
		{
			free (new_line);
			return (NULL);
		}
		while (++i < (nl_index + 1) && new_line[i])
			final_line[i] = new_line[i];
		final_line[nl_index + 1] = '\0';
	}
	else
		final_line = new_line;
	ft_memmove_nl(buffer);
	if (nl_index >= 0)
		free(new_line);
	return (final_line);
}

char	*ft_read_loop(char *buffer, char *new_line, int fd)
{
	ssize_t	bytes_read;

	ft_memmove_nl(buffer);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (new_line)
				free (new_line);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		new_line = ft_join_free(new_line, buffer);
		if (!new_line)
			return (NULL);
		if (ft_locate_nl(buffer) >= 0)
			break ;
		ft_memmove_nl(buffer);
	}
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new_line = NULL;
	if (buffer[0] != '\0')
		new_line = ft_join_free(new_line, buffer);
	if (ft_locate_nl(buffer) >= 0)
		return (ft_handle_nl(buffer, new_line));
	new_line = ft_read_loop(buffer, new_line, fd);
	new_line = ft_handle_nl(buffer, new_line);
	return (new_line);
}
