#include "so_long.h"
void ft_free_map(char **map)
{
	int i;

	i=0;
	while(map[i])
		free(map[i++]);
	free(map);
}

int main(int argc, char **argv)
{
	t_game game;
     
    if (argc != 2)
        return -1;
    game.map = ft_init_map(argv[1]);
    if (!game.map)
        return (-1);
    if (check_error(game.map) == -1)
		ft_printf("invalid map \n");
    return (ft_free_map(game.map), 0);
}