/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:46:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/09 18:12:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_error(void)
{
	ft_printf_fd(2, "Error\n");
	exit(EXIT_FAILURE);
}

void	ps_check_repeated_nb(int stack_size, int *nbs)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack_size)
	{
		j = i;
		while (j < stack_size)
		{
			if (nbs[i] == nbs[j])
			{
				free(nbs);
				ps_error();
			}
		}
	}
}

int	ps_check_char(char *nb)
{
	int	j;
	int	nb_size;

	j = 0;
	nb_size = ft_strlen(nb);
	while (j < nb_size)
	{
		if (!ft_isdigit(nb[j]))
		{
			if (nb[j] != '-' && nb[j] != '+')
				return (E_NOT_INT);
			if ((nb[j] != '-' || nb[j] != '+') && nb_size == 1)
				return (E_NOT_INT);
		}
		j++;
	}
	return (OK);
}

int	*ps_check_args(int stack_size, char *numbers[])
{
	int	i;
	int	*nbs;

	nbs = (int *) malloc(stack_size * sizeof(int));
	if (nbs == NULL)
		ps_error();
	i = 0;
	while (i < stack_size)
	{
		if (ps_check_char(numbers[i]) == E_NOT_INT)
		{
			free(nbs);
			ps_error();
		}
		nbs[i] = ft_atoi(numbers[i]);
		i++;
	}
	ps_check_repeated_nb(stack_size, nbs);
	return (nbs);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	ps_check_args(argc - 1, &argv[1]);
	return (0);
}
