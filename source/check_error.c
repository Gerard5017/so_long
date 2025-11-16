#include "so_long.h"

int is_surrounded(char **map, t_nelem *n_elem)
{
    int row;
    int col;

    row = -1;
    col = -1;
    while (map[0][++col])
        if (map[0][col] != '1')
            return -1;
    while (++row < n_elem->n_row)
        if (map[row][0] != '1' || map[row][col-1] != '1')
            return -1;
    col = -1;
    while (map[(n_elem->n_row)-1][++col])
        if (map[(n_elem->n_row)-1][col] != '1')
            return -1;
    return 1;
}

int is_rectangular(char **map, t_nelem *n_elem)
{
    int row;
    int col;

    row = 0;
    while (map[row])
    {
        col = 0;
        while (map[row][col])
            col++;
        if (col != n_elem->n_col)
            return -1;
        row++;
    }
    return 1;
}

void init_nelem(t_nelem *n_elem)
{
    n_elem->n_row = 0;
    n_elem->n_col = 0;
    n_elem->n_C = 0;
    n_elem->n_E = 0;
    n_elem->n_P = 0;
    n_elem->x_P = 0;
    n_elem->y_P = 0;
;}

int count_elem(char **map, t_nelem *n_elem)
{
    int col;
    
    init_nelem(n_elem);
    while (map[n_elem->n_row])
    {
        col = 0;
        while (map[n_elem->n_row][col])
        {
            if (map[n_elem->n_row][col] == 'C')
                n_elem->n_C += 1;
            else if (map[n_elem->n_row][col] == 'E')
                n_elem->n_E += 1;
            else if (map[n_elem->n_row][col] == 'P')
            {
                n_elem->n_P += 1;
                n_elem->x_P = col;
                n_elem->y_P = n_elem->n_row;
            }
            else if (map[n_elem->n_row][col] == '0' || map[n_elem->n_row][col] == '1')
                ;
            else
                return (ft_printf("row %d; col %d; char %c \n",n_elem->n_row+1, col+1, map[n_elem->n_row][col]),-1);
            col++;
        }
        if (n_elem->n_row == 0)
            n_elem->n_col = col;
        n_elem->n_row++;
    }
    return (1);
}

int check_error(char **map, t_game *game)
{
    t_nelem n_elem;

    if (count_elem(map, &n_elem) == -1)
        return(ft_printf("Invalid Character in the Map\n"),-1);
    if (n_elem.n_C < 1)
        return(ft_printf("Number of C is Invalid \n"),-1);
    if (n_elem.n_E != 1)
        return(ft_printf("Number of E is Invalid \n"),-1);
    if (n_elem.n_P != 1)
        return(ft_printf("Number of P is Invalid \n"),-1);
    if (is_rectangular(map,&n_elem) == -1)
        return(ft_printf("Map must be Rectangular \n"),-1);
    if (is_surrounded(map,&n_elem) == -1)
        return(ft_printf("Map must be Surrounded by 1 \n"),-1);
    game->width = n_elem.n_col;
    game->height = n_elem.n_row;
    game->player_x = n_elem.x_P;
    game->player_y = n_elem.y_P;
    game->collectibles = n_elem.n_C;
    game->collected = 0;
    return 1;
}