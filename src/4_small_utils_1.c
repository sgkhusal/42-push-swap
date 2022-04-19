/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_small_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:33:41 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/19 05:36:43 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_max_top(t_stack *a)
{
	if (a->top->nb == a->max)
	{
		if (ps_check_order(a->top->next) == ORDER)
		{
			rotate(a, STACK_A);
			return (ORDER);
		}
	}
	return (NOT_ORDER);
}

int	ps_small_part1(t_stack *a, t_stack *b)
{
	if (a->bottom->nb == a->min)
		reverse_rotate(a, STACK_A);
	if (a->top->nb != a->max)
	{
		if (a->top->next->nb < a->top->nb || a->top->next->nb == a->max)
			swap(a->top, STACK_A);
	}
	if (ps_check_order(a->top) == ORDER)
		return (ORDER);
	push(a, b, STACK_B);
	b->size++;
	a->min = stack_min(a);
	a->max = stack_max(a);
	if (b->size > 1)
	{
		b->min = stack_min(b);
		if (b->top->nb == b->min)
		{
			if (b->top->nb < a->max)
				rotate(b, STACK_B);
		}
	}
	return (NOT_ORDER);
}

int	ps_small_part2(t_stack *a, t_stack *b)
{
	push(b, a, STACK_A);
	b->size--;
	a->min = stack_min(a);
	a->max = stack_max(a);
	if (a->top->nb == a->min)
		return (ORDER);
	if (a->top->nb == a->max)
		rotate(a, STACK_A);
	if (a->top->next->nb < a->top->nb)
		swap(a->top, STACK_A);
	if (ps_check_order(a->top) == ORDER)
		return (ORDER);
	else
		return (NOT_ORDER);
}

/* void	ps_check_swap(t_push_swap *data)
{
	if (data->stack_a->top->next->nb < data->stack_a->top->nb)
	{
		if (data->stack_b->size > 1)
		{
			if (data->stack_b->top->next->nb > data->stack_b->top->nb)
				double_swap(data->stack_a->top, data->stack_b->top);
			else
				swap(data->stack_a->top, STACK_A);
		}
		else
			swap(data->stack_a->top, STACK_A);
	}
	else if (data->stack_b->size > 1)
	{
		if (data->stack_b->top->next->nb > data->stack_b->top->nb)
			swap(data->stack_b->top, STACK_B);
	}
} */

void	ps_check_swap_small(t_stack *a, t_stack *b)
{
	if (a->top->nb != a->max)
	{
		if (a->top->next->nb < a->top->nb || a->top->next->nb == a->max)
		{
			if (b->size > 1)
			{
				if (b->top->next->nb > b->top->nb)
					double_swap(a->top, b->top);
				else
					swap(a->top, STACK_A);
			}
			else
				swap(a->top, STACK_A);
		}
	}
	else if (b->size > 1)
	{
		if (b->top->next->nb > b->top->nb)
			swap(b->top, STACK_B);
	}
}

void	ps_small(t_stack *a, t_stack *b)
{
	if (rotate_max_top(a) == ORDER)
		return ;
	if (a->bottom->nb == a->min)
		reverse_rotate(a, STACK_A);
	ps_check_swap_small(a, b);
	if (ps_check_order(a->top) == ORDER)
		return ;
	push(a, b, STACK_B);
	b->size++;
	a->size--;
	a->min = stack_min(a);
	a->max = stack_max(a);
	if (b->size > 1) ///
	{
		b->min = stack_min(b);
		if (b->top->nb == b->min)
		{
			if (b->top->nb < a->max)
				rotate(b, STACK_B);
		}
	}
	if (a->size > 3)
		ps_small(a, b);
}
