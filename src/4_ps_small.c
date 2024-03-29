/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ps_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:22:50 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/06 01:44:41 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_order_3(t_stack *a)
{
	if (a->top->nb == a->max)
		rotate(a, STACK_A);
	else if (a->top->next->nb == a->max)
		reverse_rotate(a, STACK_A);
	if (a->top->nb > a->top->next->nb)
		swap(a->top, STACK_A);
}

static void	ps_small_swap(t_stack *a, t_stack *b)
{
	if (b->size > 1 && b->top->next->nb > b->top->nb && \
	b->top->next->nb < a->max)
		double_swap(a->top, b->top);
	else
		swap(a->top, STACK_A);
}

static void	ps_small_part1(t_stack *a, t_stack *b)
{
	if (a->bottom->nb == a->min)
		reverse_rotate(a, STACK_A);
	else if (a->top->nb == a->max)
	{
		if (b->size > 1 && b->top->nb == b->min)
			double_rotate(a, b);
		else
			rotate(a, STACK_A);
	}
	else if (b->size > 1 && b->top->nb == b->min)
		rotate(b, STACK_B);
	else if (a->top->next->nb < a->top->nb || (a->top->next->nb == a->max && \
	a->top->nb != a->min))
		ps_small_swap(a, b);
	else if (a->size == 3)
		ps_order_3(a);
	else if (ps_check_order(a->top) != ORDER)
		push(a, b, STACK_B);
}

static void	ps_small_part2(t_stack *a, t_stack *b)
{
	if (b->size > 1 && b->top->nb == b->min && b->top->nb < a->max)
		rotate(b, STACK_B);
	push(b, a, STACK_A);
	if (a->top->nb == a->max)
		rotate(a, STACK_A);
	if (a->top->next->nb < a->top->nb)
		ps_small_swap(a, b);
	while (ps_check_order(a->top) != ORDER)
		ps_small_part1(a, b);
}

void	ps_small(t_stack *a, t_stack *b)
{
	while (ps_check_order(a->top) != ORDER)
		ps_small_part1(a, b);
	while (b->size > 0)
		ps_small_part2(a, b);
	if (ps_check_order(a->top) == ORDER && b->size == 0)
		return ;
	else
		ps_small(a, b);
}
