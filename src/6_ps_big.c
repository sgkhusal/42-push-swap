/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_ps_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:37:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/29 22:15:12 by sguilher         ###   ########.fr       */
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
	while (b->size < ref)
	{
		//ps_swap(a, b);
		if (a->top->nb > ps->median && (b->size > 1 && b->top->nb < b->bottom->nb))
			double_rotate(a, b);
		else if (a->top->nb > ps->median)
			rotate(a, STACK_A);
		else if (b->size > 1 && b->top->nb < b->bottom->nb)
			rotate(b, STACK_B);
		else
		{
			push(a, b, STACK_B);
			//ps_swap(a, b);
		}
		/* if (a->top->nb > ps->median)
			rotate(a, STACK_A);
		else
			push(a, b, STACK_B); */
	}
	//ft_printf("stack b size = %i\n", b->size);
	//ps_rotate(a, b, ps);
}

void	ps_quick_sort_bigger(t_stack *a, t_stack *b, t_push_swap *ps, int ref)
{
	//printf("median = %f\n", ps->median);
	//print_stack2(b);
	while (a->size < ref)
	{
		//ps_swap(a, b);
		if (b->top->nb < ps->median)
			rotate(b, STACK_B);
		else
		{
			push(b, a, STACK_A);
			//ps_swap(a, b);
		}
	}
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
	int	qty;
	int	type;

	type = EVEN;
	qty = ps_section_size(a->size);
	if (qty % 2 == ODD)
		type = ODD;
	//ft_printf("stack half size = %i\n", qty);
	ps_quick_sort_smaller(a, b, ps, b->size + qty);
	if (a->size >= 10)
	{
		ps_set(a, ps, a->size);
		ps_big_step1(a, b, ps);
		//ft_printf("qty = %i\n", qty);
		//ft_printf("stack a size = %i\n", a->size);
		ps_set(b, ps, qty);
		qty = ps_section_size(qty);
		//ft_printf("qty = %i\n", qty);
		ps_quick_sort_bigger(a, b, ps, a->size + qty);
		ps_selection_sort(a, b, b->size);
		//ft_printf("qty = %i\n", qty);
		if (type == ODD)
			qty = qty - 1;
		ps_selection_sort_section_b(a, b, qty);
	}
	else
	{
		ps_selection_sort(a, b, b->size);
		ps_selection_sort_section_b(a, b, qty);
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
