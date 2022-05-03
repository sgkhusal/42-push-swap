/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:21:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/03 09:48:20 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	stack_max(t_stack *stack)
{
	t_dlist	*aux;
	int		big;

	if (stack->size == 0)
		return (0);
	else if (stack->size == 1)
		return (stack->top->nb);
	big = stack->top->nb;
	aux = stack->top->next;
	while (aux)
	{
		if (aux->nb > big)
			big = aux->nb;
		aux = aux->next;
	}
	return (big);
}

int	stack_min(t_stack *stack)
{
	t_dlist	*aux;
	int		small;

	if (stack->size == 0)
		return (0);
	else if (stack->size == 1)
		return (stack->top->nb);
	small = stack->top->nb;
	aux = stack->top->next;
	while (aux)
	{
		if (aux->nb < small)
			small = aux->nb;
		aux = aux->next;
	}
	return (small);
}

int	ps_check_order(t_dlist *lst)
{
	t_dlist	*aux1;
	t_dlist	*aux2;

	aux1 = lst;
	aux2 = aux1->next;
	while (aux2)
	{
		if (aux1->nb > aux2->nb)
			return (NOT_ORDER);
		aux1 = aux2;
		aux2 = aux2->next;
	}
	return (ORDER);
}

int	ps_check_reverse_order(t_dlist *lst)
{
	t_dlist	*aux1;
	t_dlist	*aux2;

	aux1 = lst;
	aux2 = aux1->next;
	while (aux2)
	{
		if (aux1->nb < aux2->nb)
			return (NOT_ORDER);
		aux1 = aux2;
		aux2 = aux2->next;
	}
	return (ORDER);
}
