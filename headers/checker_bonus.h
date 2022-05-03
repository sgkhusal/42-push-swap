/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:28:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/03 10:07:35 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

// my libraries and functions
# include "libft.h"
# include "ft_printf.h"

# define OK 0
# define E_MALLOC 2
# define E_NOT_INT 3

# define ORDER 1
# define NOT_ORDER 0

typedef struct s_dlist
{
	int				nb;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

typedef struct s_stack
{
	t_dlist	*top;
	t_dlist	*bottom;
	int		max;
	int		min;
	int		size;
}			t_stack;

int	ps_check_order(t_dlist *lst);
int	stack_min(t_stack *stack);
int	stack_max(t_stack *stack);


#endif
