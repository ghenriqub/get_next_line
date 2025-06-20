/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:37:49 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/06/13 11:32:15 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //malloc, free
# include <unistd.h> //read, write, exit
# include <limits.h> //int_min, int_max

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
	int				index;
	int				position;
	int				target_position;
	int				cost_a;
	int				cost_b;
}					t_stack;

// utils
int		is_sorted(t_stack *stack);
void	exit_error(t_stack **stack_a, t_stack **stack_b, char **argv, int spl);

// input check
long	ft_atol(const char *str, char **argv, int argc);
int		is_correct_input(char **argv, int argc, int stack);

// split
char	**ft_split(char const *str);
int		count_words(const char *str);
void	free_split(char **array);

// indexation
void	assign_index(t_stack *stack_a, int size);
int		get_arg_count(char **args);

// stack
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*fill_stack_values(int argc, char **argv, int stack_value);

// swap
void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);

// push
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);

// rotate
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);

// reverse rotate
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);

// sort tiny
void	sort_tiny(t_stack **stack);

// sort
void	sort(t_stack **stack_a, t_stack **stack_b);
int		ft_stack_size(t_stack *stack);

// cost
void	cost(t_stack **stack_a, t_stack **stack_b);
void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

// move
void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);

// position
void	target_position(t_stack **stack_a, t_stack **stack_b);
int		lowest_position(t_stack **stack);

#endif
