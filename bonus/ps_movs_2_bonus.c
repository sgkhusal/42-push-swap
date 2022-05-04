/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_movs_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:50:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/04 17:01:27 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rotate(t_stack *stack)
{
	t_dlist	*tmp;

	tmp = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	ft_dlstadd_back(&stack->bottom, tmp);
}

void	double_rotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate(t_stack *stack)
{
	t_dlist	*tmp;

	tmp = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->bottom->next = NULL;
}

void	double_reverse_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
