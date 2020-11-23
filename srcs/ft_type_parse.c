/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:45:54 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/23 16:08:38 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_type_parse_half(const char **fmt, t_fmts *fmts, va_list **ap)
{
	if (**fmt == 'u')
	{
		fmts->u = va_arg(**ap, unsigned int);
		fmts->type = 'u';
	}
	if (**fmt == 'x')
	{
		fmts->u = va_arg(**ap, unsigned int);
		fmts->type = 'x';
	}
	if (**fmt == 'X')
	{
		fmts->u = va_arg(**ap, unsigned int);
		fmts->type = 'X';
	}
	if (**fmt == '%')
	{
		fmts->c = '%';
		fmts->type = '%';
	}
}

void	ft_type_parse(const char **fmt, t_fmts *fmts, va_list **ap)
{
	if (**fmt == 'c')
	{
		fmts->c = va_arg(**ap, int);
		fmts->type = 'c';
	}
	if (**fmt == 's')
	{
		fmts->s = va_arg(**ap, char *);
		if (NULL == fmts->s)
			fmts->s = "(null)";
		fmts->type = 's';
	}
	if (**fmt == 'p')
	{
		fmts->p = (size_t)va_arg(**ap, void *);
		fmts->type = 'p';
	}
	if (**fmt == 'd' || **fmt == 'i')
	{
		fmts->d = va_arg(**ap, int);
		fmts->type = 'd';
	}
	ft_type_parse_half(fmt, fmts, ap);
	(*fmt)++;
}
