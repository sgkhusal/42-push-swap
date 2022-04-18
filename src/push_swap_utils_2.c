/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:21:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/15 18:15:26 by sguilher         ###   ########.fr       */
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

int	ps_bigger(t_stack *stack)
{
	t_dlist	*aux;
	int		big;

	big = stack->init->nb;
	aux = stack->init->next;
	while (aux)
	{
		if (aux->nb > big)
			big = aux->nb;
		aux = aux->next;
	}
	return (big);
}

int	ps_smaller(t_stack *stack)
{
	t_dlist	*aux;
	int		small;

	small = stack->init->nb;
	aux = stack->init->next;
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
