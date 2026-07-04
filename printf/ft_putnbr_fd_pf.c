/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 10:32:35 by daniel            #+#    #+#             */
/*   Updated: 2026/06/20 10:32:43 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd_pf(int n, int fd)
{
	long	numb;
	int		count;

	numb = n;
	count = 0;
	if (numb < 0)
	{
		numb = -numb;
		ft_putchar_fd_pf('-', fd);
		count += 1;
	}
	if (numb > 9)
	{
		count += ft_putnbr_fd_pf(numb / 10, fd);
	}
	count += ft_putchar_fd_pf(numb % 10 + '0', fd);
	return (count);
}
