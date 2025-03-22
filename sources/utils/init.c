#include "../../includes/so_long.h"

/**
 * @brief Initializes the map structure with default values.
 *
 * Sets all the counters, dimensions, and file descriptors in the map structure to
 * their initial values. Also sets pointers and starting positions to their default states.
 *
 * @param init Pointer to the game data structure.
 */
void init_map(t_data *init)
{
    init->map->e_count = 0;
    init->map->p_count = 0;
    init->map->c_count = 0;
    init->map->m_count = 0;
    init->map->e_found = 0;
    init->map->c_found = 0;
    init->map->mlen = 0;
    init->map->current_col = 0;
    init->map->len = 0;
    init->map->fd = 0;
    init->map->fdmap = 0;
    init->map->row = 0;
    init->map->col = 0;
    init->map->start_row = -1;
    init->map->start_col = -1;
    init->map->error_flag = 0;
    init->map->line = NULL;
    init->map->readedmap = NULL;
}

/**
 * @brief Initializes general game variables.
 *
 * Calls init_map() to initialize the map structure, then sets the player's starting
 * position, movement count, score, win status, and facing direction. Also initializes
 * monster and texture parameters.
 *
 * @param init Pointer to the game data structure.
 */
void init_vars(t_data *init)
{
    init_map(init);
    init->player->x = 0;
    init->player->y = 0;
    init->player->moves = 0;
    init->player->score = 0;
    init->player->win = 0;
    init->player->facing = 'L';
    init->monster->num = 0;
    init->monster->count = 0;
    init->monster->idle_time = 0;
    init->monster->init_facing = 'R';
    init->texture->keyframe = 0;
}

/**
 * @brief Allocates memory for the core game structures.
 *
 * Dynamically allocates memory for the map, player, monster, and texture structures.
 * Exits the program if any allocation fails.
 *
 * @param data Pointer to the game data structure.
 */
void init_struct_pointers(t_data *data)
{
    data->map = ft_calloc(1, sizeof(t_map));
    if (!data->map)
        exit(EXIT_FAILURE);
    data->player = ft_calloc(1, sizeof(t_player));
    if (!data->player)
        exit(EXIT_FAILURE);
    data->monster = ft_calloc(1, sizeof(t_monster));
    if (!data->monster)
        exit(EXIT_FAILURE);
    data->texture = ft_calloc(1, sizeof(t_texture));
    if (!data->texture)
        exit(EXIT_FAILURE);
}

/**
 * @brief Initializes the player's starting coordinates.
 *
 * Scans the map for the player character ('P'). When found, sets the player's coordinates,
 * as well as the starting row and column in the map structure.
 *
 * @param c Pointer to the map structure.
 * @param p Pointer to the player structure.
 * @param row The starting row index for scanning.
 * @param col The starting column index for scanning.
 * @return int Returns 1 if the player is found, otherwise returns 0.
 */
int init_player_coords(t_map *c, t_player *p, int row, int col)
{
    while (row < c->mlen)
    {
        col = 0;
        while (col < c->len)
        {
            if (c->map[row][col] == 'P')
            {
                p->y = row;
                p->x = col;
                c->start_row = row;
                c->start_col = col;
                return (1);
            }
            col++;
        }
        row++;
    }
    return (0);
}

/**
 * @brief Initializes the coordinates for all monsters on the map.
 *
 * Scans the entire map to find all monster characters ('M') and stores their coordinates
 * in the monster structure arrays.
 *
 * @param c Pointer to the map structure.
 * @param mon Pointer to the monster structure.
 */
void init_monster_coords(t_map *c, t_monster *mon)
{
    int num;
    int row;
    int col;

    num = 0;
    while (num != c->m_count)
    {
        row = 0;
        while (row < c->mlen && num < c->m_count)
        {
            col = 0;
            while (col < c->len)
            {
                if (c->map[row][col] == 'M')
                {
                    mon->y[num] = row;
                    mon->x[num] = col;
                    num++;
                }
                col++;
            }
            row++;
        }
    }
}
