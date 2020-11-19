/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:46:00 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/19 19:57:15 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_flags_parse(const char *fmt, t_fmts *fmts)
{
	while ((*fmt && !ft_strchr(TYPES, *fmt)) && !(*fmt >= '1' && *fmt <=
																   '9'))
	{
		if ('0' == *fmt)
			fmts->fillchr = '0';
		if ('-' == *fmt)
			fmts->leftjust = 1;
		if ('+' == *fmt)
			fmts->plus_sign = '+';
		if (' ' == *fmt)
			if (fmts->plus_sign == 0)
				fmts->plus_sign = ' ';
		fmt++;
	}
}