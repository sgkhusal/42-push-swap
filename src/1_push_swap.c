/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:46:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/08 21:52:13 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack *a, t_stack *b, t_push_swap *data)
{
	if (a->size == 2)
		swap(a->top, STACK_A);
	else if (a->size == 3)
		ps_order_3(a);
	else if (a->size < 10)
		ps_small(a, b);
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
	clean_stack(data.stack_a);
	clean_stack(data.stack_b);
	clean_stack(data.order);
	return (0);
}
