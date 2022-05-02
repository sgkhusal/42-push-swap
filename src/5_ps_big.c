/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ps_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:37:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/02 16:25:23 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	ps_set(t_stack *s, t_push_swap *ps, int size)
{
	if (ps->order != NULL)
		clean_stack(ps->order);
	ps->order = init_stack();
	ps->order->top = dlstdup(s->top, size);
	ps->order->max = stack_max(s);
	ps->order->min = stack_min(s);
	ps->order->size = size;
	ps->median = ps_median(ps);
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

static void	ps_big_step3(t_stack *a, t_stack *b, t_push_swap *ps, int size)
{
	t_quick_sort	qs;

	ps_set(a, ps, size);
	qs = ps_section_size(size);
	ps_qs_small2(a, b, ps, b->size + qs.b_size);
	/* ft_printf("\nStack division - big step2:\n");
	ft_printf("qs_a: %i, qs_b: %i\n", qs.a_size, qs.b_size);
	ft_printf("median: %i\n", (int)ps->median);
	print_stack2(ps->order);
	print_stack2(a);
	print_stack2(b); */
	if (ps_check_order(a->top) != ORDER)
		ps_selection_sort(a, b, b->size);
	ps_selection_sort_b(a, b, qs.b_size);
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
	ps_qs_small2(a, b, ps, b->size + qs.b_size); // 125, 63/62, 32/31, 16, 8
	/* ft_printf("\nStack division - big step1 1:\n");
	ft_printf("qs_a: %i, qs_b: %i\n", qs.a_size, qs.b_size);
	ft_printf("median: %i\n", (int)ps->median);
	print_stack2(ps->order);
	print_stack2(a);
	print_stack2(b); */
	if (ps->status == ORDER)
		ps->status++;
	if (qs.a_size > 13) // 125, 63/62, 32/31, 16 // while
	{
		ps_big_step2(a, b, ps, qs.a_size); // 63/62, 32/31, 16
		//ft_printf("qs_a: %i, qs_b: %i\n", qs.a_size, qs.b_size);
		ps_set(b, ps, qs.b_size);
		qs = ps_section_size(qs.b_size);
		ps_qs_big(a, b, ps->median, a->size + qs.a_size); // 31, 16, 8
		/* ft_printf("\nStack division - big step1 2:\n");
		ft_printf("qs_a: %i, qs_b: %i\n", qs.a_size, qs.b_size);
		ft_printf("median: %i\n", (int)ps->median);
		print_stack2(ps->order);
		print_stack2(a);
		print_stack2(b); */
		if (qs.a_size > 13) // 31, 16 // comentar
		{
			ps_big_step3(a, b, ps, qs.a_size); // 31, 16
			//ps_set(b, ps, qs.b_size);
			//qs = ps_section_size(qs.b_size);
			//ps_qs_big(a, b, ps->median, a->size + qs.a_size);
		}
		/* ft_printf("\nStack division - big step1 3:\n");
		ft_printf("qs_a: %i, qs_b: %i\n", qs.a_size, qs.b_size);
		ft_printf("median: %i\n", (int)ps->median);
		print_stack2(ps->order);
		print_stack2(a);
		print_stack2(b); */
	}
	if (ps_check_order(a->top) != ORDER) // 8, 8 (16),
		ps_selection_sort(a, b, b->size);
	ps_selection_sort_b(a, b, qs.b_size);
	/* ft_printf("\nSemi order:\n");
	print_stack2(ps->order);
	print_stack2(a);
	print_stack2(b); */
}

void	ps_big(t_stack *a, t_stack *b, t_push_swap *ps)
{
	t_quick_sort	qs;

	ps_set(a, ps, a->size);
	qs = ps_section_size(a->size);
	ps->median2 = ps_second_median(ps, STACK_B);
	ps_qs_small1(a, b, ps, b->size + qs.b_size);
	ps->status = NOT_ORDER;
	/* ft_printf("\nFirst stack division:\n");
	ft_printf("qs_a: %i, qs_b: %i\n", qs.a_size, qs.b_size);
	ft_printf("median: %i, second median: %i\n", (int)ps->median, (int)ps->median2);
	print_stack2(a);
	print_stack2(b); */
	while (qs.a_size > 13)
	{
		ps_big_step2(a, b, ps, qs.a_size); // 250 -> resolve a primeira metade , 125, 63 , 31, 16
		ps->status = ORDER;
		ps_set(b, ps, qs.b_size); // 250
		qs = ps_section_size(qs.b_size);
		ps_qs_big(a, b, ps->median, a->size + qs.a_size); // 250b -> 125a // 125 -> 63 // 62 -> 31 // 31 -> 16 // 15 -> 8
		/* ft_printf("\nStack division:\n");
		ft_printf("qs_a: %i, qs_b: %i\n", qs.a_size, qs.b_size);
		ft_printf("median: %i\n", (int)ps->median);
		print_stack2(ps->order);
		print_stack2(a);
		print_stack2(b); */
	}
	if (ps_check_order(a->top) != ORDER)
		ps_selection_sort(a, b, b->size);
	if (b->size > 0)
		ps_selection_sort_b(a, b, qs.b_size);

	/* ft_printf("Result:\n");
	print_stack2(a);
	if (b->size > 0)
		print_stack2(b); */
}
