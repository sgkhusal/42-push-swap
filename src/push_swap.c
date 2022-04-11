/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:46:07 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/11 21:36:39 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_error(long int *nbs)
{
	if (nbs != NULL)
		free(nbs);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	ps_check_order(int stack_size, long int *nbs)
{
	int	i;

	i = 0;
	while (i < stack_size - 1)
	{
		if (nbs[i] > nbs[i + 1])
			return ;
		i++;
	}
	free(nbs);
	exit(EXIT_SUCCESS);
}

void	ps_check_repeated_nb(int stack_size, long int *nbs)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack_size)
	{
		j = i + 1;
		while (j < stack_size)
		{
			if (nbs[i] == nbs[j])
				ps_error(nbs);
			j++;
		}
		i++;
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
			if ((nb[j] == '-' || nb[j] == '+') && nb_size == 1)
				return (E_NOT_INT);
			if ((nb[j] == '-' || nb[j] == '+') && j > 1)
				return (E_NOT_INT);
		}
		j++;
	}
	return (OK);
}

int	*ps_check_args(int stack_size, char *numbers[])
{
	int	i;
	long int	*nbs;

	nbs = (long int *) malloc(stack_size * sizeof(long int));
	if (nbs == NULL)
		ps_error(NULL);
	i = 0;
	while (i < stack_size)
	{
		if (ps_check_char(numbers[i]) == E_NOT_INT)
			ps_error(nbs);
		nbs[i] = ft_atol(numbers[i]);
		if (nbs[i] > 2147483647 || nbs[i] < -2147483648)
			ps_error(nbs);
		i++;
	}
	if (stack_size == 1)
	{
		free(nbs);
		exit(EXIT_SUCCESS);
	}
	ps_check_repeated_nb(stack_size, nbs);
	ps_check_order(stack_size, nbs);
	return ((int *)nbs);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	ps_check_args(argc - 1, &argv[1]);
	return (0);
}
