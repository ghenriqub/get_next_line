/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-do_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:21:47 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/05/29 18:00:20 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(a, b);
	}
}

static void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(a, b);
	}
}

static void	do_rotate(t_stack **stack, int *cost, char module)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			if (module == 'a')
				do_ra(stack);
			else if (module == 'b')
				do_rb(stack);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			if (module == 'a')
				do_rra(stack);
			else if (module == 'b')
				do_rrb(stack);
			(*cost)++;
		}
	}
}

void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	do_rotate(stack_a, &cost_a, 'a');
	do_rotate(stack_b, &cost_b, 'b');
	do_pa(stack_a, stack_b);
}
