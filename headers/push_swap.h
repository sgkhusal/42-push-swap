/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:43:52 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/19 21:37:15 by sguilher         ###   ########.fr       */
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

# define STACK_A 'a'
# define STACK_B 'b'
# define STACK_A_B 'c'

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

typedef struct s_push_swap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}			t_push_swap;

t_stack	*init_stack();
t_stack	*ps_init_stack_a(int stack_size, char *numbers[]);
int		ps_check_char(char *nb);
void	ps_check_repeated_nb(t_stack *stack);
void	ps_check_input_order(t_stack *stack);

void	push(t_stack *src, t_stack *dst, char s);
void	swap(t_dlist *lst, char s);
void	rotate(t_stack *stack, char s);
void	reverse_rotate(t_stack *stack, char s);
void	double_swap(t_dlist *lst_a, t_dlist *lst_b);
void	double_rotate(t_stack *stack_a, t_stack *stack_b);
void	double_reverse_rotate(t_stack *stack_a, t_stack *stack_b);

int		ps_check_order(t_dlist *lst);
int		ps_check_reverse_order(t_dlist *lst);
int		stack_max(t_stack *stack);
int		stack_min(t_stack *stack);
void	ft_swap(int *a, int *b);

void	ps_order_3(t_stack *stack, char s);
void	ps_order_3_reverse(t_stack *stack, char s);
void	ps_small(t_stack *a, t_stack *b, int size);
int		ps_order_4_special_case(t_stack *a, char s);
int		rotate_max_top(t_stack *a);
int		ps_small_part1(t_stack *a, t_stack *b);
int		ps_small_part2(t_stack *a, t_stack *b);
int		ps_order_4(t_stack *a, t_stack *b);
int		ps_order_5(t_stack *a, t_stack *b);
int		ps_order_6(t_stack *a, t_stack *b);
int		ps_order_7(t_stack *a, t_stack *b);
int		ps_order_8(t_stack *a, t_stack *b);
int		ps_order_9(t_stack *a, t_stack *b);
int		ps_order_10(t_stack *a, t_stack *b);

void	clean_stack(t_stack *stack);
void	ps_error(t_stack *stack);
void	ps_close(t_push_swap *data);

t_dlist	*ft_dlstnew(int nb);
void	ft_dlstadd_front(t_dlist **lst_init, t_dlist *new);
void	ft_dlstadd_back(t_dlist **lst_end, t_dlist *new);
void	ft_dlstdel(t_dlist *dlist);

#endif
