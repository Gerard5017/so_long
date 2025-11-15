/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:48:49 by emarette          #+#    #+#             */
/*   Updated: 2025/10/30 04:32:14 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_lower(unsigned int n)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	if (n / 16)
	{
		i += ft_puthex_lower((n / 16));
		i += ft_puthex_lower((n % 16));
	}
	else
		i += ft_putchar(base[n]);
	return (i);
}

int	ft_puthex_upper(unsigned int n)
{
	char	*base;
	int		i;

	base = "0123456789ABCDEF";
	i = 0;
	if (n / 16)
	{
		i += ft_puthex_upper((n / 16));
		i += ft_puthex_upper((n % 16));
	}
	else
		i += ft_putchar(base[n]);
	return (i);
}
