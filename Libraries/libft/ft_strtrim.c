/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 02:49:23 by emarette          #+#    #+#             */
/*   Updated: 2025/10/23 21:03:31 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i++;
	return (dest);
}

static int	check_charset(char c, const char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *charset)
{
	char		*s2;
	const char	*fin;
	size_t		len;

	while (*s1 && check_charset(*s1, charset) == 1)
		s1++;
	fin = s1 + ft_strlen(s1);
	while (fin > s1 && check_charset(*(fin - 1), charset) == 1)
		fin--;
	len = fin - s1;
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	ft_strncpy(s2, s1, len);
	s2[len] = '\0';
	return (s2);
}
