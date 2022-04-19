/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_small_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 01:59:00 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/19 02:52:06 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_order_6(t_stack *a, t_stack *b)
{
	ps_bigger_first(a);
	if (ps_small_part1(a, b) == ORDER)
		return (ORDER);
	if (ps_small_part1(a, b) == ORDER)
	{
		push(b, a, STACK_A);
		if (ps_check_order(a->init) == ORDER)
			return (ORDER);
		else
			return (ps_order_6(a, b)); // acho que pode entrar em loop
	}
	if (ps_small_part1(a, b) == ORDER) // problemas aqui
	{
		push(b, a, STACK_A);
		push(b, a, STACK_A);
	}
	else
	{
		ps_order_3(a, STACK_A);
		b->smaller = ps_smaller(b);
		b->bigger = ps_bigger(b);
		ps_order_3_reverse(b, STACK_B);
		ps_small_part2(a, b);
		ps_small_part2(a, b);
		if (ps_small_part2(a, b) == ORDER) // será que tem problemas??
			return (ORDER);
		else
			return (ps_order_6(a, b));
	}
	if (ps_check_order(a->init) == ORDER)
		return (ORDER);
	else
		return (ps_order_6(a, b));
}

int	ps_order_7(t_stack *a, t_stack *b)
{
	ps_bigger_first(a);
	if (ps_small_part1(a, b) == ORDER)
		return (ORDER);
	if (ps_small_part1(a, b) == ORDER)
	{
		push(b, a, STACK_A);
		return (ORDER);
	}
	if (ps_small_part1(a, b) == ORDER)
	{
		push(b, a, STACK_A);
		push(b, a, STACK_A);
	}
	else
	{
		ps_order_4(a, b);
		b->smaller = ps_smaller(b);
		b->bigger = ps_bigger(b);
		ps_order_3_reverse(b, STACK_B);
		ps_small_part2(a, b);
		ps_small_part2(a, b);
		if (ps_small_part2(a, b) == ORDER)
			return (ORDER);
		else
			return (ps_order_7(a, b));
	}
	if (ps_check_order(a->init) == ORDER)
		return (ORDER);
	else
		return (ps_order_7(a, b));
}

int	ps_order_8(t_stack *a, t_stack *b)
{
	ps_bigger_first(a);
	if (ps_small_part1(a, b) == ORDER)
		return (ORDER);
	if (ps_small_part1(a, b) == ORDER)
	{
		push(b, a, STACK_A);
		return (ORDER);
	}
	if (ps_small_part1(a, b) == ORDER)
	{
		push(b, a, STACK_A);
		push(b, a, STACK_A);
	}
	else
	{
		b->smaller = ps_smaller(b);
		b->bigger = ps_bigger(b);
		ps_order_3_reverse(b, STACK_B);
		if (ps_small_part1(a, b) == ORDER)
		{
			push(b, a, STACK_A);
			push(b, a, STACK_A);
			push(b, a, STACK_A);
		}
		else
		{
			ps_order_4(a, b);
			b->smaller = ps_smaller(b);
			b->bigger = ps_bigger(b);
			ps_small_part2(a, b);
			ps_small_part2(a, b);
			ps_small_part2(a, b);
			if (ps_small_part2(a, b) == ORDER)
				return (ORDER);
			else
				return (ps_order_8(a, b));
		}
	}
	if (ps_check_order(a->init) == ORDER)
		return (ORDER);
	else
		return (ps_order_8(a, b));
}

int	ps_order_9(t_stack *a, t_stack *b)
{
	ps_bigger_first(a);
	if (ps_small_part1(a, b) == ORDER)
		return (ORDER);
	ps_order_8(a, b);
	if (ps_small_part2(a, b) == ORDER)
		return (ORDER);
	else
		return (ps_order_9(a, b));
}

int	ps_order_10(t_stack *a, t_stack *b)
{
	ps_bigger_first(a);
	if (ps_small_part1(a, b) == ORDER)
		return (ORDER);
	ps_order_9(a, b);
	if (ps_small_part2(a, b) == ORDER)
		return (ORDER);
	else
		return (ps_order_10(a, b));
}
