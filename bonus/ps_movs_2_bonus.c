/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_movs_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:50:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/03 11:35:09 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rotate(t_stack *stack)
{
	stack->top->prev = stack->bottom;
	stack->bottom->next = stack->top;
	stack->bottom = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	stack->bottom->next = NULL;
}

void	double_rotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate(t_stack *stack)
{
	stack->top->prev = stack->bottom;
	stack->bottom->next = stack->top;
	stack->top = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->top->prev = NULL;
	stack->bottom->next = NULL;
}

void	double_reverse_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
