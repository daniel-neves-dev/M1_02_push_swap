/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 10:35:19 by daniel            #+#    #+#             */
/*   Updated: 2026/06/20 10:35:27 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_uns(unsigned int n, int fd)
{
	unsigned long	numb;
	int				count;

	numb = n;
	count = 0;
	if (numb > 9)
	{
		count += ft_putnbr_uns(numb / 10, fd);
	}
	count += ft_putchar_fd_pf(numb % 10 + '0', fd);
	return (count);
}
