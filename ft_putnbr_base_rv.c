/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_rv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 22:36:20 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/20 22:36:22 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putprefix(int n, int base, int fd)
{
	if (n >= 0 && n <= base)
	{
		if (base == 8)
			write(fd, "0", 1);
		if (base == 16)
			write(fd, "0x", 2);
	}
	if (n < 0 && n > -base)
	{
		if (base == 8)
			write(fd, "-0", 2);
		if (base == 16)
			write(fd, "-0x", 3);
		if (base == 10)
			write(fd, "-", 1);
		return (1);
	}
	return (0);
}

int			ft_putnbr_base_rv(int n, int base, int fd)
{
	static int size = 0;

	size += ft_putprefix(n, base, fd);
	if (n / base != 0)
		ft_putnbr_base_rv(n / base, base, fd);
	if (base == 10)
		write(fd, &DEC[n % base * (n < 0 ? -1 : 1)], 1);
	if (base == 8)
		write(fd, &OCT[n % base * (n < 0 ? -1 : 1)], 1);
	if (base == 16)
		write(fd, &HEX[n % base * (n < 0 ? -1 : 1)], 1);
	size++;
	if (base == 16)
		return (size + 2);
	if (base == 8)
		return (size + 1);
	return (size);
}
