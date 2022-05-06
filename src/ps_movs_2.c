/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_movs_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:50:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/06 01:44:54 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char s)
{
	t_dlist	*tmp;

	tmp = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	ft_dlstadd_back(&stack->bottom, tmp);
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
	t_dlist	*tmp;

	tmp = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->bottom->next = NULL;
	ft_dlstadd_front(&stack->top, tmp);
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
