/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:26:22 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/08 22:41:53 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	clean_list(t_list *list)
{
	t_list	*aux;
	t_list	*tmp;

	if (!list)
		return ;
	aux = list;
	while (aux)
	{
		free(aux->content);
		tmp = aux->next;
		free(aux);
		aux = tmp;
	}
}

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
	clean_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	ps_error_movs(t_stack *a, t_stack *b, t_list *movs)
{
	clean_stack(a);
	clean_stack(b);
	clean_list(movs);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
