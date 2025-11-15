/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:50:43 by emarette          #+#    #+#             */
/*   Updated: 2025/10/28 23:04:14 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n / 10)
	{
		i += ft_putunbr((n / 10));
		i += ft_putunbr((n % 10));
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}
