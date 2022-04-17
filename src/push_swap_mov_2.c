/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mov_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:50:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/17 02:38:16 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char s)
{
	stack->init->prev = stack->end;
	stack->end->next = stack->init;
	stack->end = stack->init;
	stack->init = stack->init->next;
	stack->init->prev = NULL;
	stack->end->next = NULL;
	if (s == STACK_A)
		ft_putstr_fd("ra\n", 1);
	else if (s == STACK_B)
		ft_putstr_fd("rb\n", 1);
}

void	double_rotate(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, STACK_A_B);
	rotate(stack_b, STACK_A_B);
	ft_putstr_fd("rr\n", 1);
}

void	reverse_rotate(t_stack *stack, char s)
{
	stack->init->prev = stack->end;
	stack->end->next = stack->init;
	stack->init = stack->end;
	stack->end = stack->end->prev;
	stack->init->prev = NULL;
	stack->end->next = NULL;
	if (s == STACK_A)
		ft_putstr_fd("rra\n", 1);
	else if (s == STACK_B)
		ft_putstr_fd("rrb\n", 1);
}

void	double_reverse_rotate(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, STACK_A_B);
	reverse_rotate(stack_b, STACK_A_B);
	ft_putstr_fd("rrr\n", 1);
}
