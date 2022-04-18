/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:05:08 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/17 18:35:37 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	print_stack(t_stack *stack)
{
	t_dlist	*tmp;

	tmp = stack->init;
	while (tmp != NULL)
	{
		ft_printf("%i ", tmp->nb);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	print_reverse_stack(t_stack *stack)
{
	t_dlist	*tmp;

	tmp = stack->end;
	while (tmp != NULL)
	{
		ft_printf("%i ", tmp->nb);
		tmp = tmp->prev;
	}
	ft_printf("\n");
}

void	tests(t_push_swap	*data)
{
	ft_printf("Initial stack a:\n");
	print_stack(data->stack_a);
	print_reverse_stack(data->stack_a);
}

	/* test_swap(data->stack_a);
	test_rotate(data->stack_a);
	test_reverse_rotate(data->stack_a);
	test_push(data->stack_a, data->stack_b, STACK_B);
	test_push(data->stack_a, data->stack_b, STACK_B);
	test_push(data->stack_b, data->stack_a, STACK_A);
	test_push(data->stack_b, data->stack_a, STACK_A); */
