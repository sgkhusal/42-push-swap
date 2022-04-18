/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_small_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:33:41 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/18 22:21:15 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_small_swap2(t_push_swap *data)
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
}

void	ps_small_swap(t_push_swap *data)
{
	if (data->stack_a->init->nb != data->stack_a->bigger)
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
	}
	else if (data->stack_b->size > 1)
	{
		if (data->stack_b->init->next->nb > data->stack_b->init->nb)
			swap(data->stack_b->init, STACK_B);
	}
}

int	ps_small_part1(t_push_swap *data)
{
	if (data->stack_a->end->nb == data->stack_a->smaller)
		reverse_rotate(data->stack_a, STACK_A);
	if (data->stack_a->init->nb != data->stack_a->bigger)
	{
		if (data->stack_a->init->next->nb < data->stack_a->init->nb)
			swap(data->stack_a->init, STACK_A);
		else if (data->stack_a->init->next->nb == data->stack_a->bigger)
			swap(data->stack_a->init, STACK_A);
	}
	if (ps_check_order(data->stack_a->init) == ORDER)
		return (ORDER);
	push(data->stack_a, data->stack_b, STACK_B);
	data->stack_b->size++;
	data->stack_a->smaller = ps_smaller(data->stack_a);
	data->stack_a->bigger = ps_bigger(data->stack_a);
	if (data->stack_b->size > 1)
	{
		data->stack_b->smaller = ps_smaller(data->stack_b);
		if (data->stack_b->init->nb == data->stack_b->smaller)
		{
			if (data->stack_b->init->nb < data->stack_a->bigger)
				rotate(data->stack_b, STACK_B);
		}
	}
	return (NOT_ORDER);
}

int	ps_small_part2(t_push_swap *data)
{
	//ps_small_swap2(data);
	push(data->stack_b, data->stack_a, STACK_A);
	data->stack_b->size--;
	data->stack_a->smaller = ps_smaller(data->stack_a);
	data->stack_a->bigger = ps_bigger(data->stack_a);
	if (data->stack_a->init->nb == data->stack_a->smaller)
		return (ORDER);
	if (data->stack_a->init->nb == data->stack_a->bigger)
		rotate(data->stack_a, STACK_A);
	if (data->stack_a->init->next->nb < data->stack_a->init->nb)
		swap(data->stack_a->init, STACK_A);
	if (ps_check_order(data->stack_a->init) == ORDER)
		return (ORDER);
	else
		return (NOT_ORDER);
}

int	ps_one_mov(t_push_swap *data)
{
	if (data->stack_a->init->nb == data->stack_a->bigger)
	{
		if (ps_check_order(data->stack_a->init->next) == ORDER)
		{
			rotate(data->stack_a, STACK_A);
			return (ORDER);
		}
	}
	return (NOT_ORDER);
}
