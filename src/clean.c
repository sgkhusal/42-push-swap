/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:26:22 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/06 01:44:48 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	ft_dlstdel(stack->top);
	stack->top = NULL;
	stack->bottom = NULL;
	free(stack);
	stack = NULL;
}

void	ps_error(t_stack *stack)
{
	if (stack != NULL)
		clean_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
