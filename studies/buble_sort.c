/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buble_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:45:15 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/28 23:00:40 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_small_swap(t_stack *a, t_stack *b)
{
	if (a->top->nb > a->top->next->nb)
	{
		if (b->size > 1 && b->top->next->nb > b->top->nb)
			double_swap(a->top, b->top);
		else
			swap(a->top, STACK_A);
	}
	else if (b->size > 1 && b->top->next->nb > b->top->nb)
		swap(b->top, STACK_B);
}

void	ps_buble_sort(t_stack *a, t_stack *b) // na verdade não sei se é mesmo o buble sort..
{
	while (ps_check_order(a->top) != ORDER && a->size > 2)
	{
		ps_small_swap(a, b);
		push(a, b, STACK_B);
	}
	while (b->size > 0)
	{
		ps_small_swap(a, b);
		push(b, a, STACK_A);
	}
}
