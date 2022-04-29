/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ps_selection_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:17:39 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/28 23:35:05 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	dlist_min_pos(t_stack *a)
{
	t_dlist	*aux;
	int		pos;

	aux = a->top;
	pos = 1;
	while (aux->nb != a->min)
	{
		aux = aux->next;
		pos++;
	}
	return (pos);
}

void	ps_selection_sort(t_stack *a, t_stack *b)
{
	int	pos;

	while (a->size > 3 && ps_check_order(a->top) != ORDER)
	{
		pos = dlist_min_pos(a);
		while (a->top->nb != a->min)
		{
			if (pos > a->size / 2)
				reverse_rotate(a, STACK_A);
			else
				rotate(a, STACK_A);
		}
		push(a, b, STACK_B);
	}
	if (a->size == 3)
		ps_order_3(a, STACK_A);
	while (b->size > 0)
		push(b, a, STACK_A);
}
