/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:46:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/17 19:08:16 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "test.h" ///////////////////////////

void	push_swap(t_push_swap *data)
{
	if (data->stack_size == 2)
		swap(data->stack_a->init, STACK_A);
	else if (data->stack_size == 3)
		ps_order_3(data);
	else if (data->stack_size == 4)
		ps_order_4(data);
	else
		ps_order_4(data);
}

int	main(int argc, char *argv[])
{
	t_push_swap	data;

	if (argc == 1)
		return (0);
	data.stack_size = argc - 1;
	data.stack_a = ps_init_stack_a(data.stack_size, &argv[1]);
	data.stack_b = init_stack();
	data.stack_b_size = 0;
	if (data.stack_b == NULL)
		ps_error(data.stack_a);
	print_stack(data.stack_a);
	if (data.stack_size > 2)
	{
		data.bigger = ps_bigger(data.stack_a);
		data.smaller = ps_smaller(data.stack_a);
	}
	push_swap(&data);
	//ft_printf("Final stack:\n");
	print_stack(data.stack_a);
	print_reverse_stack(data.stack_a);
	clean_stack(data.stack_a);
	clean_stack(data.stack_b);
	return (0);
}
