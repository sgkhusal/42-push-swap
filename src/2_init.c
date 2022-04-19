/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_push_swap_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:37:21 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/15 18:14:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_fill_stack_a(t_stack *stack, int stack_size, char *numbers[])
{
	int			i;
	long int	nb;
	t_dlist		*aux;
	t_dlist		*tmp;

	i = 1;
	aux = stack->top;
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
	stack->bottom = aux;
	ps_check_repeated_nb(stack);
	ps_check_input_order(stack);
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
		stack = init_stack();
		stack->size = stack_size;
		if (stack == NULL)
			ps_error(NULL);
		nb = ft_atol(numbers[0]);
		if (nb > 2147483647 || nb < -2147483648)
			ps_error(stack);
		stack->top = ft_dlstnew((int) nb);
		if (stack->top == NULL)
			ps_error(stack);
		ps_fill_stack_a(stack, stack_size, numbers);
	}
	return (stack);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}
