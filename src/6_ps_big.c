/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_ps_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:37:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/30 16:30:23 by sguilher         ###   ########.fr       */
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
	if (a->top->nb > ps->median && (b->size > 1 && b->top->nb < b->bottom->nb))
		double_rotate(a, b);
	else if (a->top->nb > ps->median)
		rotate(a, STACK_A);
	else if (b->size > 1 && b->top->nb < b->bottom->nb)
		rotate(b, STACK_B);
} */

static void	ps_set(t_stack *s, t_push_swap *ps, int size)
{
	if (ps->order != NULL)
		clean_stack(ps->order);
	ps->order = init_stack();
	ps->order->top = dlstdup(s->top, size);
	ps->order->max = s->max;
	ps->order->min = s->min;
	ps->order->size = size;
	ps->median = ps_median(ps);
}

void	ps_quick_sort_smaller(t_stack *a, t_stack *b, int median, int ref) // joga no b
{
	while (b->size < ref)
	{
		if (a->top->nb > median)
			rotate(a, STACK_A);
		else
			push(a, b, STACK_B);
	}
}

void	ps_quick_sort_bigger(t_stack *a, t_stack *b, int median, int ref) // joga no a
{
	while (a->size < ref)
	{
		if (b->top->nb <= median)
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

void	ps_big_step1(t_stack *a, t_stack *b, t_push_swap *ps)
{
	t_quick_sort	qs;

	ps_set(a, ps, a->size);
	qs = ps_section_size(a->size);
	ps_quick_sort_smaller(a, b, ps->median, b->size + qs.b_size);
	if (a->size > 13)
	{
		ps_big_step1(a, b, ps);
		ps_set(b, ps, qs.b_size);
		qs = ps_section_size(qs.b_size);
		ps_quick_sort_bigger(a, b, ps->median, a->size + qs.a_size);
		//if (qs.a_size > 13) //// AQUI!!!!!!!!!!!!!!!!!!!!!
		ps_selection_sort(a, b, b->size);
		ps_selection_sort_section_b(a, b, qs.b_size);
	}
	else
	{
		ps_selection_sort(a, b, b->size);
		ps_selection_sort_section_b(a, b, qs.b_size);
	}
}

void	ps_big(t_stack *a, t_stack *b, t_push_swap *ps)
{
	ps_big_step1(a, b, ps);
	/* ft_printf("Result:\n");
	print_stack2(a);
	if (b->size > 0)
		print_stack2(b); */
}
