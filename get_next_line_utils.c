/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:47:14 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/05/09 11:35:17 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// function that we'll count the amount of chars until '\n' (strlen)
size_t	ft_sl(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

// the function below will add the chars kept in buffer mode to the new_line
// plus, it will free the memory of the old new_line, allowing the perfect
// handling of the memory of both strings
char	*ft_join_free(char *new_line, char *buffer)
{
	ssize_t	i;
	ssize_t	j;
	char	*big_line;

	if (!new_line)
	{
		new_line = malloc(1);
		if (!new_line)
			return (NULL);
		new_line[0] = '\0';
	}
	big_line = malloc(sizeof(char) * (ft_sl(new_line) + ft_sl(buffer) + 1));
	if (big_line)
	{
		i = -1;
		j = -1;
		while (new_line[++i])
			big_line[i] = new_line[i];
		while (buffer[++j])
			big_line[i + j] = buffer[j];
		big_line[i + j] = '\0';
	}
	free (new_line);
	return (big_line);
}

// the function below will return the index where it finds the first '\n' that
// it finds, or if it doesn't, it returns -1
ssize_t	ft_locate_nl(char *str)
{
	ssize_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

// the function below will control our buffer, it will copy what if after the
// first '\n' of the buffer to its beggining, and than it cleans the rest so we
// won't never have any garbage inside our buffer. Plus, if we don't have any
// '\n' inside our fd it cleans the whole buffer
void	ft_memmove_nl(char *buffer)
{
	ssize_t	index;
	ssize_t	nl_index;

	index = 0;
	nl_index = ft_locate_nl(buffer) + 1;
	while (buffer[index + nl_index] && nl_index)
	{
		buffer[index] = buffer[index + nl_index];
		index++;
	}
	while (index < BUFFER_SIZE)
	{
		buffer[index] = '\0';
		index++;
	}
}
