/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_movs_1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:50:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/03 11:37:08 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap(t_dlist *lst)
{
	ft_swap(&lst->nb, &lst->next->nb);
}

void	double_swap(t_dlist *lst_a, t_dlist *lst_b)
{
	swap(lst_a);
	swap(lst_b);
}

static void	normal_push(t_stack *src, t_stack *dst)
{
	dst->top->prev = src->top;
	src->top = src->top->next;
	dst->top->prev->next = dst->top;
	dst->top = dst->top->prev;
	dst->top->prev = NULL;
	src->top->prev = NULL;
}

void	push(t_stack *src, t_stack *dst)
{
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
}
