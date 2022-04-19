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

void	ps_order_3(t_stack *a, char s)
{
	if (ps_check_order(a->top) == ORDER)
		return ;
	if (a->top->nb == a->min)
	{
		reverse_rotate(a, s);
		swap(a->top, s);
	}
	else if (a->top->nb == a->max)
	{
		rotate(a, s);
		if (a->top->next->nb == a->min)
			swap(a->top, s);
	}
	else
	{
		if (a->top->next->nb == a->min)
			swap(a->top, s);
		else
			reverse_rotate(a, s);
	}
}

static int	ps_order_4_special_case(t_stack *a, char s)
{
	if (a->top->next->nb == a->max)
	{
		if ((a->bottom->prev->nb == a->min))
		{
			if (a->top->nb > a->bottom->nb)
			{
				reverse_rotate(a, s);
				reverse_rotate(a, s);
				if (ps_check_order(a->top) == ORDER)
					return (ORDER);
			}
		}
	}
	return (NOT_ORDER);
}

int	ps_order_4(t_stack *a, t_stack *b)
{
	if (rotate_max_top(a) == ORDER)
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
	if (rotate_max_top(a) == ORDER)
		return (ORDER);
	if (ps_small_part1(a, b) == ORDER)
		return (ORDER);
	ps_order_4(a, b);
	if (ps_small_part2(a, b) == ORDER)
		return (ORDER);
	else
		return (ps_order_5(a, b));
}
