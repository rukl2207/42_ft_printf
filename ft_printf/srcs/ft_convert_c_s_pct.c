/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c_s_pct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:02:40 by scornhol          #+#    #+#             */
/*   Updated: 2021/12/12 16:02:49 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ft_convert_c() converts the variadic argument into a single character string
 * and return it into the specificator 'argument'.Return: -.
 *
 * ft_convert_s() converts the variadic argument into a string and return it
 * into the specificator 'argument'. Return: -.
 *
 * ft_convert_pct() converts the '%' into a single character of its kind.
 * Return: -.
 * */

#include "ft_printf.h"

void	ft_convert_c(t_format *fmt, t_specif *spf)
{
	char	ch;

	ch = (unsigned char)va_arg(fmt->ap, int);
	if (!spf->width)
		spf->width += 1;
	spf->argument = (char *)malloc(spf->width * sizeof(char));
	if (!spf->argument)
		return ;
	ft_memset(spf->argument, SPACE, spf->width);
	if (spf->left_justify == 1)
		spf->argument[0] = ch;
	else
		spf->argument[spf->width - 1] = ch;
	spf->len = spf->width;
}

void	ft_convert_s(t_format *fmt, t_specif *spf)
{
	char	*s;
	int		len;
	char	*temp;

	s = ft_strdup(va_arg(fmt->ap, char *));
	if (!s)
		s = ft_strdup("(null)");
	len = (int)ft_strlen(s);
	spf->argument = (char *)malloc((len + 1) * sizeof(char));
	if (!spf->argument)
		return ;
	ft_strlcpy(spf->argument, s, len + 1);
	if (spf->precision > -1)
	{
		temp = spf->argument;
		spf->argument = ft_strndup(temp, (size_t)spf->precision);
		free(temp);
	}
	if (!spf->left_justify)
		ft_fill_left_pad(&spf->argument, ' ', spf->width);
	else
		ft_fill_right_pad(&spf->argument, ' ', spf->width);
	spf->len = ft_strlen(spf->argument);
	free(s);
}

void	ft_convert_pct(t_specif *spf)
{
	spf->argument = ft_appendchr("", spf->conversion);
	if (!spf->left_justify)
		ft_fill_left_pad(&spf->argument, spf->padding, spf->width);
	else
		ft_fill_right_pad(&spf->argument, ' ', spf->width);
	spf->len = ft_strlen(spf->argument);
}
