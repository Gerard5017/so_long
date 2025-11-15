/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:48:54 by emarette          #+#    #+#             */
/*   Updated: 2025/10/30 04:34:04 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long int n)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	if (n / 16)
	{
		i += ft_puthex((n / 16));
		i += ft_puthex((n % 16));
	}
	else
		i += ft_putchar(base[n]);
	return (i);
}

int	ft_putaddress(void *ptr)
{
	int	i;

	i = 0;
	if (ptr == NULL)
		i += ft_putstr("(nil)");
	else
	{
		i += ft_putstr("0x");
		i += ft_puthex((unsigned long int)ptr);
	}
	return (i);
}

// int	main(void)
// {
// 	char	*ptr;

// 	ptr = "hnruhjijmc sxsokxs";
// 	printf("\n%d", ft_putaddress(ptr));
// 	printf("\n%p", ptr);
// }
