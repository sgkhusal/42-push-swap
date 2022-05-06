/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_quick_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:00:09 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/06 00:20:34 by sguilher         ###   ########.fr       */
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
	if (b->size > 1 && b->top->nb < ps->median2 && \
	b->top->next->nb >= ps->median2)
		rotate(b, STACK_B);
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

t_quick_sort	ps_qs_big(t_stack *a, t_stack *b, t_push_swap *ps, int qs_b_size)
{
	t_quick_sort	qs;
	int				a_final_size;

	ps_set(b, ps, qs_b_size);
	qs = ps_section_size(qs_b_size);
	a_final_size = a->size + qs.a_size;
	while (a->size < a_final_size)
	{
		if (b->top->nb < ps->median)
			rotate(b, STACK_B);
		else
			push(b, a, STACK_A);
	}
	return (qs);
}
