/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_quick_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:00:09 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/03 09:48:04 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_qs_small1(t_stack *a, t_stack *b, t_push_swap *ps, int ref)
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
		else if (b->size > 1 && b->top->nb < ps->median2 && \
		b->top->next->nb >= ps->median2)
			rotate(b, STACK_B);
		else
			push(a, b, STACK_B);
	}
}

void	ps_qs_small2(t_stack *a, t_stack *b, t_push_swap *ps, int ref)
{
	while (b->size < ref)
	{
		if (a->top->nb >= ps->median)
			rotate(a, STACK_A);
		else
			push(a, b, STACK_B);
	}
}

void	ps_qs_big(t_stack *a, t_stack *b, double median, int ref)
{
	while (a->size < ref)
	{
		if (b->top->nb < median)
			rotate(b, STACK_B);
		else
			push(b, a, STACK_A);
	}
}
