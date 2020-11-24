/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:46:00 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/24 14:06:41 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_flags_parse(const char **fmt, t_fmts *fmts)
{
	while (**fmt && !ft_isalpha_perc(**fmt) && !(**fmt >= '1'
	&& **fmt <= '9') && **fmt != '*' && **fmt != '.')
	{
		if ('0' == **fmt)
			fmts->fillchr = '0';
		if ('-' == **fmt)
			fmts->leftjust = 1;
		(*fmt)++;
	}
}
