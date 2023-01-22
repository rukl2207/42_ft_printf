/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p_ux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:08:48 by scornhol          #+#    #+#             */
/*   Updated: 2021/12/12 16:08:54 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ft_convert_p() converts the variadic argument into a string representing its
 * pointer in hexadecimal value and return it into the specificator 'argument'
 * variable. Return: -.
 *
 * ft_convert_ux() converts the variadic argument into a numerical string of
 * any base and return it into the specificator 'argument' variable. Return: -.
 * */

#include "ft_printf.h"

static char	*ft_nullset(t_specif *spf)
{
	char	*number;

	if (spf->precision > -1)
	{
		number = (char *)malloc((spf->precision + 1) * sizeof(char));
		if (!number)
			return (NULL);
		ft_memset(number, '0', (size_t)spf->precision);
		number[spf->precision] = '\0';
	}
	else
		number = ft_strdup("0");
	return (number);
}

void	ft_convert_p(t_format *fmt, t_specif *spf)
{
	void	*ptr;
	char	*number;

	number = NULL;
	ptr = va_arg(fmt->ap, void *);
	if (!ptr)
		number = ft_nullset(spf);
	else
		number = ft_uitoa_base((unsigned long)ptr, HEX_L_BASE);
	spf->argument = ft_strjoin(HEX_L_PREFIX, number);
	free(number);
	if (!spf->left_justify)
		ft_fill_left_pad(&spf->argument, ' ', spf->width);
	else
		ft_fill_right_pad(&spf->argument, ' ', spf->width);
	spf->len = ft_strlen(spf->argument);
}

void	ft_convert_ux(t_format *fmt, t_specif *spf, char *base)
{
	unsigned int	nbr;
	char			*number;

	number = NULL;
	nbr = (unsigned int)(va_arg(fmt->ap, unsigned int));
	number = ft_uitoa_base((unsigned long)nbr, base);
	spf->argument = ft_strdup(number);
	free(number);
	if (spf->precision > -1)
	{
		if (!spf->precision && nbr == 0)
		{
			free(spf->argument);
			spf->argument = ft_strdup("");
		}
		ft_fill_left_pad(&spf->argument, '0', spf->precision);
		spf->padding = ' ';
	}
	if (nbr)
		ft_add_prefix(spf, 0);
	if (!spf->left_justify)
		ft_fill_left_pad(&spf->argument, spf->padding, spf->width);
	else
		ft_fill_right_pad(&spf->argument, ' ', spf->width);
	spf->len = ft_strlen(spf->argument);
}
