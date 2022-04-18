/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:46:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/18 04:48:52 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "test.h" ///////////////////////////

void	push_swap(t_push_swap *data)
{
	if (data->stack_a->size == 2)
		swap(data->stack_a->init, STACK_A);
	else if (data->stack_a->size == 3)
		ps_order_3(data->stack_a, STACK_A);
	else if (data->stack_a->size == 4)
		ps_order_4(data);
	else if (data->stack_a->size == 5)
		ps_order_5(data);
	else if (data->stack_a->size == 6)
		ps_order_6(data);
	else if (data->stack_a->size == 7)
		ps_order_7(data);
	else if (data->stack_a->size == 8)
		ps_order_8(data);
	else if (data->stack_a->size == 9)
		ps_order_9(data);
	else if (data->stack_a->size == 10)
		ps_order_10(data);
}

int	main(int argc, char *argv[])
{
	t_push_swap	data;

	if (argc == 1)
		return (0);
	data.stack_a = ps_init_stack_a(argc - 1, &argv[1]);
	data.stack_b = init_stack();
	data.stack_b->size = 0;
	if (data.stack_b == NULL)
		ps_error(data.stack_a);
	//print_stack(data.stack_a);
	if (data.stack_a->size > 2)
	{
		data.stack_a->bigger = ps_bigger(data.stack_a);
		data.stack_a->smaller = ps_smaller(data.stack_a);
	}
	push_swap(&data);
	//ft_printf("Final stack:\n");
	//print_stack(data.stack_a);
	//print_reverse_stack(data.stack_a);
	/* if (ps_check_order(data.stack_a->init) == ORDER)
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
