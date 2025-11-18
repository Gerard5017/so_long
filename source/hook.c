/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:34:11 by emarette          #+#    #+#             */
/*   Updated: 2025/11/18 01:29:53 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_hooks(t_game *game)
{
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_close_hook(game->mlx, close_game, game);
}

void	key_hook(mlx_key_data_t keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode.key == MLX_KEY_ESCAPE && keycode.action == MLX_PRESS)
		close_game(game);
	if (keycode.key == MLX_KEY_W && keycode.action == MLX_PRESS)
		move_player(game, "y-1");
	if (keycode.key == MLX_KEY_S && keycode.action == MLX_PRESS)
		move_player(game, "y+1");
	if (keycode.key == MLX_KEY_A && keycode.action == MLX_PRESS)
		move_player(game, "x-1");
	if (keycode.key == MLX_KEY_D && keycode.action == MLX_PRESS)
		move_player(game, "x+1");
}
