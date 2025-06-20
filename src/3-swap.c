/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:01:48 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/05/31 15:31:46 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	write(1, "sa\n", 3);
}

void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	write(1, "sb\n", 3);
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	write(1, "ss\n", 3);
}
