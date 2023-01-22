/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:21:16 by scornhol          #+#    #+#             */
/*   Updated: 2021/12/12 12:22:01 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates and returns a new string, which is the result of the concatenation
 * of ’s’ (prefix string) and the char ’c’(suffix char).
 * Return the new string. NULL if the allocation fails.
 * */

char	*ft_appendchr(char const *s, char const c)
{
	char	*ccat;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	ccat = (char *)malloc((len + 2) * sizeof(char));
	if (!ccat)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ccat[i] = s[i];
		i++;
	}
	ccat[i++] = c;
	ccat[i] = '\0';
	return (ccat);
}
