/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:27:39 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/23 21:41:11 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_x_lennbr_base(size_t n, int base)
{
	int size;

	size = 0;
	size++;
	if (n / base != 0)
		size += ft_x_lennbr_base(n / base, base);
	return (size);
}

static int	ft_x_right_justified(t_fmts **fmts, int d_size, int prec)
{
	int size;

	size = 0;
	(*fmts)->width -= (d_size + (*fmts)->prec);
	while ((*fmts)->width-- > 0)
		size += ft_putchar_rv((*fmts)->fillchr, 1);
	while ((*fmts)->prec-- > 0)
		size += ft_putchar_rv('0', 1);
	if (!((*fmts)->u == 0 && prec < d_size && (*fmts)->precflag && prec == 0))
		size += ft_putnbr_base_rv((*fmts)->u, 16, 1);
	return (size);
}

static int	ft_x_left_justified(t_fmts **fmts, int d_size, int prec)
{
	int size;

	size = 0;
	(*fmts)->width -= (d_size + (*fmts)->prec);
	while ((*fmts)->prec-- > 0)
		size += ft_putchar_rv('0', 1);
	if (!((*fmts)->u == 0 && prec < d_size && (*fmts)->precflag && prec == 0))
		size += ft_putnbr_base_rv((*fmts)->u, 16, 1);
	while ((*fmts)->width-- > 0 && ((*fmts)->fillchr = ' '))
		size += ft_putchar_rv((*fmts)->fillchr, 1);
	return (size);
}

int			ft_print_x(t_fmts *fmts)
{
	int d_size;

	d_size = ft_x_lennbr_base(fmts->u, 16);
	if (fmts->precflag)
		fmts->fillchr = ' ';
	if (fmts->prec >= d_size)
		fmts->prec -= d_size;
	else
	{
		if (fmts->prec > 0)
			fmts->prec = 0;
		if (fmts->u == 0 && fmts->precflag && fmts->prec >= 0)
			fmts->width++;
	}
	if (fmts->leftjust)
		return (ft_x_left_justified(&fmts, d_size, fmts->prec));
	return (ft_x_right_justified(&fmts, d_size, fmts->prec));
}
