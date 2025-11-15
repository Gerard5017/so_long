/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:43:44 by emarette          #+#    #+#             */
/*   Updated: 2025/10/23 21:50:18 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (0[little] == '\0')
		return ((char *)big);
	while (i[big] && len > i)
	{
		j = 0;
		while (j[little] == (i + j)[big] && i + j < len)
		{
			j++;
			if (!j[little])
				return ((char *)&i[big]);
		}
		i++;
	}
	return (0);
}
