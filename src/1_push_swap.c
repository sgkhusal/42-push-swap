/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:46:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/25 15:39:56 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "test.h" ///////////////////////////

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		swap(a->top, STACK_A);
	else if (a->size == 3)
		ps_order_3(a, STACK_A);
	else if (a->size <= 11)
		ps_small(a, b);
	else
		ps_big(a, b);
}

int	main(int argc, char *argv[])
{
	t_push_swap	data;

	if (argc == 1)
		return (0);
	data.stack_a = ps_init_stack_a(argc - 1, &argv[1]);
	data.stack_b = init_stack();
	if (data.stack_b == NULL)
		ps_error(data.stack_a);
	//print_stack(data.stack_a);
	push_swap(data.stack_a, data.stack_b);
	//ft_printf("Final stack:\n");
	//print_stack(data.stack_a);
	//print_reverse_stack(data.stack_a);
	/* if (ps_check_order(data.stack_a->top) == ORDER)
	{
		ft_printf("\033[38;5;83m");
		ft_printf("OK\n");
		ft_printf("\033[0m");
	}
	else
	{
		ft_printf("\033[38;5;196m");
		ft_printf("NOT OK\n");
		ft_printf("\033[0m");
	} */
	clean_stack(data.stack_a);
	clean_stack(data.stack_b);
	return (0);
}
