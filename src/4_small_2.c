/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_small_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 01:59:00 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/18 19:29:56 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_order_6(t_push_swap *data)
{
	ps_one_mov(data);
	if (ps_small_part1(data) == ORDER)
		return (ORDER);
	if (ps_small_part1(data) == ORDER)
	{
		push(data->stack_b, data->stack_a, STACK_A);
		if (ps_check_order(data->stack_a->init) == ORDER)
			return (ORDER);
		else
			return (ps_order_6(data)); // acho que pode entrar em loop
	}
	if (ps_small_part1(data) == ORDER) // problemas aqui
	{
		push(data->stack_b, data->stack_a, STACK_A);
		push(data->stack_b, data->stack_a, STACK_A);
	}
	else
	{
		ps_order_3(data->stack_a, STACK_A);
		data->stack_b->smaller = ps_smaller(data->stack_b);
		data->stack_b->bigger = ps_bigger(data->stack_b);
		ps_order_3_reverse(data->stack_b, STACK_B);
		ps_small_part2(data);
		ps_small_part2(data);
		if (ps_small_part2(data) == ORDER) // será que tem problemas??
			return (ORDER);
		else
			return (ps_order_6(data));
	}
	if (ps_check_order(data->stack_a->init) == ORDER)
		return (ORDER);
	else
		return (ps_order_6(data));
}

int	ps_order_7(t_push_swap *data)
{
	ps_one_mov(data);
	if (ps_small_part1(data) == ORDER)
		return (ORDER);
	if (ps_small_part1(data) == ORDER)
	{
		push(data->stack_b, data->stack_a, STACK_A);
		return (ORDER);
	}
	if (ps_small_part1(data) == ORDER)
	{
		push(data->stack_b, data->stack_a, STACK_A);
		push(data->stack_b, data->stack_a, STACK_A);
	}
	else
	{
		ps_order_4(data);
		data->stack_b->smaller = ps_smaller(data->stack_b);
		data->stack_b->bigger = ps_bigger(data->stack_b);
		ps_order_3_reverse(data->stack_b, STACK_B);
		ps_small_part2(data);
		ps_small_part2(data);
		if (ps_small_part2(data) == ORDER)
			return (ORDER);
		else
			return (ps_order_7(data));
	}
	if (ps_check_order(data->stack_a->init) == ORDER)
		return (ORDER);
	else
		return (ps_order_7(data));
}

int	ps_order_8(t_push_swap *data)
{
	ps_one_mov(data);
	if (ps_small_part1(data) == ORDER)
		return (ORDER);
	if (ps_small_part1(data) == ORDER)
	{
		push(data->stack_b, data->stack_a, STACK_A);
		return (ORDER);
	}
	if (ps_small_part1(data) == ORDER)
	{
		push(data->stack_b, data->stack_a, STACK_A);
		push(data->stack_b, data->stack_a, STACK_A);
	}
	else
	{
		data->stack_b->smaller = ps_smaller(data->stack_b);
		data->stack_b->bigger = ps_bigger(data->stack_b);
		ps_order_3_reverse(data->stack_b, STACK_B);
		if (ps_small_part1(data) == ORDER)
		{
			push(data->stack_b, data->stack_a, STACK_A);
			push(data->stack_b, data->stack_a, STACK_A);
			push(data->stack_b, data->stack_a, STACK_A);
		}
		else
		{
			ps_order_4(data);
			data->stack_b->smaller = ps_smaller(data->stack_b);
			data->stack_b->bigger = ps_bigger(data->stack_b);
			ps_small_part2(data);
			ps_small_part2(data);
			ps_small_part2(data);
			if (ps_small_part2(data) == ORDER)
				return (ORDER);
			else
				return (ps_order_8(data));
		}
	}
	if (ps_check_order(data->stack_a->init) == ORDER)
		return (ORDER);
	else
		return (ps_order_8(data));
}

int	ps_order_9(t_push_swap *data)
{
	ps_one_mov(data);
	if (ps_small_part1(data) == ORDER)
		return (ORDER);
	ps_order_8(data);
	if (ps_small_part2(data) == ORDER)
		return (ORDER);
	else
		return (ps_order_9(data));
}

int	ps_order_10(t_push_swap *data)
{
	ps_one_mov(data);
	if (ps_small_part1(data) == ORDER)
		return (ORDER);
	ps_order_9(data);
	if (ps_small_part2(data) == ORDER)
		return (ORDER);
	else
		return (ps_order_10(data));
}
