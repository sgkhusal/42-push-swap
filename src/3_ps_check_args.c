/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ps_check_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:38:47 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/03 09:47:34 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_check_repeated_nb(t_stack *stack)
{
	t_dlist	*aux1;
	t_dlist	*aux2;

	aux1 = stack->top;
	while (aux1 != NULL)
	{
		aux2 = aux1->next;
		while (aux2 != NULL)
		{
			if (aux1->nb == aux2->nb)
				ps_error(stack);
			aux2 = aux2->next;
		}
		aux1 = aux1->next;
	}
}

int	ps_check_char(char *nb)
{
	int	j;
	int	nb_size;

	j = 0;
	nb_size = ft_strlen(nb);
	while (j < nb_size)
	{
		if (!ft_isdigit(nb[j]))
		{
			if (nb[j] != '-' && nb[j] != '+')
				return (E_NOT_INT);
			if ((nb[j] == '-' || nb[j] == '+') && nb_size == 1)
				return (E_NOT_INT);
			if ((nb[j] == '-' || nb[j] == '+') && j > 1)
				return (E_NOT_INT);
		}
		j++;
	}
	return (OK);
}

void	ps_check_input_order(t_stack *stack)
{
	if (ps_check_order(stack->top) == ORDER)
	{
		clean_stack(stack);
		exit(EXIT_SUCCESS);
	}
}
