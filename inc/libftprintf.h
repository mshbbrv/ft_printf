/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:20:55 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/23 21:25:27 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# define TYPES "cspdiuxX%"
# define DEC "0123456789"
# define HEX "0123456789abcdef"
# define HIGHHEX "0123456789ABCDEF"
# define OCT "01234567"

typedef struct		s_fmts
{
	int				type;
	int				d;
	int				c;
	char			*s;
	size_t			p;
	unsigned int	u;
	int				width;
	int				leftjust;
	char			fillchr;
	int				plus_sign;
	int				prec;
	int				precflag;
}					t_fmts;

int					ft_printf(const char *fmt, ...);
int					ft_doparse_doprint(const char **fmt, va_list *ap);
void				ft_flags_parse(const char **fmt, t_fmts *fmts);
void				ft_type_parse(const char **fmt, t_fmts *fmts, va_list **ap);
void				ft_width_parse(const char **fmt, t_fmts *fmts, va_list
**ap);
void				ft_prec_parse(const char **fmt, t_fmts *fmts, va_list **ap);
int					ft_print_int(t_fmts *fmts);
int					ft_print_char(t_fmts *fmts);
int					ft_print_ptr(t_fmts *fmts);
int					ft_print_str(t_fmts *fmts);
int					ft_print_un_int(t_fmts *fmts);
int					ft_print_x(t_fmts *fmts);
int					ft_print_xx(t_fmts *fmts);
int					ft_putchar_rv(char c, int fd);
int					ft_putnbr_base_rv(size_t n, int base, int fd);
char				*ft_strchr(const char *s, int c);
int					ft_isalpha(int c);
#endif
