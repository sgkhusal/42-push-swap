/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_small_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:22:50 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/18 19:30:02 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_order_3(t_stack *stack, char s)
{
	if (stack->init->nb == stack->smaller)
	{
		reverse_rotate(stack, s);
		swap(stack->init, s);
	}
	else if (stack->init->nb == stack->bigger)
	{
		rotate(stack, s);
		if (stack->init->next->nb == stack->smaller)
			swap(stack->init, s);
	}
	else
	{
		if (stack->init->next->nb == stack->smaller)
			swap(stack->init, STACK_A);
		else
			reverse_rotate(stack, STACK_A);
	}
}

static int	ps_order_4_special_case(t_stack *stack, char s)
{
	if (stack->init->next->nb == stack->bigger)
	{
		if ((stack->end->prev->nb == stack->smaller))
		{
			if (stack->init->nb > stack->end->nb)
			{
				reverse_rotate(stack, s);
				reverse_rotate(stack, s);
				if (ps_check_order(stack->init) == ORDER)
					return (ORDER);
			}
		}
	}
	return (NOT_ORDER);
}

int	ps_order_4(t_push_swap *data)
{
	if (ps_one_mov(data) == ORDER)
		return (ORDER);
	if (ps_order_4_special_case(data->stack_a, STACK_A) == ORDER)
		return (ORDER);
	if (ps_small_part1(data) == ORDER)
		return (ORDER);
	ps_order_3(data->stack_a, STACK_A);
	if (ps_small_part2(data) == ORDER)
		return (ORDER);
	else
		return (ps_order_4(data));
}

int	ps_order_5(t_push_swap *data)
{
	ps_one_mov(data);
	if (ps_small_part1(data) == ORDER)
		return (ORDER);
	ps_order_4(data);
	if (ps_small_part2(data) == ORDER)
		return (ORDER);
	else
		return (ps_order_5(data));
}
