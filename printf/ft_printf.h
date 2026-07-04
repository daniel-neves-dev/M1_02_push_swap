/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 10:12:36 by dneves-d          #+#    #+#             */
/*   Updated: 2026/06/20 10:31:04 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);
int		ft_putchar_fd_pf(char c, int fd);
int		ft_putstr_fd_pf(char *s, int fd);
int		ft_putnbr_fd_pf(int n, int fd);
int		ft_putnbr_uns(unsigned int n, int fd);
int		ft_putnbr_hex(unsigned int n, char *base);
int		ft_putnbr_mem(void *n, char *base);
size_t	ft_conversion(char conv, va_list arg_list);

#endif
