/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_and_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:39:26 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/19 22:15:24 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_doprint(t_fmts *fmts)
{
	if (fmts->type == 'd')
		ft_print_int(fmts);
}

void ft_parse_and_print(const char *fmt, va_list *ap)
{
	t_fmts fmts;

	fmts.width = 0;
	fmts.leftjust = 0;
	fmts.fillchr = ' ';
	fmts.plus_sign = 0;
	ft_flags_parse(fmt, &fmts);
	ft_width_parse(fmt, &fmts, &ap);
	ft_type_parse(fmt, &fmts, &ap);
	ft_doprint(&fmts);
}