/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_small_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:33:41 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/19 21:38:52 by sguilher         ###   ########.fr       */
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
		if (a->top->next->nb < a->top->nb || (a->top->next->nb == a->max && \
		a->top->nb != a->min))
			swap(a->top, STACK_A);
	}
	if (ps_check_order(a->top) == ORDER)
		return (ORDER);
	push(a, b, STACK_B);
	if (b->size > 1 && b->top->nb == b->min && b->top->nb < a->max)
		rotate(b, STACK_B);
	return (NOT_ORDER);
}

int	ps_small_part2(t_stack *a, t_stack *b)
{
	push(b, a, STACK_A);
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

void	ps_first_swap_small(t_stack *a, t_stack *b)
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
	else if (b->size > 1)
	{
		if (b->top->next->nb > b->top->nb)
			swap(b->top, STACK_B);
	}
}

void	ps_small_part11(t_stack *a, t_stack *b)
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

void	ps_small_part12(t_stack *a, t_stack *b)
{
	push(b, a, STACK_A);
	if (a->top->nb == a->min && b->size == 0)
		return ;
	if (a->top->nb == a->max)
		rotate(a, STACK_A);
	if (a->top->next->nb < a->top->nb)
		swap(a->top, STACK_A); // verificar se não faz um double swap
}

void	ps_small(t_stack *a, t_stack *b, int size)
{
	if (size == 4)
		ps_order_4_special_case(a, STACK_A);
	while (ps_check_order(a->top) != ORDER)
		ps_small_part11(a, b);
	while (b->size > 0)
		ps_small_part12(a, b);
	if (ps_check_order(a->top) == ORDER && b->size == 0)
		return ;
	else
		ps_small(a, b, size);
}
