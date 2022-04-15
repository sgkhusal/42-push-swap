/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_push_swap_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:33:41 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/15 02:21:39 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_order_2(t_stack *stack)
{
	t_dlist	*aux;

	aux = stack->init;
	stack->init = stack->end;
	stack->end = aux;
	stack->init->prev = NULL;
	stack->init->next = stack->end;
	stack->end->prev = stack->init;
	stack->end->next = NULL;
	ft_putstr_fd("sa\n", 1);
}

void	ps_order_3(t_push_swap *data)
{
	if (data->stack_a->init->nb == data->smaller)
	{
		reverse_rotate(data->stack_a, STACK_A);
		swap(&data->stack_a->init, STACK_A);
	}
	else if (data->stack_a->init->nb == data->bigger)
	{
		if (data->stack_a->init->next->nb == data->smaller)
			rotate(data->stack_a, STACK_A);
		else
		{
			rotate(data->stack_a, STACK_A);
			swap(&data->stack_a->init, STACK_A);
		}
	}
	else
	{
		if (data->stack_a->init->next->nb == data->smaller)
			swap(&data->stack_a->init, STACK_A);
		else
			reverse_rotate(data->stack_a, STACK_A);
	}
}
