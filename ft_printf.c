/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:22:16 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/19 22:28:39 by thjonell         ###   ########.fr       */
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

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
		{
			ft_putchar_fd(*fmt, 1);
			fmt++;
		}
		else
		{
			ft_parse_and_print(++fmt, &ap);
			while (!ft_strchr(TYPES, *fmt))
				fmt++;
			fmt++;
		}
	}
	va_end(ap);
	return (0);
}


