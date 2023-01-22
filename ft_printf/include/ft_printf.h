/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornhol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 10:34:16 by scornhol          #+#    #+#             */
/*   Updated: 2021/12/12 12:19:59 by scornhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define SPECIF_CONVERSION "cspdiuxX"
# define SPECIF_ALL "-0# +1234567890*"
# define SPECIF_ALL_FLAGS "-0# +"
# define SPECIF_JUSTIFY '-'
# define SPECIF_PREFIX "# +"
# define SPECIF_PAD '0'
# define SPECIF_PRECISION '.'
# define SPECIF_ASTERIX '*'

# define DEC_BASE "0123456789"
# define HEX_U_BASE "0123456789ABCDEF"
# define HEX_L_BASE "0123456789abcdef"

# define HEX_L_PREFIX "0x"
# define HEX_U_PREFIX "0X"
# define MINUS '-'
# define PLUS '+'
# define SPACE ' '

typedef struct s_format
{
	const char	*format;
	va_list		ap;
	size_t		i;
	size_t		len;
}	t_format;

typedef struct s_specif
{
	int		left_justify;
	char	*prefix;
	char	padding;
	int		width;
	int		precision;
	char	conversion;
	char	*argument;
	size_t	len;
}	t_specif;

/*  ft_printf.c  */
int			ft_printf(const char *format, ...);
int			ft_vprintf(const char *format, va_list ap);
t_format	*ft_init_format(const char *format, va_list ap);
t_specif	*ft_init_specif(void);
void		ft_specifier(t_format *fmt);

/*  ft_parse.c  */
void		*ft_parse(t_format *fmt, t_specif *spf);
void		ft_parse_flags(t_format *fmt, t_specif *spf);
void		ft_parse_width(t_format *fmt, t_specif *spf);
void		ft_parse_precision(t_format *fmt, t_specif *spf);
void		ft_parse_conversion(t_format *fmt, t_specif *spf);

/*  ft_convert.c  */
void		ft_type_conversion(t_format *fmt, t_specif *spf);
void		ft_fill_left_pad(char **src, char padding, int width);
void		ft_fill_right_pad(char **src, char padding, int width);
void		ft_add_prefix(t_specif	*spf, int sign);

/*  ft_convert_c_s_pct.c  */
void		ft_convert_c(t_format *fmt, t_specif *spf);
void		ft_convert_s(t_format *fmt, t_specif *spf);
void		ft_convert_pct(t_specif *spf);

/*  ft_convert_d_i.c  */
void		ft_convert_d_i(t_format *fmt, t_specif *spf);

/*  ft_convert_p_u_x.c  */
void		ft_convert_p(t_format *fmt, t_specif *spf);
void		ft_convert_ux(t_format *fmt, t_specif *spf, char *base);

#endif
