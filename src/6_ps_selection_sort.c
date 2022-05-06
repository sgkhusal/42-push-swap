/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_ps_selection_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:17:39 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/06 01:43:26 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	dlist_min_pos(t_stack *s)
{
	t_dlist	*aux;
	int		pos;

	aux = s->top;
	pos = 1;
	while (aux->nb != s->min)
	{
		aux = aux->next;
		pos++;
	}
	return (pos);
}

static int	dlist_max_pos(t_stack *s)
{
	t_dlist	*aux;
	int		pos;

	aux = s->top;
	pos = 1;
	while (aux && aux->nb != s->max)
	{
		aux = aux->next;
		pos++;
	}
	return (pos);
}

static void	ps_selection_sort_a(t_stack *a, t_stack *b, int b_init_size)
{
	int	pos;

	while (a->size > 3 && ps_check_order(a->top) != ORDER)
	{
		pos = dlist_min_pos(a);
		while (a->top->nb != a->min)
		{
			if (pos > a->size / 2)
				reverse_rotate(a, STACK_A);
			else
				rotate(a, STACK_A);
		}
		push(a, b, STACK_B);
	}
	if (a->size == 3)
		ps_order_3(a);
	while (b->size > b_init_size)
		push(b, a, STACK_A);
}

static void	ps_selection_sort_b(t_stack *a, t_stack *b, int section_size)
{
	int	pos;
	int	final_a_size;

	final_a_size = a->size + section_size;
	while (a->size < final_a_size)
	{
		pos = dlist_max_pos(b);
		while (b->top->nb != b->max)
		{
			if (pos > b->size / 2)
				reverse_rotate(b, STACK_B);
			else
				rotate(b, STACK_B);
		}
		push(b, a, STACK_A);
	}
}

void	ps_selection_sort(t_stack *a, t_stack *b, t_quick_sort qs)
{
	if (ps_check_order(a->top) != ORDER)
		ps_selection_sort_a(a, b, b->size);
	if (b->size > 0)
		ps_selection_sort_b(a, b, qs.b_size);
}
