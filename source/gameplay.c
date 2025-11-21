/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:53:22 by emarette          #+#    #+#             */
/*   Updated: 2025/11/21 23:45:40 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	crush_tile(t_game *game, int next_y, int next_x)
{
	char	next_tile;

	next_tile = game->map[next_y][next_x];
	if (next_tile == 'C')
		game->collected++;
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = next_x;
	game->player_y = next_y;
	game->map[game->player_y][game->player_x] = 'P';
	game->n_step++;
	ft_dprintf(1, "step :%d\n", game->n_step);
	draw_map(game);
}

void	move_player(t_game *game, char *dir)
{
	int		move_dir;
	int		next_x;
	int		next_y;

	next_x = game->player_x;
	next_y = game->player_y;
	move_dir = conditions_move_y(game, dir);
	if (move_dir == 0)
		move_dir = conditions_move_x(game, dir);
	if (move_dir == 0)
		return ;
	if (move_dir == 1)
		next_y -= 1;
	else if (move_dir == 2)
		next_y += 1;
	else if (move_dir == 3)
		next_x -= 1;
	else if (move_dir == 4)
		next_x += 1;
	else if (move_dir == 5)
	{
		ft_dprintf(1, "Congratulation You Have Won !!!\n");
		close_game(game);
	}
	crush_tile(game, next_y, next_x);
}

int	conditions_move_x(t_game *game, char *dir)
{
	char	next_tile;

	if (ft_strncmp(dir, "x-1", 3) == 0)
	{
		next_tile = game->map[game->player_y][game->player_x - 1];
		if (next_tile == '1')
			return (0);
		if (next_tile == 'E' && game->collectibles != game->collected)
			return (0);
		if (next_tile == 'E' && game->collectibles == game->collected)
			return (5);
		return (3);
	}
	if (ft_strncmp(dir, "x+1", 3) == 0)
	{
		next_tile = game->map[game->player_y][game->player_x + 1];
		if (next_tile == '1')
			return (0);
		if (next_tile == 'E' && game->collectibles != game->collected)
			return (0);
		if (next_tile == 'E' && game->collectibles == game->collected)
			return (5);
		return (4);
	}
	return (0);
}

int	conditions_move_y(t_game *game, char *dir)
{
	char	next_tile;

	if (ft_strncmp(dir, "y-1", 3) == 0)
	{
		next_tile = game->map[game->player_y - 1][game->player_x];
		if (next_tile == '1')
			return (0);
		if (next_tile == 'E' && game->collectibles != game->collected)
			return (0);
		if (next_tile == 'E' && game->collectibles == game->collected)
			return (5);
		return (1);
	}
	if (ft_strncmp(dir, "y+1", 3) == 0)
	{
		next_tile = game->map[game->player_y + 1][game->player_x];
		if (next_tile == '1')
			return (0);
		if (next_tile == 'E' && game->collectibles != game->collected)
			return (0);
		if (next_tile == 'E' && game->collectibles == game->collected)
			return (5);
		return (2);
	}
	return (0);
}
