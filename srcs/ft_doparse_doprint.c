/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doparse_doprint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:39:26 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/23 20:29:34 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_doprint(t_fmts *fmts)
{
	int size;

	size = 0;
	if (fmts->type == 'd')
		size = ft_print_int(fmts);
	if (fmts->type == 'c')
		size = ft_print_char(fmts);
	if (fmts->type == 'p')
		size = ft_print_ptr(fmts);
	if (fmts->type == 's')
		size = ft_print_str(fmts);
	if (fmts->type == 'u')
		size = ft_print_un_int(fmts);
	if (fmts->type == 'x')
		size = ft_print_x(fmts);
	if (fmts->type == 'X')
		size = ft_print_xx(fmts);
	if (fmts->type == '%')
		size = ft_print_char(fmts);
	return (size);
}

int	ft_doparse_doprint(const char **fmt, va_list *ap)
{
	t_fmts fmts;

	fmts.width = 0;
	fmts.leftjust = 0;
	fmts.fillchr = ' ';
	fmts.prec = 0;
	fmts.precflag = 0;
	ft_flags_parse(&*fmt, &fmts);
	ft_width_parse(&*fmt, &fmts, &ap);
	ft_prec_parse(&*fmt, &fmts, &ap);
	ft_type_parse(&*fmt, &fmts, &ap);
	return (ft_doprint(&fmts));
}
