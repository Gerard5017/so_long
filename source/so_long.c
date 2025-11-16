#include "so_long.h"
void ft_free_game(t_game *game)
{
    int i;

    i=0;
    while (game->map[i])
        free(game->map[i++]);
    free(game->map);
}

int main(int argc, char **argv)
{
	t_game game;
    
    game.map = NULL;
    if (argc != 2)
        return -1;
    game.map = ft_init_map(argv[1]);
    if (!game.map)
        return (ft_printf("no maps found\n"), -1);
    if (check_error(game.map,&game) == -1)
        return (ft_printf("invalid map \n"),ft_free_game(&game), -1);
    init_window(&game);
    return(ft_free_game(&game), 1);
}
