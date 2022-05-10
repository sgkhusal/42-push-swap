/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_ps_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:37:21 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/09 19:44:22 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_fill_stack_a(t_stack *stack, int stack_size, char *numbers[])
{
	int			i;
	int			ret;
	long int	nb;

	i = 0;
	while (i < stack_size)
	{
		if (ft_strlen(numbers[i]) > 11)
			ps_error(stack);
		if (ps_check_char(numbers[i]) == E_NOT_INT)
			ps_error(stack);
		nb = ft_atol(numbers[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			ps_error(stack);
		ret = ps_add_elem(stack, nb);
		if (ret == E_MALLOC)
			ps_error(stack);
		i++;
	}
	ps_check_repeated_nb(stack);
	ps_check_input_order(stack);
}

t_stack	*ps_init_stack_a(int stack_size, char *numbers[])
{
	t_stack		*stack;

	stack = init_stack();
	stack->size = stack_size;
	if (stack == NULL)
		ps_error(NULL);
	ps_fill_stack_a(stack, stack_size, numbers);
	if (stack_size == 1)
	{
		clean_stack(stack);
		exit(EXIT_SUCCESS);
	}
	stack->max = stack_max(stack);
	stack->min = stack_min(stack);
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
	stack->size = 0;
	stack->min = 0;
	stack->max = 0;
	return (stack);
}
