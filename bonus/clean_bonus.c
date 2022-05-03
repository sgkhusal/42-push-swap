/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:26:22 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/03 11:51:19 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	ps_error_movs(t_stack *a, t_stack *b)
{
	if (a != NULL)
		clean_stack(a);
	if (b != NULL)
		clean_stack(b);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
