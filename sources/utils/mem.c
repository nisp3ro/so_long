#include "../../includes/so_long.h"

/**
 * @brief Frees the memory allocated for the map and its buffer.
 *
 * Iterates through each row of the map and the corresponding map buffer,
 * freeing the allocated memory. Finally, frees the arrays that hold the map
 * and the map buffer.
 *
 * @param c Pointer to the map structure.
 */
void free_map(t_map *c)
{
    int i;

    i = 0;
    while (c->map && i <= c->mlen)
    {
        free(c->map[i]);
        free(c->map_buffer[i]);
        i++;
    }
    free(c->map);
    free(c->map_buffer);
}

/**
 * @brief Frees all allocated memory for the game.
 *
 * Frees the memory allocated for the map, monster coordinates and facing direction,
 * as well as the player, monster, and texture structures.
 *
 * @param data Pointer to the game data structure.
 */
void free_game(t_data *data)
{
    free_map(data->map);
    free(data->monster->x);
    free(data->monster->y);
    free(data->monster->facing);
    free(data->map);
    free(data->player);
    free(data->monster);
    free(data->texture);
}

/**
 * @brief Allocates memory for monster data.
 *
 * Allocates memory for the x and y coordinates and facing direction array of the monsters,
 * based on the total count of monsters. It then initializes each monster's facing direction
 * to the initial facing value.
 *
 * @param data Pointer to the game data structure.
 */
void mem_monster(t_data *data)
{
    int i;

    i = 0;
    data->monster->x = ft_calloc((data->map->m_count), sizeof(int));
    if (!data->monster->x)
        exit(EXIT_FAILURE);
    data->monster->y = ft_calloc((data->map->m_count), sizeof(int));
    if (!data->monster->y)
        exit(EXIT_FAILURE);
    data->monster->facing = ft_calloc((data->map->m_count), sizeof(char));
    if (!data->monster->facing)
        exit(EXIT_FAILURE);
    while (i < data->map->m_count)
    {
        data->monster->facing[i] = data->monster->init_facing;
        i++;
    }
}

/**
 * @brief Appends the current line to the map's read buffer.
 *
 * If no read buffer exists, duplicates the current line.
 * Otherwise, concatenates the current line to the existing buffer.
 * Finally, frees the current line memory.
 *
 * @param c Pointer to the map structure.
 */
void mem_map_buffer(t_map *c)
{
    char *temp;

    if (c->readedmap == NULL)
    {
        c->readedmap = ft_strdup(c->line);
        if (!c->readedmap)
            exit(EXIT_FAILURE);
    }
    else
    {
        temp = ft_strdup(c->readedmap);
        if (!temp)
            exit(EXIT_FAILURE);
        free(c->readedmap);
        c->readedmap = ft_strjoin(temp, c->line);
        if (!c->readedmap)
            exit(EXIT_FAILURE);
        free(temp);
    }
    free(c->line);
}

/**
 * @brief Allocates memory for the map and map buffer.
 *
 * Splits the read buffer into a map array and a map buffer array using the newline
 * character as a delimiter. Frees the read buffer after allocation.
 *
 * @param c Pointer to the map structure.
 */
void mem_alloc(t_map *c)
{
    c->map = ft_split(c->readedmap, '\n');
    if (!c->map)
        exit(EXIT_FAILURE);
    c->map_buffer = ft_split(c->readedmap, '\n');
    if (!c->map_buffer)
        exit(EXIT_FAILURE);
    free(c->readedmap);
}
