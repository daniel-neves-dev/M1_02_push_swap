/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 10:35:51 by daniel            #+#    #+#             */
/*   Updated: 2026/06/20 10:36:05 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd_pf(char *s, int fd)
{
	int	count;

	count = 0;
	if (fd < 0)
		return (0);
	if (!s)
	{
		s = "(null)";
	}
	while (*s)
	{
		ft_putchar_fd_pf(*s, fd);
		s++;
		count++;
	}
	return (count);
}
