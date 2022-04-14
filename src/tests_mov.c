/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_mov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:05:08 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/14 22:07:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_swap(t_stack *stack)
{
	ft_printf("\nTesting swap:\n");
	ft_printf("Initial stack:\n");
	print_stack(stack);
	swap(&stack->init);
	ft_printf("Final stack:\n");
	print_stack(stack);
	print_reverse_stack(stack);
}

void	test_rotate(t_stack *stack)
{
	ft_printf("\nTesting rotate:\n");
	ft_printf("Initial stack:\n");
	print_stack(stack);
	rotate(stack);
	ft_printf("Final stack:\n");
	print_stack(stack);
	print_reverse_stack(stack);
}

void	test_reverse_rotate(t_stack *stack)
{
	ft_printf("\nTesting reverse rotate:\n");
	ft_printf("Initial stack:\n");
	print_stack(stack);
	reverse_rotate(stack);
	ft_printf("Final stack:\n");
	print_stack(stack);
	print_reverse_stack(stack);
}

void	test_push(t_stack *src, t_stack *dst)
{
	ft_printf("\nTesting push:\n");
	ft_printf("Initial stack:\n");
	print_stack(src);
	ft_printf("Destiny stack:\n");
	print_stack(dst);
	push(src, dst);
	ft_printf("Results:\n");
	ft_printf("Initial stack:\n");
	print_stack(src);
	print_reverse_stack(src);
	ft_printf("Destiny stack:\n");
	print_stack(dst);
	print_reverse_stack(dst);
}
