/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:50:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/03 10:23:37 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	ps_add_elem(t_stack *stack, int nbr)
{
	t_dlist	*new;

	new = ft_dlstnew(nbr);
	if (new == NULL)
		return (E_MALLOC);
	if (stack->top == NULL && stack->bottom == NULL)
	{
		stack->top = new;
		stack->bottom = new;
	}
	ft_dlstadd_back(&stack->bottom, new);
	return (0);
}
