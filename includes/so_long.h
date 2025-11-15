#ifndef SO_LONG_H
#define SO_LONG_H

#include "ft_printf.h"
#include "libft.h"
#include "get_next_line.h"
#include "MLX42.h"
#include <stdio.h>

typedef struct s_nelem
{
    int         n_row;
    int         n_col;
    int			n_C;
    int			n_E;
    int			n_P;
}					t_nelem;

typedef struct s_game
{
	mlx_t    *mlx;
    mlx_image_t *img_wall;
    mlx_image_t *img_floor;
    mlx_image_t *img_player;
    mlx_image_t *img_exit;
    mlx_image_t *img_collect;
    char **map;
    int width;
    int height;
    int player_x;
    int player_y;
    int collectibles;
    int collected;
}					t_game;

// init_map.c
char **ft_init_map(char *filename);
int ft_row_count(char *filename);

// check_error.c
int is_surrounded(char **map, t_nelem *n_elem);
int check_error(char **map);
int count_elem(char **map, t_nelem *n_elem);
void init_nelem(t_nelem *n_elem);
int is_rectangular(char **map, t_nelem *n_elem);

#endif