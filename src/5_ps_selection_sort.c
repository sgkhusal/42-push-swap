/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ps_selection_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:17:39 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/29 16:20:47 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	dlist_min_pos(t_stack *a)
{
	t_dlist	*aux;
	int		pos;

	aux = a->top;
	pos = 1;
	while (aux->nb != a->min)
	{
		aux = aux->next;
		pos++;
	}
	return (pos);
}

void	ps_selection_sort(t_stack *a, t_stack *b, int b_init_size)
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
		ps_order_3(a, STACK_A);
	while (b->size > b_init_size)
		push(b, a, STACK_A);
}

static int	dlist_section_nb_pos(t_stack *s, int nb, int section_size)
{
	t_dlist	*aux;
	int		pos;

	aux = s->top;
	pos = 1;
	while (pos < section_size)
	{
		if (aux->nb == nb)
			return (pos);
		aux = aux->next;
		pos++;
	}
	return (pos);
}

static int	dlist_section_max(t_stack *s, int section_size)
{
	t_dlist	*aux;
	int		max;
	int		i;

	aux = s->top;
	max = aux->nb;
	i = 1;
	while (i < section_size && aux->next)
	{
		if (max < aux->next->nb)
			max = aux->next->nb;
		aux = aux->next;
		i++;
	}
	return (max);
}

void	ps_selection_sort_section_b(t_stack *a, t_stack *b, int section_size)
{
	int	i;
	int	pos;
	int	max;
	int	final_a_size;

	final_a_size = a->size + section_size;
	while (a->size < final_a_size)
	{
		max = dlist_section_max(b, section_size);
		pos = dlist_section_nb_pos(b, max, section_size);
		while (b->top->nb != max)
			rotate(b, STACK_B);
		push(b, a, STACK_A);
		i = 0;
		while (++i < pos)
			reverse_rotate(b, STACK_B);
	}
}