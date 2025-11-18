/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:57:03 by emarette          #+#    #+#             */
/*   Updated: 2025/11/16 21:57:03 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	i_need_place(t_nelem *n_elem, int col)
{
	n_elem->n_p += 1;
	n_elem->x_p = col;
	n_elem->y_p = n_elem->n_row;
}

int	is_surrounded(char **map, t_nelem *n_elem)
{
	int	row;
	int	col;

	row = -1;
	col = -1;
	while (map[0][++col])
		if (map[0][col] != '1')
			return (-1);
	while (++row < n_elem->n_row)
		if (map[row][0] != '1' || map[row][col - 1] != '1')
			return (-1);
	col = -1;
	while (map[(n_elem->n_row) - 1][++col])
		if (map[(n_elem->n_row) - 1][col] != '1')
			return (-1);
	return (1);
}

int	is_rectangular(char **map, t_nelem *n_elem)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
			col++;
		if (col != n_elem->n_col)
			return (-1);
		row++;
	}
	return (1);
}

int	count_elem(char **map, t_nelem *n_elem)
{
	int	col;

	ft_bzero(n_elem, sizeof(t_nelem));
	while (map[n_elem->n_row])
	{
		col = -1;
		while (map[n_elem->n_row][++col])
		{
			if (map[n_elem->n_row][col] == 'C')
				n_elem->n_c += 1;
			else if (map[n_elem->n_row][col] == 'E')
				n_elem->n_e += 1;
			else if (map[n_elem->n_row][col] == 'P')
			{
				i_need_place(n_elem, col);
			}
			else if (!(map[n_elem->n_row][col] == '0'
				|| map[n_elem->n_row][col] == '1'))
				return (-1);
		}
		if (n_elem->n_row == 0)
			n_elem->n_col = col;
		n_elem->n_row++;
	}
	return (1);
}

int	check_error(char **map, t_game *game)
{
	t_nelem	n_elem;

	if (count_elem(map, &n_elem) == -1)
		return (ft_dprintf(2, "ERROR : Invalid Character In The Map\n"), -1);
	game->width = n_elem.n_col;
	game->height = n_elem.n_row;
	game->player_x = n_elem.x_p;
	game->player_y = n_elem.y_p;
	game->collectibles = n_elem.n_c;
	game->collected = 0;
	if (n_elem.n_c < 1)
		return (ft_dprintf(2, "ERROR : Number Of 'C' Is Invalid \n"), -1);
	if (n_elem.n_e != 1)
		return (ft_dprintf(2, "ERROR : Number Of 'E' Is Invalid \n"), -1);
	if (n_elem.n_p != 1)
		return (ft_dprintf(2, "ERROR : Number Of 'P' Is Invalid \n"), -1);
	if (is_rectangular(map, &n_elem) == -1)
		return (ft_dprintf(2, "ERROR : Map Must Be Rectangular \n"), -1);
	if (is_surrounded(map, &n_elem) == -1)
		return (ft_dprintf(2, "ERROR : Map Must be Surrounded by 1 \n"), -1);
	if (check_path(&n_elem, map) == -1)
		return (ft_dprintf(2, "ERROR : No Path Possible\n"), -1);
	return (1);
}
