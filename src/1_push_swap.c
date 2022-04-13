/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:46:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/13 19:49:37 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_push_swap	data;
	t_dlist		*tmp;

	if (argc == 1)
		return (0);
	data.stack_size = argc - 1;
	data.stack_a = ps_init_stack_a(data.stack_size, &argv[1]);
	tmp = data.stack_a->init;
	ft_printf("From double linked list:\n");
	while (tmp != NULL)
	{
		ft_printf("%i ", tmp->nb);
		tmp = tmp->next;
	}
	ft_printf("\n");
	tmp = data.stack_a->end;
	while (tmp != NULL)
	{
		ft_printf("%i ", tmp->nb);
		tmp = tmp->prev;
	}
	ft_printf("\n");
	clean_stack(data.stack_a);
	return (0);
}
