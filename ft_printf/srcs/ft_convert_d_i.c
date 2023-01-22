/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:03:01 by scornhol          #+#    #+#             */
/*   Updated: 2021/12/12 16:03:12 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ft_convert_d_i() converts the variadic argument into a decimal number
 * string and return it into the specificator 'argument' variable. Return: -.
 * */

#include "ft_printf.h"

static void	ft_convert_d_i_width(t_specif *spf, int sign)
{
	if (spf->left_justify)
	{
		ft_add_prefix(spf, sign);
		ft_fill_right_pad(&spf->argument, ' ', spf->width);
	}
	else
	{
		if (spf->padding == ' ')
		{
			ft_add_prefix(spf, sign);
			ft_fill_left_pad(&spf->argument, spf->padding, spf->width);
		}
		else if (spf->padding == '0')
		{
			if (sign < 0 || ft_strchr(spf->prefix, ' ') || \
				ft_strchr(spf->prefix, '+'))
				ft_fill_left_pad(&spf->argument, spf->padding, spf->width - 1);
			else
				ft_fill_left_pad(&spf->argument, spf->padding, spf->width);
			ft_add_prefix(spf, sign);
		}
	}
}

void	ft_convert_d_i(t_format *fmt, t_specif *spf)
{
	int			sign;
	long int	arg;

	sign = 1;
	arg = (int)va_arg(fmt->ap, int);
	if (arg < 0)
		sign *= -1;
	if (arg == -2147483648)
		spf->argument = ft_strdup("2147483648");
	else
		spf->argument = ft_uitoa_base(sign * arg, DEC_BASE);
	if (spf->precision > -1)
	{
		if (!spf->precision && arg == 0)
		{
			free(spf->argument);
			spf->argument = ft_strdup("");
		}
		ft_fill_left_pad(&spf->argument, '0', spf->precision);
		spf->padding = ' ';
	}
	ft_convert_d_i_width(spf, sign);
	spf->len = ft_strlen(spf->argument);
}
