/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doparse_doprint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:39:26 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/20 16:25:50 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_doparse_doprint(const char **fmt, va_list *ap)
{
	t_fmts fmts;

	fmts.width = 0;
	fmts.leftjust = 0;
	fmts.fillchr = ' ';
	fmts.plus_sign = 0;
	ft_flags_parse(&*fmt, &fmts);
	ft_width_parse(&*fmt, &fmts, &ap);
	ft_type_parse(&*fmt, &fmts, &ap);
	return (ft_doprint(&fmts));
}