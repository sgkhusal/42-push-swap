/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:43:52 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/13 19:33:22 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// my libraries and functions
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define OK 0
# define E_MALLOC 2
# define E_NOT_INT 3

typedef struct s_dlist
{
	int				nb;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

typedef struct s_stack
{
	t_dlist	*init;
	t_dlist	*end;
}			t_stack;

typedef struct s_push_swap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
}			t_push_swap;

t_dlist	*ft_dlstnew(int nb);
void	ft_dlstadd_front(t_dlist **lst_init, t_dlist *new);
void	ft_dlstadd_back(t_dlist **lst_end, t_dlist *new);
void	ft_dlstdel(t_dlist *dlist);

void	clean_stack(t_stack *stack);

#endif