/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 23:14:47 by emarette          #+#    #+#             */
/*   Updated: 2025/11/16 23:14:47 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *game)
{
	int	r;
	int	c;

	r = -1;
	while (++r < game->height)
	{
		c = -1;
		while (++c < game->width)
		{
			mlx_image_to_window(game->mlx, game->img_floor, c * 64, r * 64);
			if (game->map[r][c] == '1')
				mlx_image_to_window(game->mlx, game->img_wall, c * 64, r * 64);
			else if (game->map[r][c] == 'P')
				mlx_image_to_window(game->mlx, game->img_player, c * 64, r
					* 64);
			else if (game->map[r][c] == 'C')
				mlx_image_to_window(game->mlx, game->img_collect, c * 64, r
					* 64);
			else if (game->map[r][c] == 'E')
				mlx_image_to_window(game->mlx, game->img_exit, c * 64, r * 64);
		}
	}
}

int	texture(t_game *game, mlx_image_t **img, char *path)
{
	mlx_texture_t	*tx;

	tx = mlx_load_png(path);
	if (!tx)
		return (-1);
	*img = mlx_texture_to_image(game->mlx, tx);
	mlx_delete_texture(tx);
	if (!*img)
		return (-1);
	return (1);
}

int	init_images(t_game *game)
{
	if (texture(game, &game->img_wall, "textures/wall.png") < 0)
		return (-1);
	if (texture(game, &game->img_floor, "textures/floor.png") < 0)
		return (-1);
	if (texture(game, &game->img_player, "textures/player.png") < 0)
		return (-1);
	if (texture(game, &game->img_collect, "textures/collect.png") < 0)
		return (-1);
	if (texture(game, &game->img_exit, "textures/exit.png") < 0)
		return (-1);
	return (1);
}

int	init_window(t_game *game)
{
	game->mlx = mlx_init(game->width * 64, game->height * 64, "So_long",
			false);
	if (!game->mlx)
		return (-1);
	if (init_images(game) == -1)
		return (-1);
	draw_map(game);
	init_hooks(game);
	mlx_loop(game->mlx);
	free_images(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free_map(game);
	return (1);
}
