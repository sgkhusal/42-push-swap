/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:50:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/18 19:31:34 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_dlist *lst, char s)
{
	ft_swap(&lst->nb, &lst->next->nb);
	if (s == STACK_A)
		ft_putstr_fd("sa\n", 1);
	else if (s == STACK_B)
		ft_putstr_fd("sb\n", 1);
}

void	double_swap(t_dlist *lst_a, t_dlist *lst_b)
{
	ft_swap(&lst_a->nb, &lst_a->next->nb);
	ft_swap(&lst_b->nb, &lst_b->next->nb);
	ft_putstr_fd("ss\n", 1);
}
