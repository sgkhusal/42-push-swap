/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:46:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/01 15:37:22 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack *a, t_stack *b, t_push_swap *data)
{
	if (a->size == 2)
		swap(a->top, STACK_A);
	else if (a->size == 3)
		ps_order_3(a, STACK_A);
	else if (a->size <= 9)
		ps_small(a, b);
	else if (a->size <= 12)
		ps_selection_sort(a, b, b->size);
	else
		ps_big(a, b, data);
}

int	main(int argc, char *argv[])
{
	t_push_swap	data;

	if (argc == 1)
		return (0);
	data.stack_a = ps_init_stack_a(argc - 1, &argv[1]);
	data.stack_b = init_stack();
	data.order = NULL;
	if (data.stack_b == NULL)
		ps_error(data.stack_a);
	push_swap(data.stack_a, data.stack_b, &data);
	/* if (ps_check_order(data.stack_a->top) == ORDER && data.stack_b->size == 0)
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
	clean_stack(data.order);
	return (0);
}
