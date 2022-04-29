/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:21:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/28 22:58:45 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	dlst_buble_sort(t_dlist *lst)
{
	t_dlist	*aux1;
	t_dlist	*aux2;

	aux1 = lst;
	while(aux1)
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

t_dlist	*dlstdup(t_dlist *lst)
{
	t_dlist	*aux1;
	t_dlist	*aux2;
	t_dlist	*init;
	t_dlist	*end;

	init = ft_dlstnew(lst->nb);
	if (!init)
		return (NULL);
	end = init;
	aux1 = lst->next;
	while (aux1)
	{
		aux2 = ft_dlstnew(aux1->nb);
		if (!aux2)
		{
			ft_dlstdel(init);
			return (NULL);
		}
		ft_dlstadd_back(&end, aux2);
		aux1 = aux1->next;
	}
	return (init);
}

double	ps_median(t_push_swap *ps)
{
	int		i;
	t_dlist	*aux;

	i = 0;
	dlst_buble_sort(ps->order->top);
	aux = ps->order->top;
	if (ps->order->size % 2 == 1)
	{
		while (++i <= ps->order->size / 2)
			aux = aux->next;
		return (aux->nb);
	}
	else
	{
		while (++i <= (ps->order->size - 1) / 2)
			aux = aux->next;
		return (((double) (aux->nb + aux->next->nb)) / 2);
	}
}
