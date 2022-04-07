/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:48:14 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/05 23:39:39 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

typedef struct
{
	char	*name;
	char	*number;
}
person;

int	main(void)
{
	//char	*names[] = {"Brian", "David"};
	//char	*numbers[] = {"+1-617-495-1000", "+1-949-468-2750"};
	person	people[2];
	int		i;

	people[0].name = "Brian";
	people[0].number = "+1-617-495-1000";
	people[0].name = "David";
	people[0].number = "+1-949-468-2750";
	i = 0;
	while (i < 2)
	{
		if (strcmp(people[i].name, "David") == 0)
		{
			printf("Found %s\n", people[i].number);
			return (0);
		}
		i++;
	}
	printf("Not found\n");
	return (1);
}