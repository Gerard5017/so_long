/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:04:06 by emarette          #+#    #+#             */
/*   Updated: 2025/11/18 01:28:59 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
		game->map = NULL;
	}
}

void	free_images(t_game *game)
{
	if (game->mlx)
	{
		if (game->img_collect)
			mlx_delete_image(game->mlx, game->img_collect);
		if (game->img_player)
			mlx_delete_image(game->mlx, game->img_player);
		if (game->img_exit)
			mlx_delete_image(game->mlx, game->img_exit);
		if (game->img_wall)
			mlx_delete_image(game->mlx, game->img_wall);
		if (game->img_floor)
			mlx_delete_image(game->mlx, game->img_floor);
	}
}

void	close_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (!game)
		exit (0);
	free_images(game);
	free_map(game);
	if (game->mlx)
	{
		mlx_terminate(game->mlx);
		game->mlx = NULL;
	}
	ft_dprintf(1, "Close Of The Game\n");
	exit (0);
}
