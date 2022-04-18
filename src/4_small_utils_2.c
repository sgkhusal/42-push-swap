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
# include "test.h" ///////////////////////////

void	ps_order_3_reverse(t_stack *stack, char s)
{
	if (stack->init->nb == stack->bigger)
	{
		if (stack->init->next->nb == stack->smaller)
		{
			swap(stack->init, s);
			rotate(stack, s);
		}
	}
	else if (stack->init->nb == stack->smaller)
	{
		rotate(stack, s);
		if (stack->init->next->nb == stack->bigger)
			swap(stack->init, s);
	}
	else
	{
		if (stack->end->nb == stack->bigger)
			reverse_rotate(stack, STACK_A);
		else if (stack->init->next->nb == stack->bigger)
			swap(stack->init, STACK_A);
	}
}

/* int	ps_one_mov_reverse(t_push_swap *data)
{
	if (data->stack_a->init->nb == data->stack_a->bigger)
	{
		if (ps_check_reverse_order(data->stack_a->init->next) == ORDER)
		{
			rotate(data->stack_a, STACK_A);
			return (ORDER);
		}
	}
	return (NOT_ORDER);
} */
