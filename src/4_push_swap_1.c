/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_push_swap_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:33:41 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/18 01:49:36 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# include "test.h" ///////////////////////////

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
			rotate(data->stack_a, STACK_A);
	}
	if (data->stack_a->end->nb == data->smaller)
		reverse_rotate(data->stack_a, STACK_A);
}

void	ps_order_4_special_case(t_push_swap *data, t_stack *stack, char s)
{
	if (stack->init->next->nb == data->bigger)
	{
		if ((stack->end->prev->nb == data->smaller))
		{
			if (stack->init->nb > stack->end->nb)
			{
				reverse_rotate(stack, s);
				reverse_rotate(stack, s);
			}
		}
	}
}

void	ps_order_4(t_push_swap *data)
{
	ps_one_mov(data);
	ps_order_4_special_case(data, data->stack_a, STACK_A);
	if (data->stack_a->init->nb != data->bigger)
	{
		if (data->stack_a->init->next->nb < data->stack_a->init->nb)
			swap(data->stack_a->init, STACK_A);
	}
	if (ps_check_order(data->stack_a->init) == ORDER)
		return ;
	push(data->stack_a, data->stack_b, STACK_B);
	data->smaller = ps_smaller(data->stack_a);
	data->bigger = ps_bigger(data->stack_a);
	ps_order_3(data);
	push(data->stack_b, data->stack_a, STACK_A);
	data->smaller = ps_smaller(data->stack_a);
	data->bigger = ps_bigger(data->stack_a);
	if (data->stack_a->init->nb == data->smaller)
		return ;
	else if (data->stack_a->init->nb == data->bigger)
		rotate(data->stack_a, STACK_A);
	else
		ps_order_4(data);
}

void	ola(t_push_swap *data)
{
	if (data->stack_a->end->nb == data->smaller)
	{
		reverse_rotate(data->stack_a, STACK_A);
		if (ps_check_order(data->stack_a->init) == ORDER)
			ps_close(data);
	}
	else if (data->stack_a->init->nb == data->bigger)
	{
		rotate(data->stack_a, STACK_A);
		if (ps_check_order(data->stack_a->init) == ORDER)
			ps_close(data);
	}

}
