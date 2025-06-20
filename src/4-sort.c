/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:13:25 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/05/29 19:48:41 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = ft_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while ((stack_size - pushed) > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}
}

static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = ft_stack_size(*stack_a);
	lowest_pos = lowest_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			do_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(stack_a);
			lowest_pos--;
		}
	}
}

int	ft_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	save_three(stack_a, stack_b);
	sort_tiny(stack_a);
	while (*stack_b)
	{
		target_position(stack_a, stack_b);
		cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
