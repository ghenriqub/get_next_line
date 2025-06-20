/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-input_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:57:46 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/06/13 11:36:19 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	nbcmp(const char *n1, const char *n2, char **argv, int argc)
{
	int	str1;
	int	str2;

	if (argc == 2)
	{
		str1 = ft_atol(n1, argv, argc);
		str2 = ft_atol(n2, argv, argc);
	}
	else
	{
		str1 = ft_atol(n1, NULL, 0);
		str2 = ft_atol(n2, NULL, 0);
	}
	if (str1 == str2)
		return (0);
	return (1);
}

static int	have_duplicates(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[j])
		{
			if (i != j && nbcmp(argv[i], argv[j], argv, argc) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_number(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i] && (argv[i] >= '0' && argv[i] <= '9'))
		i++;
	if ((argv[i] != '\0' && !(argv[i] >= '0' && argv[i] <= '9')) || i == 0)
		return (0);
	if ((argv[0] == '-' || argv[0] == '+') && i == 1)
		return (0);
	return (1);
}

int	is_correct_input(char **argv, int argc, int stack)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (!is_number(argv[i]))
		{
			if (stack == 1)
				exit_error(NULL, NULL, argv, argc);
			else
				exit_error(NULL, NULL, NULL, 0);
		}
	}
	if (have_duplicates(argv, argc))
	{
		if (stack == 1)
			exit_error(NULL, NULL, argv, argc);
		else
			exit_error(NULL, NULL, NULL, 0);
		return (0);
	}
	return (1);
}
