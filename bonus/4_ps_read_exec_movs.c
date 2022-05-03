/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ps_read_exec_movs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:00:11 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/03 12:03:53 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int    ps_execute_moves(t_stack *a, t_stack *b, char *mov, int size)
{
	if (ft_strncmp(mov, "ra\n", size) == 0)
		rotate(a);
	else if (ft_strncmp(mov, "rb\n", size) == 0)
		rotate(b);
	else if (ft_strncmp(mov, "rr\n", size) == 0)
		double_rotate(a, b);
	else if (ft_strncmp(mov, "rra\n", size) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(mov, "rrb\n", size) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(mov, "rrr\n", size) == 0)
		double_reverse_rotate(a, b);
	else if (ft_strncmp(mov, "pa\n", size) == 0)
		push(b, a);
	else if (ft_strncmp(mov, "pb\n", size) == 0)
		push(a, b);
	else if (ft_strncmp(mov, "sa\n", size) == 0)
		swap(a->top);
	else if (ft_strncmp(mov, "sb\n", size) == 0)
		swap(b->top);
	else if (ft_strncmp(mov, "ss\n", size) == 0)
		double_swap(a->top, b->top);
	else
		return (E_INVALID_MOV);
	return (OK);
}

void    ps_read_exec_movs(t_stack *a, t_stack *b)
{
	char   *mov;
	int		size;

	mov = NULL;
	while (get_next_line(STDIN_FILENO, &mov) > 0)
	{
		size = ft_strlen(mov) + 1;
		if (ps_execute_moves(a, b, mov, size) == E_INVALID_MOV)
		{
			free(mov);
			ps_error_movs(a, b);
		}
		free(mov);
		mov = NULL;
	}
}
