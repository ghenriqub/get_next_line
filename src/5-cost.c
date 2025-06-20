/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-cost.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:34:05 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/05/29 17:43:42 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		size_a;
	int		size_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	size_a = ft_stack_size(temp_a);
	size_b = ft_stack_size(temp_b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->position;
		if (temp_b->position > size_b / 2)
			temp_b->cost_b = (size_b - temp_b->position) * -1;
		temp_b->cost_a = temp_b->target_position;
		if (temp_b->target_position > size_a / 2)
			temp_b->cost_a = (size_a - temp_b->target_position) * -1;
		temp_b = temp_b->next;
	}
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	temp = *stack_b;
	cheapest = INT_MAX;
	while (temp)
	{
		if (ft_abs(temp->cost_a) + ft_abs(temp->cost_b) < ft_abs(cheapest))
		{
			cheapest = ft_abs(temp->cost_b) + ft_abs(temp->cost_a);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}
