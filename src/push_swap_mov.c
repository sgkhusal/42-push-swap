/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:50:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/15 01:46:53 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_dlist **lst, char s)
{
	(*lst)->prev = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	(*lst)->next->prev = *lst;
	(*lst)->prev->next = *lst;
	*lst = (*lst)->prev;
	(*lst)->prev = NULL;
	if (s == STACK_A)
		ft_putstr_fd("sa\n", 1);
	else if (s == STACK_B)
		ft_putstr_fd("sb\n", 1);
	else
		ft_putstr_fd("ss\n", 1);
}

void	rotate(t_stack *stack, char s)
{
	stack->init->prev = stack->end;
	stack->end->next = stack->init;
	stack->end = stack->init;
	stack->init = stack->init->next;
	stack->init->prev = NULL;
	stack->end->next = NULL;
	if (s == STACK_A)
		ft_putstr_fd("ra\n", 1);
	else if (s == STACK_B)
		ft_putstr_fd("rb\n", 1);
	else
		ft_putstr_fd("rr\n", 1);
}

void	reverse_rotate(t_stack *stack, char s)
{
	stack->init->prev = stack->end;
	stack->end->next = stack->init;
	stack->init = stack->end;
	stack->end = stack->end->prev;
	stack->init->prev = NULL;
	stack->end->next = NULL;
	if (s == STACK_A)
		ft_putstr_fd("rra\n", 1);
	else if (s == STACK_B)
		ft_putstr_fd("rrb\n", 1);
	else
		ft_putstr_fd("rrr\n", 1);
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

void	push(t_stack *src, t_stack *dst, char s)
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
	if (s == STACK_A)
		ft_putstr_fd("pa\n", 1);
	else if (s == STACK_B)
		ft_putstr_fd("pb\n", 1);
}
