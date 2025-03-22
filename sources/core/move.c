#include "../../includes/so_long.h"

/**
 * @brief Moves the player upward.
 *
 * Updates the current cell based on its state (exit or normal cell) before moving.
 * Calls check_up() to handle collision and movement logic, then updates the player's new position:
 * if the new cell is an exit, marks it with 'X'; otherwise, marks it with 'P'.
 *
 * @param data Pointer to the game data structure.
 */
void move_up(t_data *data)
{
    if (data->map->map[data->player->y][data->player->x] == 'X')
        data->map->map[data->player->y][data->player->x] = 'E';
    else
        data->map->map[data->player->y][data->player->x] = '0';
    check_up(data);
    if (data->map->map[data->player->y][data->player->x] == 'E')
        data->map->map[data->player->y][data->player->x] = 'X';
    else
        data->map->map[data->player->y][data->player->x] = 'P';
}

/**
 * @brief Moves the player downward.
 *
 * Updates the current cell based on its state (exit or normal cell) before moving.
 * Calls check_down() to handle collision and movement logic, then updates the player's new position:
 * if the new cell is an exit, marks it with 'X'; otherwise, marks it with 'P'.
 *
 * @param data Pointer to the game data structure.
 */
void move_down(t_data *data)
{
    if (data->map->map[data->player->y][data->player->x] == 'X')
        data->map->map[data->player->y][data->player->x] = 'E';
    else
        data->map->map[data->player->y][data->player->x] = '0';
    check_down(data);
    if (data->map->map[data->player->y][data->player->x] == 'E')
        data->map->map[data->player->y][data->player->x] = 'X';
    else
        data->map->map[data->player->y][data->player->x] = 'P';
}

/**
 * @brief Moves the player to the left.
 *
 * Updates the current cell based on its state (exit or normal cell) before moving.
 * Calls check_left() to handle collision and movement logic, then updates the player's new position:
 * if the new cell is an exit, marks it with 'X'; otherwise, marks it with 'P'.
 *
 * @param data Pointer to the game data structure.
 */
void move_left(t_data *data)
{
    if (data->map->map[data->player->y][data->player->x] == 'X')
        data->map->map[data->player->y][data->player->x] = 'E';
    else
        data->map->map[data->player->y][data->player->x] = '0';
    check_left(data);
    if (data->map->map[data->player->y][data->player->x] == 'E')
        data->map->map[data->player->y][data->player->x] = 'X';
    else
        data->map->map[data->player->y][data->player->x] = 'P';
}

/**
 * @brief Moves the player to the right.
 *
 * Updates the current cell based on its state (exit or normal cell) before moving.
 * Calls check_right() to handle collision and movement logic, then updates the player's new position:
 * if the new cell is an exit, marks it with 'X'; otherwise, marks it with 'P'.
 *
 * @param data Pointer to the game data structure.
 */
void move_right(t_data *data)
{
    if (data->map->map[data->player->y][data->player->x] == 'X')
        data->map->map[data->player->y][data->player->x] = 'E';
    else
        data->map->map[data->player->y][data->player->x] = '0';
    check_right(data);
    if (data->map->map[data->player->y][data->player->x] == 'E')
        data->map->map[data->player->y][data->player->x] = 'X';
    else
        data->map->map[data->player->y][data->player->x] = 'P';
}
