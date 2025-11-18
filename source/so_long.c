/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 23:11:12 by emarette          #+#    #+#             */
/*   Updated: 2025/11/16 23:11:12 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || ft_strstr(argv[1], ".ber") == 0)
		return (ft_dprintf(2, "ERROR: Include File.ber In Parameter\n"), -1);
	ft_bzero(&game, sizeof(t_game));
	game.map = ft_init_map(argv[1]);
	if (!game.map)
		return (ft_dprintf(2, "ERROR: No Read Map\n"), -1);
	if (check_error(game.map, &game) == -1)
		return (ft_dprintf(2, "Invalid Map \n"), free_map(&game), -1);
	init_window(&game);
	return (0);
}
