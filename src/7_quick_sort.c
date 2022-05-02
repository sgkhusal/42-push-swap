/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_quick_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:00:09 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/02 16:23:58 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_qs_small1(t_stack *a, t_stack *b, t_push_swap *ps, int ref) // joga no b
{
	while (b->size < ref)
	{
		if (a->top->nb >= ps->median)
		{
			if (b->size > 1 && b->top->nb < ps->median2)
				double_rotate(a, b);
			else
				rotate(a, STACK_A);
		}
		else
			push(a, b, STACK_B);
	}
}

void	ps_qs_small2(t_stack *a, t_stack *b, t_push_swap *ps, int ref) // joga no b
{
	while (b->size < ref)
	{
		if (a->top->nb >= ps->median)
			rotate(a, STACK_A);
		else
			push(a, b, STACK_B);
	}
}

/* void	ps_qs_small3(t_stack *a, t_stack *b, t_push_swap *ps, int ref) // joga no b
{
	while (a->top->nb < ps->order->max)
	{
		if (a->top->nb >= ps->median)
			rotate(a, STACK_A);
		else
			push(a, b, STACK_B);
	}
	while (b->size < ref)
	{
		reverse_rotate(a, STACK_A);
		if (a->top->nb < ps->median) //
			push(a, b, STACK_B);
	}
	if (ps->status > ORDER)
		ps->status = NOT_ORDER;
	else if (ps->status == NOT_ORDER)
		ps->status = ORDER;
} */

void	ps_qs_big(t_stack *a, t_stack *b, double median, int ref) // joga no a
{
	while (a->size < ref)
	{
		if (b->top->nb < median)
			rotate(b, STACK_B);
		else
			push(b, a, STACK_A);
	}
}
