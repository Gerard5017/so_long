/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 00:21:54 by emarette          #+#    #+#             */
/*   Updated: 2025/10/19 02:03:09 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copiereverse(char *temp, int i)
{
	char	*res;
	int		j;

	j = 0;
	res = malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (0);
	while (--i >= 0)
		res[j++] = temp[i];
	res[j] = '\0';
	return (res);
}

char	*ft_itoa(int nb)
{
	char	temp[12];
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if (nb < 0)
		sign *= -1;
	while (nb / 10)
	{
		temp[i++] = ((nb % 10) * sign + '0');
		nb /= 10;
	}
	temp[i++] = ((nb % 10) * sign + '0');
	if (sign < 0)
		temp[i++] = '-';
	return (copiereverse(temp, i));
}
