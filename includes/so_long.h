/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarette <emarette@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 23:57:21 by emarette          #+#    #+#             */
/*   Updated: 2025/11/17 23:57:21 by emarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42.h"
# include "ft_dprintf.h"
# include "get_next_line.h"
# include "libft.h"
# include <stdio.h>

typedef struct s_nelem
{
	int	n_row;
	int	n_col;
	int	n_c;
	int	n_e;
	int	n_p;
	int	x_p;
	int	y_p;
	int	d_c;
	int	d_e;
}	t_nelem;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img_wall;
	mlx_image_t	*img_floor;
	mlx_image_t	*img_player;
	mlx_image_t	*img_exit;
	mlx_image_t	*img_collect;
	char		**map;
	int			width;
	int			height;
	int			player_x;
	int			player_y;
	int			collectibles;
	int			collected;
	int			n_step;
}	t_game;

// init_map.c
char	**ft_init_map(char *filename);
int		ft_row_count(char *filename);

// check_error.c
int		is_surrounded(char **map, t_nelem *n_elem);
int		check_error(char **map, t_game *game);
int		count_elem(char **map, t_nelem *n_elem);
void	init_nelem(t_nelem *n_elem);
int		is_rectangular(char **map, t_nelem *n_elem);

// chaeck_path.c
int		check_path(t_nelem *n_elem, char **map);
void	free_visited_map(char **visited, int height);
char	**strdup_map(char **map, int height);
void	move_test_c(t_nelem *n_elem, char **map, char **visited, int *xy);
void	move_test_e(t_nelem *n_elem, char **map, char **visited, int *xy);

// init_window.c
int		init_window(t_game *game);
int		init_images(t_game *game);
void	draw_map(t_game *game);
int		texture(t_game *game, mlx_image_t **img, char *path);

// hook.c
void	key_hook(mlx_key_data_t keycode, void *param);
void	init_hooks(t_game *game);

// close.c
void	close_game(void *param);
void	free_images(t_game *game);
void	free_map(t_game *game);

// gameplay.c
int		conditions_move_y(t_game *game, char *dir);
int		conditions_move_x(t_game *game, char *dir);
void	move_player(t_game *game, char *dir);

#endif
