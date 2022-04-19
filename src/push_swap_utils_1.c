/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:50:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/13 19:52:26 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstadd_front(t_dlist **lst_init, t_dlist *new)
{
	if (lst_init && new)
	{
		new->next = *lst_init;
		new->prev = NULL;
		*lst_init = new;
	}
}

void	ft_dlstadd_back(t_dlist **lst_end, t_dlist *new)
{
	if (lst_end && new)
	{
		(*lst_end)->next = new;
		new->next = NULL;
		new->prev = *lst_end;
		*lst_end = new;
	}
}

t_dlist	*ft_dlstnew(int nb)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_dlstdel(t_dlist *dlist)
{
	t_dlist	*aux;

	if (dlist == NULL)
		return ;
	while (dlist)
	{
		aux = dlist->next;
		dlist->next = NULL;
		dlist->prev = NULL;
		free(dlist);
		dlist = aux;
	}
}

int	ps_add_elem(t_stack *stack, char *nbr, int idx)
{
	t_dlist	*new;

	new = ft_dlstnew(ft_atoi(nbr));
	if (new == NULL)
		return (E_MALLOC);
	if (idx == 0)
		stack->top = new;
	ft_dlstadd_back(&stack->bottom, new);
	return (0);
}
