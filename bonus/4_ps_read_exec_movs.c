/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ps_read_exec_movs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:00:11 by sguilher          #+#    #+#             */
/*   Updated: 2022/05/09 00:55:09 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ps_make_move(t_stack *a, t_stack *b, char *mov, int size)
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
}

void	ps_execute_moves(t_stack *a, t_stack *b, t_list *movs)
{
	t_list	*aux;

	aux = movs;
	while (aux)
	{
		ps_make_move(a, b, aux->content, ft_strlen(aux->content) + 1);
		aux = aux->next;
	}
}

static int	ps_check_moves(char *mov, int size)
{
	if (ft_strncmp(mov, "ra\n", size) == 0)
		return (OK);
	else if (ft_strncmp(mov, "rb\n", size) == 0)
		return (OK);
	else if (ft_strncmp(mov, "rr\n", size) == 0)
		return (OK);
	else if (ft_strncmp(mov, "rra\n", size) == 0)
		return (OK);
	else if (ft_strncmp(mov, "rrb\n", size) == 0)
		return (OK);
	else if (ft_strncmp(mov, "rrr\n", size) == 0)
		return (OK);
	else if (ft_strncmp(mov, "pa\n", size) == 0)
		return (OK);
	else if (ft_strncmp(mov, "pb\n", size) == 0)
		return (OK);
	else if (ft_strncmp(mov, "sa\n", size) == 0)
		return (OK);
	else if (ft_strncmp(mov, "sb\n", size) == 0)
		return (OK);
	else if (ft_strncmp(mov, "ss\n", size) == 0)
		return (OK);
	else
		return (E_INVALID_MOV);
}

t_list	*ps_read_movs(t_stack *a, t_stack *b)
{
	char	*line;
	int		size;
	t_list	*movs;
	t_list	*aux;

	line = NULL;
	movs = NULL;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		aux = NULL;
		size = ft_strlen(line) + 1;
		aux = ft_lstnew(line);
		ft_lstadd_back(&movs, aux);
		if (ps_check_moves(line, size) == E_INVALID_MOV || !aux)
		{
			if (!aux)
				free(line);
			ps_error_movs(a, b, movs);
		}
		line = NULL;
	}
	if (line)
		free(line);
	return (movs);
}
