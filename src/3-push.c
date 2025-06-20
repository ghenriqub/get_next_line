/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:16:26 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/05/22 16:25:03 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*temp;

	if (!*stack_src)
		return ;
	temp = (*stack_src)->next;
	(*stack_src)->next = *stack_dest;
	*stack_dest = *stack_src;
	*stack_src = temp;
}

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	push (stack_b, stack_a);
	write (1, "pa\n", 3);
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	push (stack_a, stack_b);
	write (1, "pb\n", 3);
}
