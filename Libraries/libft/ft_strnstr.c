/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:43:44 by emarette          #+#    #+#             */
/*   Updated: 2025/11/17 22:43:38 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (0[little] == '\0')
		return (0);
	while (i[big])
	{
		j = 0;
		while (j[little] == (i + j)[big])
		{
			j++;
			if (!j[little])
				return (1);
		}
		i++;
	}
	return (0);
}
