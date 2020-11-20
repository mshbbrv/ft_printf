/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:20:55 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/20 22:42:00 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>
# define TYPES "cspdiuxX%nfge"
# define DEC "0123456789"
# define HEX "0123456789abcdef"
# define OCT "01234567"

typedef struct		s_fmts
{
	int 			type;
	int				d;
	int 			c;
	char			*s;
	size_t 			p;
	int 			i;
	unsigned int	x;
	unsigned int	X;
	unsigned int	u;
	int 			n;
	double			f;
	double			g;
	double			e;
	int 			dd;
	int				width;
	int 			leftjust;
	char			fillchr;
	int 			plus_sign;
}					t_fmts;

int		ft_printf(const char *, ...);
int 	ft_doparse_doprint(const char **fmt, va_list *ap);
void	ft_flags_parse(const char **fmt, t_fmts *fmts);
void	ft_type_parse(const char **fmt, t_fmts *fmts, va_list **ap);
void	ft_width_parse(const char **fmt, t_fmts *fmts, va_list **ap);
int 	ft_print_int(t_fmts *fmts);
int 	ft_print_char(t_fmts *fmts);
int 	ft_doprint(t_fmts *fmts);
int		ft_putchar_rv(char c, int fd);
int		ft_putnbr_base_rv(int n, int base, int fd);
#endif
