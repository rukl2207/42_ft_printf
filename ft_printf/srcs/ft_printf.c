/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 10:31:17 by scornhol          #+#    #+#             */
/*   Updated: 2021/12/05 10:31:24 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * printf() - formatted output conversion
 * The  functions in the printf() family produce output according to a format
 * as described below.  The functions printf() and vprintf() write output to
 * stdout, the standard output stream. Parametrs: #1. The string format in 
 * which the output will be printed. ... The variadic arguments. In the 
 * vprintf() function, the variadic argument are already passed as a va_list 
 * type. Rerurn: Upon successful return, these functions return the number of 
 * characters printed (excluding the null byte used to end output to strings).
 
 * ft_init_format() initialize the format struct with the string (format)
 * and the va_list variable (ap), setting the initial values of len and the 
 * counter i to 0. Return the new, inilialized variable struct format.
 *
 * ft_init_specif() initialize the specificator struct (t_specif). 
 * Return the new, inilialized variable struct specificator.

 * ft_specifier() manages whatever comes after the '%'. It calls the 
 * initialize function for the format struct and the parse function
 * that will eventually convert the argument passed to the va_list into the
 * specificator struct. At the end, it will print to the screen the converted 
 * string of the respective argument. Rerurn: -.
 * */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	if (!format)
		return (0);
	va_start(ap, format);
	len = ft_vprintf(format, ap);
	va_end(ap);
	return (len);
}

int	ft_vprintf(const char *format, va_list ap)
{
	int			len;
	t_format	*fmt;

	fmt = ft_init_format(format, ap);
	if (!fmt)
		return (0);
	while (fmt->format[fmt->i])
	{
		if (fmt->format[fmt->i] == '%')
			ft_specifier(fmt);
		else
			fmt->len += write(1, &fmt->format[fmt->i++], 1);
	}
	len = fmt->len;
	free (fmt);
	return (len);
}

t_format	*ft_init_format(const char *format, va_list ap)
{
	t_format	*fmt;

	fmt = malloc(sizeof(t_format));
	if (!fmt)
		return (NULL);
	fmt->format = format;
	va_copy(fmt->ap, ap);
	fmt->i = 0;
	fmt->len = 0;
	return (fmt);
}

t_specif	*ft_init_specif(void)
{
	t_specif	*spf;

	spf = malloc(sizeof(t_specif));
	if (!spf)
		return (NULL);
	spf->left_justify = 0;
	spf->prefix = ft_strdup("");
	spf->padding = ' ';
	spf->width = 0;
	spf->precision = -1;
	spf->conversion = '\0';
	spf->argument = NULL;
	spf->len = 0;
	return (spf);
}

void	ft_specifier(t_format *fmt)
{
	t_specif	*spf;

	fmt->i++;
	spf = ft_init_specif();
	ft_parse(fmt, spf);
	if (spf->conversion)
	{
		ft_type_conversion(fmt, spf);
		fmt->len += write(1, spf->argument, spf-> len);
		free(spf-> argument);
	}
	free(spf->prefix);
	free(spf);
}
