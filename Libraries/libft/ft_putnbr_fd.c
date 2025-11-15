/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:35:37 by emarette          #+#    #+#             */
/*   Updated: 2025/10/23 21:49:43 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign = -sign;
		ft_putchar_fd('-', fd);
	}
	if (!(n / 10))
		ft_putchar_fd(n * sign + '0', fd);
	else
	{
		ft_putnbr_fd((n / 10) * sign, fd);
		ft_putnbr_fd((n % 10) * sign, fd);
	}
}
