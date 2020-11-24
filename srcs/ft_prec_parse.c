/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:58:32 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/23 20:33:26 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_prec_parse(const char **fmt, t_fmts *fmts, va_list **ap)
{
	while (**fmt && !ft_isalpha_perc(**fmt))
	{
		if ('.' == **fmt)
		{
			++(*fmt);
			fmts->precflag = 1;
			if (**fmt >= '0' && **fmt <= '9')
			{
				fmts->prec = 0;
				while (**fmt >= '0' && **fmt <= '9')
				{
					fmts->prec = fmts->prec * 10 + (**fmt - '0');
					(*fmt)++;
				}
			}
			else if ('*' == **fmt)
				fmts->prec = va_arg(**ap, int);
		}
		if (!ft_isalpha_perc(**fmt))
			++(*fmt);
	}
}
