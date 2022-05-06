/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_checker_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:26:02 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/06 01:45:14 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	a = ps_init_stack_a(argc - 1, &argv[1]);
	b = init_stack();
	ps_read_exec_movs(a, b);
	if (ps_check_order(a->top) == ORDER && b->size == 0)
	{
		ft_printf("\033[38;5;83m");
		ft_printf("OK\n");
		ft_printf("\033[0m");
	}
	else
	{
		ft_printf("\033[38;5;196m");
		ft_printf("KO\n");
		ft_printf("\033[0m");
	}
	clean_stack(a);
	clean_stack(b);
	return (0);
}
