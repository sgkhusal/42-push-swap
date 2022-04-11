/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:12:05 by sguilher          #+#    #+#             */
/*   Updated: 2022/04/11 20:24:25 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	compair_atol(const char *n);
long int	ft_atol(const char *nptr);
void	test_ft_atol(void);

int	main(void)
{
	printf("\nMaximum int: 2147483647\n");
	printf("atol result = %li\n", atol("2147483647"));
	printf("ft_atol result = %li\n", ft_atol("2147483647"));
	printf("diff = %li\n", atol("2147483647") - ft_atol("2147483647"));
	
	printf("\nMinimum int: -2147483648\n");
	printf("atol result = %li\n", atol("-2147483648"));
	printf("ft_atol result = %li\n", ft_atol("-2147483648"));
	printf("diff = %li\n", atol("-2147483648") - ft_atol("-2147483648"));
	
	printf("\nGreater than maximum int: 2147483648\n");
	printf("atol result = %li\n", atol("2147483648"));
	printf("ft_atol result = %li\n", ft_atol("2147483648"));
	printf("diff = %li\n", atol("2147483648") - ft_atol("2147483648"));

	printf("\nLesser than minimum int: -2147483649\n");
	printf("atol result = %li\n", atol("-2147483649"));
	printf("ft_atol result = %li\n", ft_atol("-2147483649"));
	printf("diff = %li\n", atol("-2147483649") - ft_atol("-2147483649"));

	test_ft_atol();
	return (0);
}

void	test_ft_atol(void)
{
	printf("\n\n\n*****************************ft_atol function*****************************\n");

	printf("\ntest 1: n\n");
	compair_atol("1");

	printf("\ntest 2: nnn\n");
	compair_atol("109");

	printf("\ntest 3: 7n\n");
	compair_atol("5000000");

	printf("\ntest 4: 0\n");
	compair_atol("---++00000");

	printf("\ntest 5: maximum int\n");
	compair_atol("+2147483647");

	printf("\ntest 6: minimum int\n");
	compair_atol("-2147483648");

	printf("\ntest 7: < minimum int - not ok\n");
	compair_atol("-2147483649");

	printf("\ntest 8: > maximum int - not ok\n");
	compair_atol("2147483648");

	printf("\ntest 9: 0000n\n");
	compair_atol("000753");

	printf("\ntest 10: 0000--n\n");
	compair_atol("000--753");

	printf("\ntest 10.1: 001-+ n\n");
	compair_atol("001-+ 753");

	printf("\ntest 11: sum\n");
	compair_atol("100+83");

	printf("\ntest 12: subtraction\n");
	compair_atol("-100+83");

	printf("\ntest 13: space in the middle\n");
	compair_atol("-100 83");

	printf("\ntest 14: letters and numbers 1\n");
	compair_atol("-10abcde83");

	printf("\ntest 15: letters and numbers 2\n");
	compair_atol("jhjhsd-10abcde83");

	printf("\ntest 16: letters 1\n");
	compair_atol("+++---abcde");

	printf("\ntest 17: letters 2\n");
	compair_atol("ABcde");

	printf("\ntest 18: space 1\n");
	compair_atol("   ");

	printf("\ntest 19: space 2\n");
	compair_atol("   1");

	printf("\ntest 20: \\t\\t\\t\\-1\n");
	compair_atol("\t\t\t-1");

	printf("\ntest 21: \\n\\n\\n-1\n");
	compair_atol("\n\n\n-1");

	printf("\ntest 22: \\n in the middle\n");
	compair_atol("+7\n-1");

	printf("\ntest 23: \\v\\v\\v-1\n");
	compair_atol("\v\v\v-1");

	printf("\ntest 24: \\f\\f\\f-1\n");
	compair_atol("\f\f\f-1");

	printf("\ntest 25: \\r\\r\\r-1\n");
	compair_atol("\r\r\r-1");

	printf("\ntest 26: --n\n");
	compair_atol("--7");

	printf("\ntest 27: ---n\n");
	compair_atol("---7");

	printf("\ntest 28: -+n\n");
	compair_atol("-+7");

	printf("\ntest 29: non printable - 0 to 8, 14 to 31\n");
	char str[] = "0123456789";
	str[0] = 0;
	compair_atol(str);
}

void	compair_atol(const char *n)
{
	printf("n = %s\n", n);
	printf("atol result    = %ld\n", atol(n));
	printf("ft_atol result = %ld\n", ft_atol(n));
	if (atol(n) == ft_atol(n))
		printf("OK\n");
	else
		printf("NOT OK\n");
}
