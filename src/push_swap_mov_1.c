/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mov_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:50:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/17 02:38:03 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_dlist *lst, char s)
{
	ft_swap(&lst->nb, &lst->next->nb);
	if (s == STACK_A)
		ft_putstr_fd("sa\n", 1);
	else if (s == STACK_B)
		ft_putstr_fd("sb\n", 1);
}

void	double_swap(t_dlist *lst_a, t_dlist *lst_b)
{
	ft_swap(&lst_a->nb, &lst_a->next->nb);
	ft_swap(&lst_b->nb, &lst_b->next->nb);
	ft_putstr_fd("ss\n", 1);
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
