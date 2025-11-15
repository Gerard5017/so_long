/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:03:15 by emarette          #+#    #+#             */
/*   Updated: 2025/11/08 15:04:55 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_keep(char **keep)
{
	if (*keep)
		free(*keep);
	*keep = NULL;
	return (NULL);
}

static void	rest(char **keep, int i)
{
	char	*temp;

	if (!(*keep)[i])
		return (free_keep(keep), (void)0);
	temp = ft_strdup(*keep + i);
	if (!temp)
		return (free_keep(keep), (void)0);
	free(*keep);
	*keep = temp;
}

static char	*cutnewline(char **keep)
{
	char	*line;
	int		i;

	if (!*keep || !(*keep)[0])
		return (free_keep(keep));
	i = 0;
	while ((*keep)[i] && (*keep)[i] != '\n')
		i++;
	line = malloc(i + 1 + ((*keep)[i] == '\n'));
	if (!line)
		return (free_keep(keep));
	ft_strlcpy(line, *keep, i + 1);
	if ((*keep)[i] == '\n')
		line[i] = '\n';
	line[i + ((*keep)[i] == '\n')] = '\0';
	rest(keep, i + ((*keep)[i] == '\n'));
	return (line);
}

static int	read_line(char *buffer, char **keep, int fd)
{
	int		bytes_size;
	char	*temp;

	while (1)
	{
		bytes_size = read(fd, buffer, BUFFER_SIZE);
		if (bytes_size <= 0)
			break ;
		buffer[bytes_size] = '\0';
		if (!*keep)
			*keep = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(*keep, buffer);
			free(*keep);
			*keep = temp;
		}
		if (!*keep)
			return (-1);
		if (ft_strchr(*keep, '\n'))
			break ;
	}
	if (bytes_size == -1)
		return (-1);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*keep;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free_keep(&keep));
	if (read_line(buffer, &keep, fd) == -1)
		return (free(buffer), free_keep(&keep));
	return (free(buffer), cutnewline(&keep));
}

// int    main(void)
// {
// 	char    *s;
// 	int        fd;
// 	int        i;

// 	if (!(fd = open("text.txt", O_RDONLY)))
// 	{
// 		printf("Epic fail (fd open)\n");
// 		return (0);
// 	}
// 	i = 1;
// 	while ((s = get_next_line(fd)) && i < 100000)
// 	{
// 		printf("[i = %i] -> '%s'\n", i++, s);
// 		free (s);
// 	}
// 	close(fd);
// 	return (0);
// }
