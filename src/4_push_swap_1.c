/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_push_swap_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:33:41 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/17 03:39:05 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_order_3(t_push_swap *data)
{
	if (data->stack_a->init->nb == data->smaller)
	{
		reverse_rotate(data->stack_a, STACK_A);
		swap(data->stack_a->init, STACK_A);
	}
	else if (data->stack_a->init->nb == data->bigger)
	{
		rotate(data->stack_a, STACK_A);
		if (data->stack_a->init->next->nb == data->smaller)
			swap(data->stack_a->init, STACK_A);
	}
	else
	{
		if (data->stack_a->init->next->nb == data->smaller)
			swap(data->stack_a->init, STACK_A);
		else
			reverse_rotate(data->stack_a, STACK_A);
	}
}

void	ps_one_mov(t_push_swap *data)
{
	if (data->stack_a->init->nb == data->bigger)
	{
		if (ps_check_order(data->stack_a->init->next) == ORDER)
		{
			rotate(data->stack_a, STACK_A);
			exit(EXIT_SUCCESS);
		}
	}
}

void	ps_my(t_push_swap *data)
{
	if (data->stack_a->end->nb == data->smaller)
		reverse_rotate(data->stack_a, STACK_A);
	else if (data->stack_a->init->nb == data->bigger)
		rotate(data->stack_a, STACK_A);
	else if (data->stack_a->init->nb > data->stack_a->init->next->nb)
		swap(data->stack_a->init, STACK_A);
	else if (data->stack_size > 2)
	{
		push(data->stack_a, data->stack_b, STACK_A);
		data->stack_b_size++;
		data->stack_size--;
	}
	else if (data->stack_b_size > 0)
	{
		push(data->stack_b, data->stack_a, STACK_B);
		data->stack_b_size--;
		data->stack_size++;
	}
	if (ps_check_order(data->stack_a->init) == ORDER && data->stack_b_size == 0)
		exit(EXIT_SUCCESS);
	else
		ps_my(data);
}

void	ps_order_4(t_push_swap *data)
{
	ps_one_mov(data);
	if (data->stack_a->init->nb == data->smaller)
	{
		push(data->stack_a, data->stack_b, STACK_B);
		data->smaller = ps_smaller(data->stack_a);
		ps_order_3(data);
		push(data->stack_a, data->stack_b, STACK_A);
	}
	else if (data->stack_a->init->nb == data->bigger)
	{
		push(data->stack_a, data->stack_b, STACK_B);
		data->bigger = ps_bigger(data->stack_a);
		ps_order_3(data);
		push(data->stack_a, data->stack_b, STACK_A);
	}
	else
		ps_my(data);
}
