/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 10:33:07 by daniel            #+#    #+#             */
/*   Updated: 2026/06/20 10:33:28 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int n, char *base)
{
	long	numb;
	int		count;

	numb = n;
	count = 0;
	if (numb >= 16)
	{
		count += ft_putnbr_hex(numb / 16, base);
	}
	count += ft_putchar_fd_pf(base[numb % 16], 1);
	return (count);
}
