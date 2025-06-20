/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-filling.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:39:31 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/06/12 15:46:22 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str, char **argv, int argc)
{
	long	i;
	long	n;
	long	result;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	n = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if ((result * n) > INT_MAX || (result * n) < INT_MIN)
		exit_error(NULL, NULL, argv, argc);
	return (result * n);
}

static t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->position = -1;
	new->target_position = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

static void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_stack_bottom(*stack);
	tail->next = new;
}

t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*fill_stack_values(int argc, char **argv, int stack_size)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;
	int			start;

	stack_a = NULL;
	nb = 0;
	if (stack_size == 1)
		start = 0;
	else
		start = 1;
	i = start;
	while (i < argc)
	{
		nb = ft_atol(argv[i], argv, argc);
		if (nb > INT_MAX || nb < INT_MIN)
			return (0);
		if (i == start)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}
