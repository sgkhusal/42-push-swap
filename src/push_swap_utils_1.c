/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:50:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/14 21:54:20 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_dlist **lst)
{
	(*lst)->prev = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	(*lst)->next->prev = *lst;
	(*lst)->prev->next = *lst;
	*lst = (*lst)->prev;
	(*lst)->prev = NULL;
}

void	rotate(t_stack *stack)
{
	stack->init->prev = stack->end;
	stack->end->next = stack->init;
	stack->end = stack->init;
	stack->init = stack->init->next;
	stack->init->prev = NULL;
	stack->end->next = NULL;
}

void	reverse_rotate(t_stack *stack)
{
	stack->init->prev = stack->end;
	stack->end->next = stack->init;
	stack->init = stack->end;
	stack->end = stack->end->prev;
	stack->init->prev = NULL;
	stack->end->next = NULL;
}

void	normal_push(t_stack *src, t_stack *dst)
{
	dst->init->prev = src->init;
	src->init = src->init->next;
	dst->init->prev->next = dst->init;
	dst->init = dst->init->prev;
	dst->init->prev = NULL;
	src->init->prev = NULL;
}

void	push(t_stack *src, t_stack *dst)
{
	if (dst->init == NULL)
	{
		dst->init = src->init;
		dst->end = dst->init;
		src->init = src->init->next;
		dst->init->next = NULL;
		dst->init->prev = NULL;
		src->init->prev = NULL;
	}
	else if (src->init == src->end)
	{
		dst->init->prev = src->init;
		src->init->next = dst->init;
		dst->init = src->init;
		src->init = NULL;
		src->end = NULL;
	}
	else
		normal_push(src, dst);
}
