/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:12:44 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/20 16:24:35 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_width_parse(const char **fmt, t_fmts *fmts, va_list **ap)
{
	while (**fmt && !ft_strchr(TYPES, **fmt))
	{
		if (**fmt >= '1' && **fmt <= '9')
		{
			while (ft_isdigit(**fmt))
			{
				fmts->width = fmts->width * 10 + (**fmt - 48);
				(*fmt)++;
			}
		} else if ('*' == **fmt)
		{
			fmts->width = va_arg(**ap, int);
			if (fmts->width < 0)
			{
				fmts->leftjust = 1;
				fmts->width = -fmts->width;
			}
		}
		if (!ft_strchr(TYPES, **fmt))
			(*fmt)++;
	}
}
