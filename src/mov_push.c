/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:50:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/18 19:31:51 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	normal_push(t_stack *src, t_stack *dst)
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
