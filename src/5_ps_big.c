/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ps_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:37:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/06 01:43:21 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_big_step3(t_stack *a, t_stack *b, t_push_swap *ps, int size)
{
	t_quick_sort	qs;

	ps_set(a, ps, size);
	qs = ps_section_size(size);
	ps_qs_small2(a, b, ps, b->size + qs.b_size);
	ps_selection_sort(a, b, qs);
}

static void	ps_big_step2(t_stack *a, t_stack *b, t_push_swap *ps, int size)
{
	t_quick_sort	qs;

	if (ps->status > ORDER)
	{
		while (a->bottom->nb != a->max)
			reverse_rotate(a, STACK_A);
	}
	ps_set(a, ps, size);
	qs = ps_section_size(size);
	ps_qs_small2(a, b, ps, b->size + qs.b_size);
	if (ps->status == ORDER)
		ps->status++;
	if (qs.a_size > MIN_SIZE)
	{
		ps_big_step2(a, b, ps, qs.a_size);
		qs = ps_qs_big(ps, qs.b_size);
		if (qs.a_size > MIN_SIZE)
			ps_big_step3(a, b, ps, qs.a_size);
	}
	ps_selection_sort(a, b, qs);
}

t_quick_sort	ps_big_step1(t_stack *a, t_stack *b, t_push_swap *ps)
{
	t_quick_sort	qs;

	ps_set(a, ps, a->size);
	qs = ps_section_size(a->size);
	ps->median2 = ps_second_median(ps, STACK_B);
	ps_qs_small1(a, b, ps, b->size + qs.b_size);
	ps->status = NOT_ORDER;
	return (qs);
}

static void	ps_medium(t_stack *a, t_stack *b, t_push_swap *ps, t_quick_sort qs)
{
	while (qs.a_size > MIN_SIZE)
	{
		ps_big_step2(a, b, ps, qs.a_size);
		if (ps->status == NOT_ORDER)
		{
			ps->status = ORDER;
			qs = ps_section_size(qs.b_size);
			qs = ps_qs_big(ps, qs.b_size);
		}
		else
		{
			if (ps->status >= ORDER)
			{
				while (b->bottom->nb >= ps->median2)
					reverse_rotate(a, STACK_A);
			}
			qs = ps_qs_big(ps, qs.b_size);
		}
	}
	ps_selection_sort(a, b, qs);
	if (b->size > 0)
		qs = ps_qs_big(ps, b->size);
	ps_selection_sort(a, b, qs);
}

void	ps_big(t_stack *a, t_stack *b, t_push_swap *ps)
{
	t_quick_sort	qs;
	int				type;

	type = BIG;
	if (a->size <= 100)
		type = MEDIUM;
	qs = ps_big_step1(a, b, ps);
	if (type == BIG)
	{
		while (qs.a_size > MIN_SIZE)
		{
			ps_big_step2(a, b, ps, qs.a_size);
			ps->status = ORDER;
			qs = ps_qs_big(ps, qs.b_size);
		}
		ps_selection_sort(a, b, qs);
	}
	else
		ps_medium(a, b, ps, qs);
}
