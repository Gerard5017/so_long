/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:17:36 by emarette          #+#    #+#             */
/*   Updated: 2025/10/23 21:01:49 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;

	while (*s == c)
		s++;
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (i);
}

static char	**ft_free_all(char **res)
{
	int	i;

	i = 0;
	if (!res)
		return (NULL);
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static char	**ft_split_1(char const *s, char **res, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (s[i + j] != c && s[i + j])
				j++;
			res[k] = ft_substr(s, i, j);
			if (!(res[k++]))
				return (ft_free_all(res));
			i += j;
		}
	}
	return (res[k] = 0, res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = malloc((count_word((char *)s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	return (ft_split_1(s, res, c));
}
