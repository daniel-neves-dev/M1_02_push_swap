/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_mem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 10:33:42 by daniel            #+#    #+#             */
/*   Updated: 2026/06/20 10:34:08 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_hex(unsigned long long n, char *base)
{
	int		count;

	count = 0;
	if (n >= 16)
	{
		count += ft_convert_hex(n / 16, base);
	}
	count += ft_putchar_fd_pf(base[n % 16], 1);
	return (count);
}

int	ft_putnbr_mem(void *ptr, char *base)
{
	int					count;
	unsigned long long	number;

	count = 0;
	if (!ptr)
		return (ft_putstr_fd_pf("(nil)", 1));
	number = (unsigned long long)ptr;
	count += ft_putstr_fd_pf("0x", 1);
	count += ft_convert_hex(number, base);
	return (count);
}
