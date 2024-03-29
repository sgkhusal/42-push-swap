/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:43:52 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/06 21:12:28 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// my libraries and functions
# include "libft.h"
# include "ft_printf.h"

# define OK 0
# define E_MALLOC 2
# define E_NOT_INT 3

# define STACK_A 'a'
# define STACK_B 'b'
# define STACK_A_B 'c'

# define ORDER 1
# define NOT_ORDER 0

# define ODD 1
# define MIN_SIZE 13
# define MEDIUM 1
# define BIG 2

typedef struct s_dlist
{
	int				nb;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

typedef struct s_quick_sort
{
	int		a_size;
	int		b_size;
}			t_quick_sort;

typedef struct s_stack
{
	t_dlist	*top;
	t_dlist	*bottom;
	int		max;
	int		min;
	int		size;
}			t_stack;

typedef struct s_push_swap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*order;
	double	median;
	double	median2;
	int		status;
}			t_push_swap;

t_stack			*init_stack(void);
t_stack			*ps_init_stack_a(int stack_size, char *numbers[]);
int				ps_check_char(char *nb);
void			ps_check_repeated_nb(t_stack *stack);
void			ps_check_input_order(t_stack *stack);

void			push(t_stack *src, t_stack *dst, char s);
void			swap(t_dlist *lst, char s);
void			rotate(t_stack *stack, char s);
void			reverse_rotate(t_stack *stack, char s);
void			double_swap(t_dlist *lst_a, t_dlist *lst_b);
void			double_rotate(t_stack *stack_a, t_stack *stack_b);
void			double_reverse_rotate(t_stack *stack_a, t_stack *stack_b);

void			ft_swap(int *a, int *b);
int				ps_check_order(t_dlist *lst);
int				stack_max(t_stack *stack);
int				stack_min(t_stack *stack);
void			ps_set(t_stack *s, t_push_swap *ps, int size);
double			ps_median(t_push_swap *ps);
double			ps_second_median(t_push_swap *ps, char s);
t_quick_sort	ps_section_size(int size);

void			ps_order_3(t_stack *stack);
void			ps_small(t_stack *a, t_stack *b);
void			ps_big(t_stack *a, t_stack *b, t_push_swap *ps);
void			ps_selection_sort(t_stack *a, t_stack *b, t_quick_sort qs);
void			ps_qs_small1(t_stack *a, t_stack *b, t_push_swap *ps, int ref);
void			ps_qs_small2(t_stack *a, t_stack *b, t_push_swap *ps, int ref);
t_quick_sort	ps_qs_big(t_push_swap *ps, int qs_b_size);

void			clean_stack(t_stack *stack);
void			ps_error(t_stack *stack);

t_dlist			*ft_dlstnew(int nb);
t_dlist			*dlstdup(t_dlist *lst, int size);
void			ft_dlstadd_front(t_dlist **lst_init, t_dlist *new);
void			ft_dlstadd_back(t_dlist **lst_end, t_dlist *new);
void			ft_dlstdel(t_dlist *dlist);
int				ps_add_elem(t_stack *stack, int nbr);

#endif
