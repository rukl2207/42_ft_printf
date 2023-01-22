/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 10:25:50 by scornhol          #+#    #+#             */
/*   Updated: 2021/12/05 10:29:13 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * gcc -Wall -Wextra -Werror -c test_main.c
 * gcc -o test test_main.o -L. -lftprintf
 * ./test
 * */

/*	system("leaks test.out");*/
	/*
	while (1)
	{
		n1 = 1;
	}
	*/

#include "./include/ft_printf.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	n1;
	int	n2;

	n1 = printf("|d:%d| |i:%i| |c:%c| |s:%s| |u:%u| |x:%x| |X:%X| |%%|\n",
			42, 42, 'c', "String", 42, 42, 42);
	n2 = ft_printf("|d:%d| |i:%i| |c:%c| |s:%s| |u:%u| |x:%x| |X:%X| |%%|\n",
			42, 42, 'c', "String", 42, 42, 42);
	if (n1 == n2)
		printf("Ok\n");
	else
		printf("WARNING\n");
	return (0);
}
