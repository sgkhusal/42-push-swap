/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_movs_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:50:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/08 21:24:24 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_push(char s)
{
	if (s == STACK_A)
		ft_putstr_fd("pa\n", 1);
	else if (s == STACK_B)
		ft_putstr_fd("pb\n", 1);
}

static void	update_stack_data(t_stack *src, t_stack *dst)
{
	dst->size++;
	src->size--;
	src->min = stack_min(src);
	src->max = stack_max(src);
	dst->min = stack_min(dst);
	dst->max = stack_max(dst);
}

static void	normal_push(t_stack *src, t_stack *dst)
{
	t_dlist	*tmp;

	tmp = src->top;
	src->top = src->top->next;
	src->top->prev = NULL;
	ft_dlstadd_front(&dst->top, tmp);
}

void	push(t_stack *src, t_stack *dst, char s)
{
	if (src->size < 1)
		return ;
	if (dst->top == NULL)
	{
		dst->top = src->top;
		dst->bottom = dst->top;
		src->top = src->top->next;
		dst->top->next = NULL;
		dst->top->prev = NULL;
		src->top->prev = NULL;
	}
	else if (src->top == src->bottom)
	{
		dst->top->prev = src->top;
		src->top->next = dst->top;
		dst->top = src->top;
		src->top = NULL;
		src->bottom = NULL;
	}
	else
		normal_push(src, dst);
	print_push(s);
	update_stack_data(src, dst);
}

void	swap(t_dlist *lst, char s)
{
	if (!lst || !lst->next)
		return ;
	ft_swap(&lst->nb, &lst->next->nb);
	if (s == STACK_A)
		ft_putstr_fd("sa\n", 1);
	else if (s == STACK_B)
		ft_putstr_fd("sb\n", 1);
}
