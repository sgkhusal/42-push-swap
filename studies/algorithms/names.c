/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   names.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:23:43 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/05 22:44:17 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*names[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"};
	int		i;

	i = 0;
	while (i < 7)
	{
		printf("Step %i\n", i + 1);
		if (strcmp(names[i], "Ron") == 0)
		{
			printf("Found Ron\n");
			return (0);
		}
		i++;
	}
	printf("Not found\n");
	return (1);
}
