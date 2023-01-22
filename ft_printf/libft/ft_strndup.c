/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:22:13 by scornhol          #+#    #+#             */
/*   Updated: 2021/12/12 12:22:22 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* re-code the functions strndup                                              */
/* man strndup                                                                */
/* strndup - save a copy of a string. The strndup() function copies at most n */
/* characters from the string s1 always NUL terminating the copied string.    */
/* The strdup() function allocates sufficient memory for a copy of the string */
/* s1, does the copy, and returns a pointer to it.							  */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str_cpy;
	size_t	size;

	if (!s1)
		return (NULL);
	size = ft_strlen((char *)s1);
	if (size > n)
		size = n;
	str_cpy = (char *)malloc(sizeof(char) * (size + 1));
	if (NULL == str_cpy)
		return (NULL);
	ft_memcpy(str_cpy, s1, size);
	str_cpy[size] = '\0';
	return (str_cpy);
}
