/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:28:16 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/03 10:44:22 by sguilher         ###   ########.fr       */
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

t_stack	*init_stack(void);
int		stack_min(t_stack *stack);
int		stack_max(t_stack *stack);

int		ps_add_elem(t_stack *stack, int nbr);
int		ps_check_order(t_dlist *lst);
int		ps_check_char(char *nb);
void	ps_check_repeated_nb(t_stack *stack);
void	ps_check_input_order(t_stack *stack);

void	ps_error(t_stack *stack);
void	clean_stack(t_stack *stack);

t_dlist	*ft_dlstnew(int nb);
void	ft_dlstdel(t_dlist *dlist);

#endif
