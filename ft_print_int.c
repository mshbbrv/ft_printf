/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:21:36 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/20 19:34:16 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_int_right_justified(t_fmts **fmts)
{
	int	size;

	size = 0;
	if ((*fmts)->fillchr == '0' && (*fmts)->plus_sign && (*fmts)->d >= 0)
		size += ft_putchar_rv((*fmts)->plus_sign, 1);
	if ((*fmts)->plus_sign || (*fmts)->d < 0)
		(*fmts)->width--;
	if ((*fmts)->fillchr == '0' && (*fmts)->d < 0)
	{
		size += ft_putchar_rv('-', 1);
		(*fmts)->d = -(*fmts)->d;
	}
	while ((*fmts)->width-- > 0)
		size += ft_putchar_rv((*fmts)->fillchr, 1);
	if ((*fmts)->fillchr != '0' && (*fmts)->plus_sign && (*fmts)->d >= 0)
		size += ft_putchar_rv((*fmts)->plus_sign, 1);
	size += ft_putnbr_base_rv((*fmts)->d, 10, 1);
	return (size);
}

static int	ft_int_left_justified(t_fmts **fmts)
{
	int	size;

	size = 0;
	if ((*fmts)->plus_sign && (*fmts)->d >= 0)
	{
		size += ft_putchar_rv((*fmts)->plus_sign, 1);
		(*fmts)->width--;
	}
	if ((*fmts)->d < 0)
		(*fmts)->width--;
	size += ft_putnbr_base_rv((*fmts)->d, 10, 1);
	while ((*fmts)->width-- > 0 && ((*fmts)->fillchr = ' '))
		size += ft_putchar_rv((*fmts)->fillchr, 1);
	return (size);
}

int 		ft_print_int(t_fmts *fmts)
{
	fmts->d = fmts->dd;
	if (fmts->dd == 0)
		fmts->width--;
	while (fmts->dd)
	{
		fmts->dd /= 10;
		fmts->width--;
	}
	if (fmts->leftjust)
		return (ft_int_left_justified(&fmts));
	return (ft_int_right_justified(&fmts));
}