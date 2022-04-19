/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_small_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:22:50 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/19 04:38:58 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_order_3(t_stack *stack, char s)
{
	if (ps_check_order(stack->init) == ORDER)
		return ;
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
			swap(stack->init, s);
		else
			reverse_rotate(stack, s);
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

int	ps_order_4(t_stack *a, t_stack *b)
{
	if (ps_bigger_first(a) == ORDER)
		return (ORDER);
	if (ps_order_4_special_case(a, STACK_A) == ORDER)
		return (ORDER);
	if (ps_small_part1(a, b) == ORDER)
		return (ORDER);
	ps_order_3(a, STACK_A);
	if (ps_small_part2(a, b) == ORDER)
		return (ORDER);
	else
		return (ps_order_4(a, b));
}

int	ps_order_5(t_stack *a, t_stack *b)
{
	if (ps_bigger_first(a) == ORDER)
		return (ORDER);
	if (ps_small_part1(a, b) == ORDER)
		return (ORDER);
	ps_order_4(a, b);
	if (ps_small_part2(a, b) == ORDER)
		return (ORDER);
	else
		return (ps_order_5(a, b));
}
