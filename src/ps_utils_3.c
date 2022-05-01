/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:21:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/01 17:37:05 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	dlst_sort(t_dlist *lst)
{
	t_dlist	*aux1;
	t_dlist	*aux2;

	aux1 = lst;
	while (aux1)
	{
		aux2 = aux1->next;
		while (aux2)
		{
			if (aux1->nb > aux2->nb)
				ft_swap(&aux1->nb, &aux2->nb);
			aux2 = aux2->next;
		}
		aux1 = aux1->next;
	}
}

t_dlist	*dlstdup(t_dlist *lst, int size)
{
	t_dlist	*aux1;
	t_dlist	*aux2;
	t_stack	s;
	int		i;

	s.top = ft_dlstnew(lst->nb);
	if (!s.top)
		return (NULL);
	s.bottom = s.top;
	aux1 = lst->next;
	i = 1;
	while (aux1 && i <= size)
	{
		aux2 = ft_dlstnew(aux1->nb);
		if (!aux2)
		{
			ft_dlstdel(s.top);
			return (NULL);
		}
		ft_dlstadd_back(&s.bottom, aux2);
		aux1 = aux1->next;
		i++;
	}
	return (s.top);
}

t_dlist	*dlstdup_small(t_dlist *lst, int size, int sub_size)
{
	t_dlist	*aux1;
	t_dlist	*aux2;

	aux1 = dlstdup(lst, size);
	dlst_sort(aux1);
	aux2 = dlstdup(lst, sub_size);
	// limpar aux1
	return (aux2);
}

double	ps_median(t_push_swap *ps)
{
	int		i;
	t_dlist	*aux;

	i = 0;
	dlst_sort(ps->order->top);
	aux = ps->order->top;
	if (ps->order->size % 2 == ODD)
	{
		while (++i <= ps->order->size / 2)
			aux = aux->next;
		return (aux->nb);
	}
	else
	{
		while (++i <= (ps->order->size - 1) / 2)
			aux = aux->next;
		return (((double)(aux->nb + aux->next->nb)) / 2);
	}
}

double	ps_second_median(t_push_swap *ps, char s)
{
	int		i;
	int		size;
	t_dlist	*aux;
	t_quick_sort	qs;

	i = 0;
	qs = ps_section_size(ps->order->size);
	aux = ps->order->top;
	if (s == STACK_B)
		size = qs.b_size;
	else
		size = qs.a_size;
	if (size % 2 == ODD)
	{
		while (++i <= size / 2)
			aux = aux->next;
		return (aux->nb);
	}
	else
	{
		while (++i <= (size - 1) / 2)
			aux = aux->next;
		return (((double)(aux->nb + aux->next->nb)) / 2);
	}
}
