/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dneves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 09:58:24 by dneves-d          #+#    #+#             */
/*   Updated: 2026/06/20 09:58:28 by dneves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_conversion(char conv, va_list arg_list)
{
	size_t	count;

	count = 0;
	if (conv == 'c')
		count = ft_putchar_fd_pf(va_arg(arg_list, int), 1);
	else if (conv == 's')
		count = ft_putstr_fd_pf(va_arg(arg_list, char *), 1);
	else if (conv == 'd' || conv == 'i')
		count = ft_putnbr_fd_pf(va_arg(arg_list, int), 1);
	else if (conv == 'u')
		count = ft_putnbr_uns(va_arg(arg_list, unsigned int), 1);
	else if (conv == 'p')
		count = ft_putnbr_mem(va_arg(arg_list, void *), "0123456789abcdef");
	else if (conv == 'x')
		count = ft_putnbr_hex(va_arg(arg_list, unsigned int),
				"0123456789abcdef");
	else if (conv == 'X')
		count = ft_putnbr_hex(va_arg(arg_list, unsigned int),
				"0123456789ABCDEF");
	else if (conv == '%')
		count = ft_putchar_fd_pf('%', 1);
	return (count);
}
