/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 10:30:18 by scornhol          #+#    #+#             */
/*   Updated: 2021/12/05 10:30:39 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ft_parse() take the format string and attempt to analyze and organize 
 * values into a struct of type t_specif, using other parsing subfunctions.
 * Return the t_specif variable that holds all the information about that
 * particular specificator.
 * */

#include "ft_printf.h"

void	*ft_parse(t_format *fmt, t_specif *spf)
{
	ft_parse_flags(fmt, spf);
	ft_parse_width(fmt, spf);
	ft_parse_precision(fmt, spf);
	ft_parse_conversion(fmt, spf);
	if (!spf->conversion && (ft_strchr(SPECIF_ALL, fmt->format[fmt->i])))
		ft_parse(fmt, spf);
	return (spf);
}

void	ft_parse_flags(t_format *fmt, t_specif *spf)
{
	char	*temp;

	if (!spf->prefix)
		spf->prefix = ft_strdup("");
	while (ft_strchr(SPECIF_ALL_FLAGS, fmt->format[fmt->i]))
	{
		if (fmt->format[fmt->i] == SPECIF_JUSTIFY)
			spf->left_justify = 1;
		if (ft_strchr(SPECIF_PREFIX, fmt->format[fmt->i]))
		{
			temp = spf->prefix;
			spf->prefix = ft_appendchr(temp, fmt->format[fmt->i]);
			free(temp);
		}
		if (fmt->format[fmt->i] == SPECIF_PAD)
			spf->padding = SPECIF_PAD;
		fmt->i++;
	}
}

void	ft_parse_width(t_format *fmt, t_specif *spf)
{
	int	width;

	width = spf->width;
	if (fmt->format[fmt->i] == SPECIF_ASTERIX)
	{
		width = (int)va_arg(fmt->ap, int);
		if (width < 0)
		{
			spf->left_justify = 1;
			width *= -1;
		}
		fmt->i++;
	}
	else if (ft_isdigit(fmt->format[fmt->i]))
	{
		width = 0;
		while (ft_isdigit(fmt->format[fmt->i]))
		{
			width = (width * 10) + (fmt->format[fmt->i] - '0');
			fmt->i++;
		}
	}
	spf->width = width;
}

void	ft_parse_precision(t_format *fmt, t_specif *spf)
{
	int	precision;

	precision = spf->precision;
	if (fmt->format[fmt->i] == SPECIF_PRECISION)
	{
		fmt->i++;
		if (fmt->format[fmt->i] == SPECIF_ASTERIX)
		{
			precision = (int)va_arg(fmt->ap, int);
			fmt->i++;
		}
		else if (!ft_isdigit(fmt->format[fmt->i]))
			precision = 0;
		else
		{
			precision = 0;
			while (ft_isdigit(fmt->format[fmt->i]))
			{
				precision = (precision * 10) + (fmt->format[fmt->i] - '0');
				fmt->i++;
			}
		}
	}
	spf->precision = precision;
}

void	ft_parse_conversion(t_format *fmt, t_specif *spf)
{
	if (!ft_strchr(SPECIF_ALL, fmt->format[fmt->i]) \
		&& ft_isprint(fmt->format[fmt->i]))
	{
		spf->conversion = fmt->format[fmt->i];
		fmt->i++;
	}
}
