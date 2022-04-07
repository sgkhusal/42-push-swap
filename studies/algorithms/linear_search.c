/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:14:36 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/05 22:17:51 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main()
{
	int	numbers[] = {4, 6, 8, 2, 7, 5, 0};
	int	i;

	i = 0;
	while (i < 7)
	{
		printf("Step %i\n", i + 1);
		if (numbers[i] == 0)
		{
			printf("Found\n");
			return (0);
		}
		i++;
	}
	printf("Not found\n");
	return (1);
}