/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:57:06 by emarette          #+#    #+#             */
/*   Updated: 2025/11/18 01:23:46 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_test(t_nelem *n_elem, char **map, char **visited, int xy[2])
{
	int	x;
	int	y;

	x = xy[0];
	y = xy[1];
	if (x < 0 || x >= n_elem->n_col || y < 0 || y >= n_elem->n_row)
		return ;
	if (map[y][x] == '1' || visited[y][x] == '1')
		return ;
	visited[y][x] = '1';
	if (map[y][x] == 'C')
		n_elem->d_c++;
	if (map[y][x] == 'E')
		n_elem->d_e++;
	move_test(n_elem, map, visited, ((int []){xy[0] + 1, xy[1]}));
	move_test(n_elem, map, visited, ((int []){xy[0] - 1, xy[1]}));
	move_test(n_elem, map, visited, ((int []){xy[0], xy[1] + 1}));
	move_test(n_elem, map, visited, ((int []){xy[0], xy[1] - 1}));
}

char	**strdup_map(char **map, int height)
{
	int		i;
	char	**visited;

	i = 0;
	visited = malloc(sizeof(char *) * height);
	if (!visited)
		return (NULL);
	while (map[i])
	{
		visited[i] = ft_strdup(map[i]);
		i++;
	}
	return (visited);
}

void	free_visited_map(char **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(visited[i++]);
	free(visited);
}

int	check_path(t_nelem *n_elem, char **map)
{
	char	**visited;

	visited = strdup_map(map, n_elem->n_row);
	move_test(n_elem, map, visited, ((int []){n_elem->x_p, n_elem->y_p}));
	free_visited_map(visited, n_elem->n_row);
	if (n_elem->d_c == n_elem->n_c && n_elem->d_e == n_elem->n_e)
		return (1);
	return (-1);
}
