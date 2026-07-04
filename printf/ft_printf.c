/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 10:10:36 by daniel            #+#    #+#             */
/*   Updated: 2026/06/20 10:10:50 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg_list;
	size_t	i;
	size_t	count;

	if (!format)
		return (-1);
	va_start(arg_list, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += ft_conversion(format[i + 1], arg_list);
			i++;
		}
		else
		{
			ft_putchar_fd_pf(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(arg_list);
	return ((int)count);
}
