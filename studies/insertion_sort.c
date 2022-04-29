/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:35:39 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/28 23:03:07 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_reverse_order_3(t_stack *b, char s)
{
	if (b->top->nb == b->min)
		rotate(b, s);
	else if (b->top->next->nb == b->min)
		reverse_rotate(b, s);
	if (b->top->nb < b->top->next->nb)
		swap(b->top, s);
}

void	order_b(t_stack *b)
{
	t_dlist	*aux;
	int			pos;
	int			i;

	aux = b->top->next;
	pos = 1;
	i = -1;
	while (b->top->nb < aux->nb)
	{
		pos++;
		aux = aux->next;
	}
	if (pos > b->size / 2 )
	{
		while(++i < b->size - pos)
		{
			reverse_rotate(b, STACK_B);
			swap(b->top, STACK_B);
		}
		i = -1;
		while(++i <= b->size - pos)
			rotate(b, STACK_B);
	}
	else
	{
		swap(b->top, STACK_B);
		while(++i < pos - 2)
		{
			rotate(b, STACK_B);
			swap(b->top, STACK_B);
		}
		i = -1;
		while(++i < pos - 2)
			reverse_rotate(b, STACK_B);
	}
}

void	ps_insertion_sort(t_stack *a, t_stack *b)
{
	while (ps_check_order(a->top) != ORDER && a->size > 0)
	{
		if (a->size > 1 && a->top->nb > a->top->next->nb)
			swap(a->top, STACK_A);
		if (a->size > 1)
		{
			push(a, b, STACK_B);
			if (b->size > 1 && ps_check_reverse_order(b->top) != ORDER)
			{
				if (b->size == 3)
					ps_reverse_order_3(b, STACK_B);
				else if (b->top->nb == b->min)
					rotate(b, STACK_B);
				else
					order_b(b);
			}
		}
	}
	while (b->size > 0)
		push(b, a, STACK_A);
}
