/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:48:25 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/23 17:02:54 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_lennbr_base(size_t n, size_t base)
{
	int size;

	size = 0;
	size++;
	if (n / base != 0)
		size += ft_lennbr_base(n / base, base);
	return (size);
}

static int	ft_ptr_right_justified(t_fmts **fmts, int d_size)
{
	int size;

	size = 0;
	(*fmts)->width -= (2 + d_size);
	if ((*fmts)->fillchr == '0')
	{
		size += ft_putchar_rv('0', 1);
		size += ft_putchar_rv('x', 1);
	}
	while ((*fmts)->width-- > 0)
		size += ft_putchar_rv((*fmts)->fillchr, 1);
	if ((*fmts)->fillchr == ' ')
	{
		size += ft_putchar_rv('0', 1);
		size += ft_putchar_rv('x', 1);
	}
	size += ft_putnbr_base_rv((*fmts)->p, 16, 1);
	return (size);
}

static int	ft_ptr_left_justified(t_fmts **fmts)
{
	int size;

	size = 0;
	size += ft_putchar_rv('0', 1);
	size += ft_putchar_rv('x', 1);
	size += ft_putnbr_base_rv((*fmts)->p, 16, 1);
	(*fmts)->width = (*fmts)->width - size;
	while ((*fmts)->width-- > 0 && ((*fmts)->fillchr = ' '))
		size += ft_putchar_rv((*fmts)->fillchr, 1);
	return (size);
}

int			ft_print_ptr(t_fmts *fmts)
{
	int d_size;

	d_size = ft_lennbr_base(fmts->p, 16);
	if (fmts->leftjust)
		return (ft_ptr_left_justified(&fmts));
	return (ft_ptr_right_justified(&fmts, d_size));
}
