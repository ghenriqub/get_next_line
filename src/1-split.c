/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:14:09 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/06/13 12:00:39 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			count++;
			while (str[i] && (str[i] != ' '))
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while ((i < (size - 1)) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

static char	*ft_strdup_mod(const char *src)
{
	int		size;
	char	*dest;

	size = 0;
	while (src[size] && src[size] != ' ')
		size++;
	dest = malloc((size + 1) * (sizeof(char)));
	if (!dest)
		return (0);
	ft_strlcpy(dest, src, (size + 1));
	return (dest);
}

void	free_split(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

char	**ft_split(char const *str)
{
	char	**result;
	int		i;

	i = -1;
	result = malloc((count_words(str) + 2) * sizeof(char *));
	if (!result)
		return (0);
	while (*str)
	{
		if (*str != ' ')
		{
			result[++i] = ft_strdup_mod(str);
			if (!result[i])
			{
				free_split(result);
				return (0);
			}
			while (*str && *str != ' ')
				str++;
		}
		else
			str++;
	}
	result[i + 1] = 0;
	return (result);
}
