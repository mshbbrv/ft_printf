/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:45:54 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/20 16:17:24 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_type_parse(const char **fmt, t_fmts *fmts, va_list **ap)
{
	if (**fmt == 'c')
	{
		fmts->c = va_arg(**ap, int);
		fmts->type = 'c';
	}
	if (**fmt == 's')
		fmts->s = va_arg(**ap, char *);
	if (**fmt == 'p')
		fmts->p = va_arg(**ap, char *);
	if (**fmt == 'd')
	{
		fmts->dd = va_arg(**ap, int);
		fmts->type = 'd';
	}
	if (**fmt == 'i')
		fmts->i = va_arg(**ap, int);
	if (**fmt == 'u')
		fmts->u = va_arg(**ap, unsigned int);
	if (**fmt == 'x')
		fmts->x = va_arg(**ap, unsigned int);
	if (**fmt == 'X')
		fmts->X = va_arg(**ap, unsigned int);
	if (**fmt == 'n')
		fmts->n = va_arg(**ap, int);
	if (**fmt == 'f')
		fmts->f = va_arg(**ap, double);
	if (**fmt == 'g')
		fmts->g = va_arg(**ap, double);
	if (**fmt == 'e')
		fmts->e = va_arg(**ap, double);
	(*fmt)++;
}
