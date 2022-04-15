/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:21:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/15 02:21:47 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
