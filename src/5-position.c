/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-position.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:03:59 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/05/29 19:49:03 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	target(t_stack **stack, int b_idx, int target_idx, int target_pos)
{
	t_stack	*temp_a;

	temp_a = *stack;
	while (temp_a)
	{
		if (temp_a->index > b_idx && temp_a->index < target_idx)
		{
			target_idx = temp_a->index;
			target_pos = temp_a->position;
		}
		temp_a = temp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	temp_a = *stack;
	while (temp_a)
	{
		if (temp_a->index < target_idx)
		{
			target_idx = temp_a->index;
			target_pos = temp_a->position;
		}
		temp_a = temp_a->next;
	}
	return (target_pos);
}

static void	position(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp->position = i;
		temp = temp->next;
		i++;
	}
}

int	lowest_position(t_stack **stack)
{
	t_stack	*temp;
	int		lowest_index;
	int		lowest_position;

	temp = *stack;
	lowest_index = INT_MAX;
	position(stack);
	lowest_position = temp->position;
	while (temp)
	{
		if (temp->index < lowest_index)
		{
			lowest_index = temp->index;
			lowest_position = temp->position;
		}
		temp = temp->next;
	}
	return (lowest_position);
}

void	target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		target_position;

	temp = *stack_b;
	position(stack_a);
	position(stack_b);
	target_position = 0;
	while (temp)
	{
		target_position = target(stack_a, temp->index, \
			INT_MAX, target_position);
		temp->target_position = target_position;
		temp = temp->next;
	}
}
