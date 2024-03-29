/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:11:48 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/15 01:54:23 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "push_swap.h"

void	tests(t_push_swap	*data);
void	test_swap(t_stack *stack);
void	test_rotate(t_stack *stack);
void	test_reverse_rotate(t_stack *stack);
void	test_push(t_stack *src, t_stack *dst, char s);

void	print_stack(t_stack *stack);
void	print_reverse_stack(t_stack *stack);

#endif