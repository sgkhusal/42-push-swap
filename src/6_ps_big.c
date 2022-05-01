/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_ps_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:37:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/01 20:39:01 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //////

void	ps_big_step1(t_stack *a, t_stack *b, t_push_swap *ps, int size);

void	print_stack2(t_stack *stack)
{
	t_dlist	*tmp;

	tmp = stack->top;
	while (tmp != NULL)
	{
		ft_printf("%i ", tmp->nb);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

/* static void	ps_swap(t_stack *a, t_stack *b)
{
	if (a->top->nb > a->top->next->nb)
	{
		if (b->size > 1 && b->top->next->nb > b->top->nb && b->top->nb != b->min)
			double_swap(a->top, b->top);
		else
			swap(a->top, STACK_A);
	}
	else if (b->size > 1 && b->top->next->nb > b->top->nb && b->top->nb != b->min)
		swap(b->top, STACK_B);
} */

/* static void	ps_rotate(t_stack *a, t_stack *b, t_push_swap *ps)
{
	if ((b->size > 1 && b->top->nb <= ps->median2))
		double_rotate(a, b);
	else
		rotate(a, STACK_A);
} */

static void	ps_set(t_stack *s, t_push_swap *ps, int size)
{
	if (ps->order != NULL)
		clean_stack(ps->order);
	ps->order = init_stack();
	if (ps->status >= ORDER)
		ps->order->top = dlstdup_small(s->top, s->size, size);
	else
		ps->order->top = dlstdup(s->top, size);
	ps->order->max = s->max;
	ps->order->min = s->min;
	ps->order->size = size;
	ps->median = ps_median(ps);
}

void	ps_quick_sort_smaller1(t_stack *a, t_stack *b, t_push_swap *ps, int ref) // joga no b
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

void	ps_quick_sort_smaller2(t_stack *a, t_stack *b, t_push_swap *ps, int ref) // joga no b
{
	while (b->size < ref)
	{
		if (a->top->nb >= ps->median)
			rotate(a, STACK_A);
		else
			push(a, b, STACK_B);
	}
}

void	ps_quick_sort_smaller3(t_stack *a, t_stack *b, t_push_swap *ps, int ref) // joga no b
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
}

void	ps_quick_sort_bigger(t_stack *a, t_stack *b, double median, int ref) // joga no a
{
	while (a->size < ref)
	{
		if (b->top->nb < median)
			rotate(b, STACK_B);
		else
			push(b, a, STACK_A);
	}
}

t_quick_sort	ps_section_size(int size)
{
	t_quick_sort	qs;

	if (size % 2 == ODD)
	{
		qs.a_size = size / 2 + 1; // a mediana estará sempre no a
		qs.b_size = qs.a_size - 1;
	}
	else
	{
		qs.a_size = size / 2;
		qs.b_size = qs.a_size;
	}
	return(qs);
}

void	ps_big_step2(t_stack *a, t_stack *b, t_push_swap *ps, int size)
{
	t_quick_sort	qs;

	ps_set(a, ps, size);
	qs = ps_section_size(size);
	ps_quick_sort_smaller2(a, b, ps, b->size + qs.b_size);
	if (ps_check_order(a->top) != ORDER)
		ps_selection_sort(a, b, b->size);
	ps_selection_sort_section_b(a, b, qs.b_size);
}

void	ps_big_step1(t_stack *a, t_stack *b, t_push_swap *ps, int size)
{
	t_quick_sort	qs;

	ps_set(a, ps, size);
	qs = ps_section_size(size);
	//if (ps->status <= ORDER)
		ps_quick_sort_smaller2(a, b, ps, b->size + qs.b_size); // 125, 63/62, 32/31, 16, 8
	/* else
		ps_quick_sort_smaller3(a, b, ps, b->size + qs.b_size); // 125, 63/62, 32/31, 16, 8 */
	if (ps->status == ORDER)
		ps->status++;
	while (qs.a_size > 13) // 125, 63/62, 32/31, 16
	{
		ps_big_step1(a, b, ps, qs.a_size); // 63/62, 32/31, 16
		ps_set(b, ps, qs.b_size);
		qs = ps_section_size(qs.b_size);
		ps_quick_sort_bigger(a, b, ps->median, a->size + qs.a_size); // 31, 16, 8
		/* if (qs.a_size > 13) // 31, 16
			ps_big_step2(a, b, ps, qs.a_size); // 31, 16 */
	}
	if (ps_check_order(a->top) != ORDER) // 8, 8 (16),
		ps_selection_sort(a, b, b->size);
	ps_selection_sort_section_b(a, b, qs.b_size);
}

void	ps_big(t_stack *a, t_stack *b, t_push_swap *ps)
{
	t_quick_sort	qs;

	ps_set(a, ps, a->size);
	qs = ps_section_size(a->size);
	ps->median2 = ps_second_median(ps, STACK_B);
	ps_quick_sort_smaller1(a, b, ps, b->size + qs.b_size);
	ps->status = NOT_ORDER;
	while (qs.a_size > 13)
	{
		ps_big_step1(a, b, ps, qs.a_size); // 250 -> resolve a primeira metade , 125, 63 , 31, 16
		ps->status = ORDER;
		ps_set(b, ps, qs.b_size); // 250
		qs = ps_section_size(qs.b_size);
		ps_quick_sort_bigger(a, b, ps->median, a->size + qs.a_size); // 250b -> 125a // 125 -> 63 // 62 -> 31 // 31 -> 16 // 15 -> 8
	}
	if (ps_check_order(a->top) != ORDER)
		ps_selection_sort(a, b, b->size);
	if (b->size > 0)
		ps_selection_sort_section_b(a, b, qs.b_size);

	/* ft_printf("Result:\n");
	print_stack2(a);
	if (b->size > 0)
		print_stack2(b); */
}
