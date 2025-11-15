/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:49:07 by emarette          #+#    #+#             */
/*   Updated: 2025/10/30 04:45:24 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <ctype.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

// function put
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putaddress(void *ptr);
int	ft_puthex(unsigned long int n);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_puthex_lower(unsigned int n);
int	ft_puthex_upper(unsigned int n);
int	ft_putpercent(void);

// other function
int	ft_isformat(char c);
int	ft_putformat(char format, va_list arg);
int	ft_printf(const char *str, ...);

#endif
