/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:57:59 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/06/19 19:06:52 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		sort_tiny(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

void	exit_error(t_stack **stack_a, t_stack **stack_b, char **argv, int spl)
{
	if (spl)
		free_split(argv);
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(1, "Error\n", 6);
	exit (1);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	stack_size = 0;
	if (argc == 2)
	{
		stack_size = 1;
		argv = ft_split(argv[1]);
		if (!argv || !argv[0])
			exit_error(NULL, NULL, argv, argc);
	}
	if (!is_correct_input((argv + !stack_size), argc, stack_size))
		exit_error(NULL, NULL, argv, stack_size);
	stack_b = NULL;
	stack_a = fill_stack_values(get_arg_count(argv), argv, stack_size);
	stack_size = ft_stack_size(stack_a);
	assign_index(stack_a, stack_size);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (argc == 2)
		free_split(argv);
}
