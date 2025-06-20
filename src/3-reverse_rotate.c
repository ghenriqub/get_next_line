/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-reverse_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:18:16 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/05/29 18:05:29 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_stack_before_bottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;
	t_stack	*before_tail;

	if (!*stack || !(*stack)->next)
		return ;
	tail = get_stack_bottom(*stack);
	before_tail = get_stack_before_bottom(*stack);
	temp = *stack;
	*stack = tail;
	(*stack)->next = temp;
	before_tail->next = NULL;
}

void	do_rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	do_rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
