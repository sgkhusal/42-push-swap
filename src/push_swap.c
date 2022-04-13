/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:46:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/13 19:32:39 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_error(t_stack *stack)
{
	if (stack != NULL)
		clean_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	ps_check_order(t_stack *stack)
{
	t_dlist	*aux1;
	t_dlist	*aux2;

	aux1 = stack->init;
	aux2 = aux1->next;
	while (aux2 != NULL)
	{
		if (aux1->nb > aux2->nb)
			return ;
		aux1 = aux2;
		aux2 = aux2->next;
	}
	clean_stack(stack);
	exit(EXIT_SUCCESS);
}

void	ps_check_repeated_nb(t_stack *stack)
{
	t_dlist	*aux1;
	t_dlist	*aux2;

	aux1 = stack->init;
	while (aux1 != NULL)
	{
		aux2 = aux1->next;
		while (aux2 != NULL)
		{
			if (aux1->nb == aux2->nb)
				ps_error(stack);
			aux2 = aux2->next;
		}
		aux1 = aux1->next;
	}
}

int	ps_check_char(char *nb)
{
	int	j;
	int	nb_size;

	j = 0;
	nb_size = ft_strlen(nb);
	while (j < nb_size)
	{
		if (!ft_isdigit(nb[j]))
		{
			if (nb[j] != '-' && nb[j] != '+')
				return (E_NOT_INT);
			if ((nb[j] == '-' || nb[j] == '+') && nb_size == 1)
				return (E_NOT_INT);
			if ((nb[j] == '-' || nb[j] == '+') && j > 1)
				return (E_NOT_INT);
		}
		j++;
	}
	return (OK);
}

void	ps_fill_stack_a(t_stack *stack, int stack_size, char *numbers[])
{
	int	i;
	long int	nb;
	t_dlist	*aux;
	t_dlist	*tmp;

	i = 1;
	aux = stack->init;
	while (i < stack_size)
	{
		if (ps_check_char(numbers[i]) == E_NOT_INT)
			ps_error(stack);
		nb = ft_atol(numbers[i]);
		if (nb > 2147483647 || nb < -2147483648)
			ps_error(stack);
		tmp = ft_dlstnew((int) nb);
		if (tmp == NULL)
			ps_error(stack);
		tmp->prev = aux;
		aux->next = tmp;
		aux = tmp;
		i++;
	}
	stack->end = aux;
	ps_check_repeated_nb(stack);
	ps_check_order(stack);
}

t_stack	*ps_init_stack_a(int stack_size, char *numbers[])
{
	t_stack		*stack;
	long int	nb;
	
	if (ps_check_char(numbers[0]) == E_NOT_INT)
		ps_error(NULL);
	if (stack_size == 1)
		exit(EXIT_SUCCESS);
	else
	{
		stack = (t_stack *)malloc(sizeof(t_stack));
		if (stack == NULL)
			ps_error(NULL);
		nb = ft_atol(numbers[0]);
		if (nb > 2147483647 || nb < -2147483648)
			ps_error(stack);
		stack->init = ft_dlstnew((int) nb);
		if (stack->init == NULL)
			ps_error(stack);
		stack->end = NULL;
		ps_fill_stack_a(stack, stack_size, numbers);
	}
	return (stack);
}

int	main(int argc, char *argv[])
{
	t_push_swap	data;
	t_dlist	*tmp;
	
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
