/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:42:21 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/20 15:38:14 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_doprint(t_fmts *fmts)
{
	int size;

	size = 0;
	if (fmts->type == 'd')
		size = ft_print_int(fmts);
	if (fmts->type == 'c')
		size = ft_print_char(fmts);
	return (size);
}
