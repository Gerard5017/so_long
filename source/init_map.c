/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:57:00 by emarette          #+#    #+#             */
/*   Updated: 2025/11/16 21:57:00 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_row_count(char *filename)
{
	int		fd;
	int		row_count;
	char	*line;

	row_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		row_count++;
	}
	return (close(fd), row_count);
}

char	**ft_init_map(char *filename)
{
	char	**map;
	char	*line;
	int		fd;
	int		row_count;
	int		i;

	row_count = ft_row_count(filename);
	if (row_count == -1)
		return (NULL);
	map = malloc(sizeof(char *) * (row_count + 1));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(map), NULL);
	i = 0;
	while (i < row_count)
	{
		line = get_next_line(fd);
		map[i++] = ft_strtrim(line, "\r\n");
		free(line);
	}
	return (map[i] = NULL, close(fd), map);
}
