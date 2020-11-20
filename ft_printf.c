/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:22:16 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/20 19:32:37 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
/*
 * получить и обработать строку
 */

/*
 * обработка строки: вывести все что до % обработать все что после %
 */

/*
 * обратбатываем данные: % флаг ширина точно размер тип
 */

int ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int 	size;

	size = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			size += ft_putchar_rv(*fmt++, 1);
		else
		{
			fmt++;
			size += ft_doparse_doprint(&fmt, &ap);
		}
	}
	va_end(ap);
	return (size);
}


