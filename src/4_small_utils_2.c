/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_small_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:33:41 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/18 20:01:03 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_order_3_reverse(t_stack *stack, char s)
{
	if (stack->top->nb == stack->max)
	{
		if (stack->top->next->nb == stack->min)
		{
			swap(stack->top, s);
			rotate(stack, s);
		}
	}
	else if (stack->top->nb == stack->min)
	{
		rotate(stack, s);
		if (stack->top->next->nb == stack->max)
			swap(stack->top, s);
	}
	else
	{
		if (stack->bottom->nb == stack->max)
			reverse_rotate(stack, STACK_A);
		else if (stack->top->next->nb == stack->max)
			swap(stack->top, STACK_A);
	}
}

/* int	ps_one_mov_reverse(t_push_swap *data)
{
	if (data->stack_a->top->nb == data->stack_a->max)
	{
		if (ps_check_reverse_order(data->stack_a->top->next) == ORDER)
		{
			rotate(data->stack_a, STACK_A);
			return (ORDER);
		}
	}
	return (NOT_ORDER);
} */
