/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:53:11 by scornhol          #+#    #+#             */
/*   Updated: 2021/10/13 20:40:35 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* re-code the functions strdup                                               */
/* man strdup                                                                 */
/* strdup - save a copy of a string. The strdup() function allocates		  */
/* sufficient memory for a copy of the string s1, does the copy, and returns  */
/* a pointer to it.															  */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*ptr;

	if (!s1)
		return (NULL);
	size = ft_strlen((char *)s1);
	ptr = malloc((size + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, size);
	ptr[size] = '\0';
	return (ptr);
}
