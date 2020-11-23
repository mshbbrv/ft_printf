/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:20:52 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/23 19:43:24 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_str_right_justified(t_fmts **fmts)
{
	int size;

	size = 0;
	if ((*fmts)->precflag && (*fmts)->prec < (int)ft_strlen((*fmts)->s) &&
	(*fmts)->prec >= 0)
		(*fmts)->width -= (*fmts)->prec;
	else
		(*fmts)->width -= (int)ft_strlen((*fmts)->s);
	while ((*fmts)->width-- > 0)
		size += ft_putchar_rv((*fmts)->fillchr, 1);
	if ((*fmts)->precflag && (*fmts)->prec < (int)ft_strlen((*fmts)->s) &&
	(*fmts)->prec >= 0)
	{
		while ((*fmts)->prec-- > 0)
			size += ft_putchar_rv((*((*fmts)->s)++), 1);
	}
	else
	{
		while (*((*fmts)->s))
			size += ft_putchar_rv((*((*fmts)->s)++), 1);
	}
	return (size);
}

static int	ft_str_left_justified(t_fmts **fmts)
{
	int size;

	size = 0;
	if ((*fmts)->precflag && (*fmts)->prec < (int)ft_strlen((*fmts)->s) &&
	(*fmts)->prec >= 0)
	{
		while ((*fmts)->prec-- > 0)
			size += ft_putchar_rv((*((*fmts)->s)++), 1);
	}
	else
	{
		while (*((*fmts)->s))
			size += ft_putchar_rv((*((*fmts)->s)++), 1);
	}
	(*fmts)->width -= size;
	while ((*fmts)->width-- > 0 && ((*fmts)->fillchr = ' '))
		size += ft_putchar_rv((*fmts)->fillchr, 1);
	return (size);
}

int			ft_print_str(t_fmts *fmts)
{
	if (fmts->leftjust)
		return (ft_str_left_justified(&fmts));
	return (ft_str_right_justified(&fmts));
}
