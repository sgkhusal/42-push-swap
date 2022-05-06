/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_quick_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:00:09 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/06 01:43:29 by sguilher         ###   ########.fr       */
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

t_quick_sort	ps_qs_big(t_push_swap *ps, int qs_b_size)
{
	t_quick_sort	qs;
	int				a_final_size;

	ps_set(ps->stack_b, ps, qs_b_size);
	qs = ps_section_size(qs_b_size);
	a_final_size = ps->stack_a->size + qs.a_size;
	while (ps->stack_a->size < a_final_size)
	{
		if (ps->stack_b->top->nb < ps->median)
			rotate(ps->stack_b, STACK_B);
		else
			push(ps->stack_b, ps->stack_a, STACK_A);
	}
	return (qs);
}
