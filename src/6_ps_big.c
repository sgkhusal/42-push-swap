/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_ps_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:37:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/28 22:49:27 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ps_big(t_stack *a, t_stack *b, t_push_swap *ps)
{
	ps->order = init_stack();
	ps->order->top = dlstdup(ps->stack_a->top);
	//ps->order->bottom
	ps->order->max = a->max;
	ps->order->min = a->min;
	ps->order->size = a->size;
	ps->median = ps_median(ps);
	//ps_insertion_sort(a, b);
	/* while (ps_check_order(a->top) != ORDER || b->size > 0)
		ps_buble_sort(a, b); */
	ft_printf("Result:\n");
	print_stack2(ps->order);
	if (b->size > 0)
		print_stack2(b);
}
