/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:46:51 by emarette          #+#    #+#             */
/*   Updated: 2025/10/30 02:01:35 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -sign;
		i += ft_putchar('-');
	}
	if (n / 10)
	{
		i += ft_putnbr((n / 10) * sign);
		i += ft_putnbr((n % 10) * sign);
	}
	else
		i += ft_putchar(n * sign + '0');
	return (i);
}
