/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_rv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 22:36:20 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/23 16:57:54 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_putnbr_base_rv(size_t n, int base, int fd)
{
	int size;

	size = 0;
	if (n / base != 0)
		size += ft_putnbr_base_rv(n / base, base, fd);
	if (base == 10)
		size += write(fd, &DEC[n % base * (n < 0 ? -1 : 1)], 1);
	if (base == 8)
		size += write(fd, &OCT[n % base * (n < 0 ? -1 : 1)], 1);
	if (base == 16)
		size += write(fd, &HEX[n % base * (n < 0 ? -1 : 1)], 1);
	return (size);
}
