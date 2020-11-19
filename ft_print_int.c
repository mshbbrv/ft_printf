/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:21:36 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/19 22:14:54 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_int(t_fmts *fmts)
{
	fmts->d = fmts->dd;
	if (fmts->dd == 0)
		fmts->width--;
	while (fmts->dd)
	{
		fmts->dd /= 10;
		fmts->width--;
	}
	if (fmts->leftjust == 1)
	{
		if (fmts->plus_sign && fmts->d >= 0)
		{
			ft_putchar_fd(fmts->plus_sign, 1);
			fmts->width--;
		}
		if (fmts->d < 0)
			fmts->width--;
		ft_putnbr_fd(fmts->d, 1);
		while (fmts->width-- > 0 && fmts->fillchr == ' ')
			ft_putchar_fd(fmts->fillchr, 1);
	}
	else
	{
		if (fmts->fillchr == '0' && fmts->plus_sign && fmts->d >= 0)
			ft_putchar_fd(fmts->plus_sign, 1);
		if (fmts->plus_sign || fmts->d < 0)
			fmts->width--;
		if (fmts->fillchr == '0' && fmts->d < 0)
		{
			ft_putchar_fd('-', 1);
			fmts->d = -fmts->d;
		}
		while (fmts->width-- > 0)
			ft_putchar_fd(fmts->fillchr, 1);
		if (fmts->fillchr != '0' && fmts->plus_sign && fmts->d >= 0)
			ft_putchar_fd(fmts->plus_sign, 1);
		ft_putnbr_fd(fmts->d, 1);
	}
}