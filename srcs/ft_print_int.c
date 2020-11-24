/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:21:36 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/24 14:42:26 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_putnbr_rv(int n, int fd, int thistime)
{
	int size;

	size = 0;
	size++;
	if (n == -2147483648 && thistime)
		return (write(fd, "2147483648", 10));
	if (n < 0 && n > -10)
		size += write(fd, "-", 1);
	if (n / 10 != 0)
		size += ft_putnbr_rv(n / 10, fd, thistime);
	write(fd, &DEC[n % 10 * (n < 0 ? -1 : 1)], 1);
	return (size);
}

static int	ft_int_lennbr_base(int n, int base)
{
	int size;

	size = 0;
	size++;
	if (n / base != 0)
		size += ft_int_lennbr_base(n / base, base);
	return (size);
}

static int	ft_int_right_justified(t_fmts **fmts, int d_size, int prec, int s)
{
	int thistime;

	thistime = 0;
	if ((d_size + (*fmts)->prec) >= 0)
		(*fmts)->width -= (d_size + (*fmts)->prec);
	else
		(*fmts)->width -= d_size;
	if ((*fmts)->fillchr == '0' && (*fmts)->d < 0)
	{
		s += ft_putchar_rv('-', 1);
		(*fmts)->d = -(*fmts)->d;
		thistime = 1;
	}
	while ((*fmts)->width-- > 0)
		s += ft_putchar_rv((*fmts)->fillchr, 1);
	if ((*fmts)->prec > 0 && (*fmts)->d < 0)
	{
		s += ft_putchar_rv('-', 1);
		(*fmts)->d = -(*fmts)->d;
	}
	while ((*fmts)->prec-- > 0)
		s += ft_putchar_rv('0', 1);
	if (!((*fmts)->d == 0 && prec < d_size && (*fmts)->precflag && prec == 0))
		s += ft_putnbr_rv((*fmts)->d, 1, thistime);
	return (s);
}

static int	ft_int_left_justified(t_fmts **fmts, int d_size, int prec, int size)
{
	if ((d_size + (*fmts)->prec) >= 0)
		(*fmts)->width -= (d_size + (*fmts)->prec);
	else
		(*fmts)->width -= d_size;
	if ((*fmts)->prec > 0 && (*fmts)->d < 0)
	{
		size += ft_putchar_rv('-', 1);
		(*fmts)->d = -(*fmts)->d;
	}
	while ((*fmts)->prec-- > 0)
		size += ft_putchar_rv('0', 1);
	if (!((*fmts)->d == 0 && prec < d_size && (*fmts)->precflag && prec == 0))
		size += ft_putnbr_rv((*fmts)->d, 1, 0);
	while ((*fmts)->width-- > 0 && ((*fmts)->fillchr = ' '))
		size += ft_putchar_rv((*fmts)->fillchr, 1);
	return (size);
}

int			ft_print_int(t_fmts *fmts)
{
	int d_size;

	d_size = ft_int_lennbr_base(fmts->d, 10);
	if (fmts->precflag && fmts->prec >= 0)
		fmts->fillchr = ' ';
	if (fmts->prec >= d_size)
		fmts->prec -= d_size;
	else
	{
		if (fmts->prec > 0)
			fmts->prec = 0;
		if (fmts->d == 0 && fmts->precflag && fmts->prec >= 0)
			fmts->width++;
	}
	if (fmts->d < 0)
		fmts->width--;
	if (fmts->leftjust)
		return (ft_int_left_justified(&fmts, d_size, fmts->prec, 0));
	return (ft_int_right_justified(&fmts, d_size, fmts->prec, 0));
}
