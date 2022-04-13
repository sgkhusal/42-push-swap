/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:26:22 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/13 19:31:43 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	ft_dlstdel(stack->init);
	stack->init = NULL;
	stack->end = NULL;
	free(stack);
	stack = NULL;
}