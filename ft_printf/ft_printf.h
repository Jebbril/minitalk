/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:40:56 by orakib            #+#    #+#             */
/*   Updated: 2022/12/29 14:26:01 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_atoi(const char *str);
int	ft_printf(const char *s, ...);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putunbr_fd(unsigned int n, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_puthex_fd(unsigned int n, int fd);
int	ft_puthexu_fd(unsigned int n, int fd);
int	ft_putadr_fd(uintptr_t n, int fd);

#endif
