/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 04:27:41 by lsellier          #+#    #+#             */
/*   Updated: 2025/11/18 01:47:08 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		results;
	int		i;

	i = 0;
	results = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			results += ft_dselect(*(format + i + 1), args, fd);
			++i;
		}
		else
			results += ft_dputchar(format[i], fd);
		++i;
	}
	va_end(args);
	return (results);
}
