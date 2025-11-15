/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:27:16 by emarette          #+#    #+#             */
/*   Updated: 2025/10/23 21:49:33 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char		*a;
	const unsigned char	*b;
	int					i;

	i = 0;
	a = (unsigned char *)dest;
	b = (const unsigned char *)src;
	if (a == 0 && b == 0)
		return (0);
	while (size > 0)
	{
		a[i] = b[i];
		size--;
		i++;
	}
	return (a);
}
