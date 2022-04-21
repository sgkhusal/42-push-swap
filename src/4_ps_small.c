/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_small_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:22:50 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/21 22:16:14 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_order_3(t_stack *a, char s)
{
	if (ps_check_order(a->top) == ORDER)
		return ;
	if (a->top->nb == a->min)
	{
		reverse_rotate(a, s);
		swap(a->top, s);
	}
	else if (a->top->nb == a->max)
	{
		rotate(a, s);
		if (a->top->next->nb == a->min)
			swap(a->top, s);
	}
	else
	{
		if (a->top->next->nb == a->min)
			swap(a->top, s);
		else
			reverse_rotate(a, s);
	}
}

static void	ps_first_swap_small(t_stack *a, t_stack *b)
{
	if (a->top->nb != a->max)
	{
		if (a->top->next->nb < a->top->nb || (a->top->next->nb == a->max && \
		a->top->nb != a->min))
		{
			if (b->size > 1)
			{
				if (b->top->next->nb > b->top->nb && b->top->next->nb < a->max) /// verificar
					double_swap(a->top, b->top);
				else
					swap(a->top, STACK_A);
			}
			else
				swap(a->top, STACK_A);
		}
	}
	/* else if (b->size > 1)
	{
		if (b->top->next->nb > b->top->nb)
			swap(b->top, STACK_B);
	} */
}

static void	ps_small_part1(t_stack *a, t_stack *b)
{
	if (a->top->nb == a->max && ps_check_order(a->top->next) == ORDER)
		rotate(a, STACK_A);
	if (a->bottom->nb == a->min)
		reverse_rotate(a, STACK_A);
	ps_first_swap_small(a, b);
	if (ps_check_order(a->top) == NOT_ORDER)
		push(a, b, STACK_B);
	if (b->size > 1 && b->top->nb == b->min && b->top->nb < a->max)
		rotate(b, STACK_B); ///
	if (a->size == 3)
		ps_order_3(a, STACK_A);
}

static void	ps_small_part2(t_stack *a, t_stack *b)
{
	push(b, a, STACK_A);
	if (a->top->nb == a->min && b->size == 0)
		return ;
	if (a->top->nb == a->max)
		rotate(a, STACK_A);
	if (a->top->next->nb < a->top->nb)
		swap(a->top, STACK_A); // verificar se não faz um double swap
	while (ps_check_order(a->top) != ORDER)
		ps_small_part1(a, b);
}

void	ps_small(t_stack *a, t_stack *b, int size)
{
	while (ps_check_order(a->top) != ORDER)
		ps_small_part1(a, b);
	while (b->size > 0)
		ps_small_part2(a, b);
	if (ps_check_order(a->top) == ORDER && b->size == 0)
		return ;
	else
		ps_small(a, b, size);
}