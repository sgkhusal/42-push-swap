/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_ps_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:37:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/30 00:58:25 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> ////////////////

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
	//ps->order->bottom
	ps->order->max = s->max;
	ps->order->min = s->min;
	ps->order->size = size;
	ps->median = ps_median(ps);
	//printf("median = %f\n", ps->median);
}

void	ps_quick_sort_smaller(t_stack *a, t_stack *b, t_push_swap *ps, int ref)
{
	//print_stack2(a);
	//print_stack2(b);
	while (b->size < ref)
	{
		if (a->top->nb > ps->median)
			rotate(a, STACK_A);
		else
			push(a, b, STACK_B);
	}
	//print_stack2(a);
	//print_stack2(b);
	//ft_printf("stack b size = %i\n", b->size);
}

void	ps_quick_sort_bigger(t_stack *a, t_stack *b, t_push_swap *ps, int ref)
{
	//printf("median = %f\n", ps->median);
	//print_stack2(a);
	//print_stack2(b);
	while (a->size < ref)
	{
		if (b->top->nb < ps->median)
			rotate(b, STACK_B);
		else
			push(b, a, STACK_A);
	}
	//print_stack2(a);
	//print_stack2(b);
	//ft_printf("stack b size = %i\n", b->size);
}

int		ps_section_size(int size)
{
	if (size % 2 == ODD)
		return(size / 2 + 1);
	else
		return(size / 2);
}

void	ps_big_step1(t_stack *a, t_stack *b, t_push_swap *ps)
{
	int	qty_a;
	int	qty_b;

	qty_a = ps_section_size(a->size);
	if (a->size % 2 == ODD)
		qty_b = qty_a - 1;
	else
		qty_b = qty_a;
	//ft_printf("qty_a = %i\n", qty_a);
	//ft_printf("qty_b = %i\n", qty_b);
	//ft_printf("stack half size = %i\n", qty);
	ps_quick_sort_smaller(a, b, ps, b->size + qty_b);
	//ft_printf("stack_a size = %i\n", a->size);
	//ft_printf("stack_b size = %i\n", b->size);
	if (a->size > 13)
	{
		ps_set(a, ps, a->size);
		ps_big_step1(a, b, ps);
		//ft_printf("stack a size = %i\n", a->size);
		ps_set(b, ps, qty_b);
		qty_a = ps_section_size(qty_b);
		if (qty_b % 2 == ODD)
			qty_b = qty_a - 1;
		else
			qty_b = qty_a;
		ps_quick_sort_bigger(a, b, ps, a->size + qty_a);
		ps_selection_sort(a, b, b->size);
		ps_selection_sort_section_b(a, b, qty_b);
	}
	else
	{
		ps_selection_sort(a, b, b->size);
		ps_selection_sort_section_b(a, b, qty_b);
	}
}

/* void	ps_big_step1(t_stack *a, t_stack *b, t_push_swap *ps)
{
	int	qty;

	qty = a->size / 2;
	while (b->size < qty)
	{
		if (a->top->nb > ps->median)
			rotate(a, STACK_A);
		else
			push(a, b, STACK_B);
	}
} */

void	ps_big(t_stack *a, t_stack *b, t_push_swap *ps)
{
	ps_set(a, ps, a->size);
	ps_big_step1(a, b, ps);
	/* ft_printf("Result:\n");
	print_stack2(a);
	if (b->size > 0)
		print_stack2(b); */
}
