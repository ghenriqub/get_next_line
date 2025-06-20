/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-indexation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:39:31 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/06/11 12:28:56 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_values(int *array, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
}

static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	get_index(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (0);
}

int	get_arg_count(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	assign_index(t_stack *stack_a, int size)
{
	int		sorted[2048];
	t_stack	*tmp;

	copy_values(sorted, stack_a);
	sort_array(sorted, size);
	tmp = stack_a;
	while (tmp)
	{
		tmp->index = get_index(sorted, size, tmp->value);
		tmp = tmp->next;
	}
}
