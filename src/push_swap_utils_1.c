/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:50:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/13 21:31:24 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_dlist *src, t_dlist *dst)
{
	dst->prev = src;
	src = src->next;
	src->prev = NULL;
	dst->prev->next = dst;
	dst = dst->prev;
}

void	swap(t_dlist **lst)
{
	(*lst)->prev = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	(*lst)->next->prev = *lst;
	(*lst)->prev->next = *lst;
	*lst = (*lst)->prev;
	(*lst)->prev = NULL;
}

/* void	rotate(t_stack *stack)
{
	
}

void	reverse_rotate(t_stack *stack)
{
	
} */