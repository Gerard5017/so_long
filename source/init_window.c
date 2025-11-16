#include "so_long.h"

void draw_map(t_game *game)
{
    int row;
    int col;

    row = 0;
    while (row < game->height)
    {
        col =0;
        while (col < game->width)
        {
            if (game->map[row][col] == '1')
                mlx_image_to_window(game->mlx, game->img_wall, col * 64, row * 64);
            else if (game->map[row][col] == '0')
                mlx_image_to_window(game->mlx, game->img_floor, col * 64, row * 64);
            else if (game->map[row][col] == 'P')
                mlx_image_to_window(game->mlx, game->img_player, col * 64, row * 64);
            else if (game->map[row][col] == 'C')
                mlx_image_to_window(game->mlx, game->img_collect, col * 64, row * 64);
            else if (game->map[row][col] == 'E')
                mlx_image_to_window(game->mlx, game->img_exit, col * 64, row * 64);
            col++;
        }
        row++;
    }
}

int init_images(t_game *game)
{
    mlx_texture_t *tx;

    tx = mlx_load_png("textures/wall.png");
    if (!tx)
        return (-1);
    game->img_wall = mlx_texture_to_image(game->mlx, tx);
    mlx_delete_texture(tx);
    tx = mlx_load_png("textures/floor.png");
    if (!tx)
        return (-1);
    game->img_floor = mlx_texture_to_image(game->mlx, tx);
    mlx_delete_texture(tx);
    tx = mlx_load_png("textures/player.png");
    if (!tx)
        return (-1);
    game->img_player = mlx_texture_to_image(game->mlx, tx);
    mlx_delete_texture(tx);
    tx = mlx_load_png("textures/collect.png");
    if (!tx)
        return (-1);
    game->img_collect = mlx_texture_to_image(game->mlx, tx);
    mlx_delete_texture(tx);
    tx = mlx_load_png("textures/exit.png");
    if (!tx)
        return (-1);
    game->img_exit = mlx_texture_to_image(game->mlx, tx);
    mlx_delete_texture(tx);

    if (!game->img_wall || !game->img_floor || !game->img_player
        || !game->img_collect || !game->img_exit)
        return (-1);
    return (1);
}

int init_window(t_game *game)
{
    game->mlx = mlx_init(game->width*64,game->height*64, "So_long", false);
    if (!game->mlx)
        return (-1);
    if (init_images(game) < 0)
            return (-1);
    draw_map(game);
    mlx_loop(game->mlx);
    return 1;
}