/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_small_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:33:41 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/19 04:31:02 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_bigger_first(t_stack *a)
{
	if (a->init->nb == a->bigger)
	{
		if (ps_check_order(a->init->next) == ORDER)
		{
			rotate(a, STACK_A);
			return (ORDER);
		}
	}
	return (NOT_ORDER);
}

int	ps_small_part1(t_stack *a, t_stack *b)
{
	if (a->end->nb == a->smaller)
		reverse_rotate(a, STACK_A);
	if (a->init->nb != a->bigger)
	{
		if (a->init->next->nb < a->init->nb || \
		a->init->next->nb == a->bigger)
			swap(a->init, STACK_A);
	}
	if (ps_check_order(a->init) == ORDER)
		return (ORDER);
	push(a, b, STACK_B);
	b->size++;
	a->smaller = ps_smaller(a);
	a->bigger = ps_bigger(a);
	if (b->size > 1)
	{
		b->smaller = ps_smaller(b);
		if (b->init->nb == b->smaller)
		{
			if (b->init->nb < a->bigger)
				rotate(b, STACK_B);
		}
	}
	return (NOT_ORDER);
}

int	ps_small_part2(t_stack *a, t_stack *b)
{
	push(b, a, STACK_A);
	b->size--;
	a->smaller = ps_smaller(a);
	a->bigger = ps_bigger(a);
	if (a->init->nb == a->smaller)
		return (ORDER);
	if (a->init->nb == a->bigger)
		rotate(a, STACK_A);
	if (a->init->next->nb < a->init->nb)
		swap(a->init, STACK_A);
	if (ps_check_order(a->init) == ORDER)
		return (ORDER);
	else
		return (NOT_ORDER);
}

/* void	ps_check_swap(t_push_swap *data)
{
	if (data->stack_a->init->next->nb < data->stack_a->init->nb)
	{
		if (data->stack_b->size > 1)
		{
			if (data->stack_b->init->next->nb > data->stack_b->init->nb)
				double_swap(data->stack_a->init, data->stack_b->init);
			else
				swap(data->stack_a->init, STACK_A);
		}
		else
			swap(data->stack_a->init, STACK_A);
	}
	else if (data->stack_b->size > 1)
	{
		if (data->stack_b->init->next->nb > data->stack_b->init->nb)
			swap(data->stack_b->init, STACK_B);
	}
} */

void	ps_check_swap_small(t_stack *a, t_stack *b)
{
	if (a->init->nb != a->bigger)
	{
		if (a->init->next->nb < a->init->nb || a->init->next->nb == a->bigger)
		{
			if (b->size > 1)
			{
				if (b->init->next->nb > b->init->nb)
					double_swap(a->init, b->init);
				else
					swap(a->init, STACK_A);
			}
			else
				swap(a->init, STACK_A);
		}
	}
	else if (b->size > 1)
	{
		if (b->init->next->nb > b->init->nb)
			swap(b->init, STACK_B);
	}
}

void	ps_small(t_stack *a, t_stack *b)
{
	if (ps_bigger_first(a) == ORDER)
		return ;
	if (a->end->nb == a->smaller)
		reverse_rotate(a, STACK_A);
	ps_check_swap_small(a, b);
	if (ps_check_order(a->init) == ORDER)
		return ;
	push(a, b, STACK_B);
	b->size++;
	a->size--;
	a->smaller = ps_smaller(a);
	a->bigger = ps_bigger(a);
	if (b->size > 1) ///
	{
		b->smaller = ps_smaller(b);
		if (b->init->nb == b->smaller)
		{
			if (b->init->nb < a->bigger)
				rotate(b, STACK_B);
		}
	}
	if (a->size > 3)
		ps_small(a, b);
}
