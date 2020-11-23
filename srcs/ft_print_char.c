/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:29:09 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/20 19:34:52 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_char_right_justified(t_fmts **fmts)
{
	int size;

	size = 0;
	while ((*fmts)->width-- > 0)
		size += ft_putchar_rv((*fmts)->fillchr, 1);
	size += ft_putchar_rv((*fmts)->c, 1);
	return (size);
}

static int	ft_char_left_justified(t_fmts **fmts)
{
	int size;

	size = 0;
	size += ft_putchar_rv((*fmts)->c, 1);
	while ((*fmts)->width-- > 0 && ((*fmts)->fillchr = ' '))
		size += ft_putchar_rv((*fmts)->fillchr, 1);
	return (size);
}

int			ft_print_char(t_fmts *fmts)
{
	if (fmts->width)
		fmts->width--;
	if (fmts->leftjust)
		return (ft_char_left_justified(&fmts));
	return (ft_char_right_justified(&fmts));
}
