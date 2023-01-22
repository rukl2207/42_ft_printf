/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:03:21 by scornhol          #+#    #+#             */
/*   Updated: 2021/12/12 16:03:24 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ft_type_conversion() takes the completed specifier and format structures and
 * redirects them to its specific conversion functions. Return: -
 * */

#include "ft_printf.h"

static void	ft_prefix_ux(t_specif *spf);

void	ft_type_conversion(t_format *fmt, t_specif *spf)
{
	if (spf->conversion == 'c')
		ft_convert_c(fmt, spf);
	else if (spf->conversion == 's')
		ft_convert_s(fmt, spf);
	else if (spf->conversion == 'p')
		ft_convert_p(fmt, spf);
	else if (spf->conversion == 'd' || spf->conversion == 'i')
		ft_convert_d_i(fmt, spf);
	else if (spf->conversion == 'u')
		ft_convert_ux(fmt, spf, DEC_BASE);
	else if (spf->conversion == 'x')
		ft_convert_ux(fmt, spf, HEX_L_BASE);
	else if (spf->conversion == 'X')
		ft_convert_ux(fmt, spf, HEX_U_BASE);
	else
		ft_convert_pct(spf);
}

void	ft_fill_left_pad(char **src, char padding, int width)
{
	char	*temp;
	size_t	str_len;
	size_t	pad_len;

	str_len = ft_strlen(*src);
	if (!width || width < (int)str_len)
		width = str_len;
	temp = (char *)malloc((width + 1) * sizeof(char));
	if (!temp)
		return ;
	pad_len = width - str_len;
	ft_memset(temp, padding, pad_len);
	temp[pad_len] = '\0';
	ft_strlcat(temp, *src, width + 1);
	free(*src);
	*src = temp;
}

void	ft_fill_right_pad(char **src, char padding, int width)
{
	char	*temp;
	size_t	str_len;
	size_t	pad_len;

	str_len = ft_strlen(*src);
	if (!width || width < (int)str_len)
		width = str_len;
	temp = (char *)malloc((width + 1) * sizeof(char));
	if (!temp)
		return ;
	ft_strlcpy(temp, *src, str_len + 1);
	pad_len = width - str_len;
	ft_memset(&temp[str_len], padding, pad_len);
	temp[width] = '\0';
	free(*src);
	*src = temp;
}

void	ft_add_prefix(t_specif	*spf, int sign)
{
	int	len;

	len = (int)ft_strlen(spf->argument);
	if (spf->conversion == 'd' || spf->conversion == 'i')
	{
		len += 1;
		if (ft_strchr(spf->prefix, PLUS) && sign == 1)
			ft_fill_left_pad(&spf->argument, PLUS, len);
		else if (ft_strchr(spf->prefix, SPACE) && sign == 1)
			ft_fill_left_pad(&spf->argument, SPACE, len);
		else if (sign == -1)
			ft_fill_left_pad(&spf->argument, MINUS, len);
	}
	else if (spf->conversion == 'x' || spf->conversion == 'X')
		ft_prefix_ux(spf);
}

static void	ft_prefix_ux(t_specif *spf)
{
	char	*temp;

	temp = spf->argument;
	if (ft_strchr(spf->prefix, '#'))
	{
		if (spf->conversion == 'x')
			spf->argument = ft_strjoin(HEX_L_PREFIX, temp);
		if (spf->conversion == 'X')
			spf->argument = ft_strjoin(HEX_U_PREFIX, temp);
		free(temp);
	}
}
