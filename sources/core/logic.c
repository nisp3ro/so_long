#include "../../includes/so_long.h"

/**
 * @brief Checks the current cell for unique elements.
 *
 * If the player is on a collectible ('C'), increases the score.
 * If the player is on a monster ('M'), triggers a loss and ends the game.
 *
 * @param data Pointer to the game data structure.
 */
void check_unique(t_data *data)
{
    if (data->map->map[data->player->y][data->player->x] == 'C')
    {
        data->player->score++;
    }
    else if (data->map->map[data->player->y][data->player->x] == 'M')
    {
        lose();
        game_destroy(data);
    }
    return;
}

/**
 * @brief Checks the tile above the player and processes movement.
 *
 * If the tile is a wall ('1'), no movement occurs.
 * If the tile is the exit ('E') and the player has collected all items,
 * the game ends with a victory.
 * Otherwise, the player moves up, the move count is incremented, and any unique
 * items are processed.
 *
 * @param data Pointer to the game data structure.
 */
void check_up(t_data *data)
{
    if (data->map->map[data->player->y - 1][data->player->x] == '1')
        return;
    else if (data->map->map[data->player->y - 1][data->player->x] == 'E')
    {
        if (data->player->win == 1)
        {
            data->player->moves++;
            ft_printf("Move #%i\n", data->player->moves);
            victory();
            game_destroy(data);
            return;
        }
    }
    data->player->y--;
    data->player->moves++;
    ft_printf("Move #%i\n", data->player->moves);
    check_unique(data);
    return;
}

/**
 * @brief Checks the tile below the player and processes movement.
 *
 * If the tile is a wall ('1'), no movement occurs.
 * If the tile is the exit ('E') and the player has collected all items,
 * the game ends with a victory.
 * Otherwise, the player moves down, the move count is incremented, and any unique
 * items are processed.
 *
 * @param data Pointer to the game data structure.
 */
void check_down(t_data *data)
{
    if (data->map->map[data->player->y + 1][data->player->x] == '1')
        return;
    else if (data->map->map[data->player->y + 1][data->player->x] == 'E')
    {
        if (data->player->win == 1)
        {
            data->player->moves++;
            ft_printf("Move #%i\n", data->player->moves);
            victory();
            game_destroy(data);
            return;
        }
    }
    data->player->y++;
    data->player->moves++;
    ft_printf("Move #%i\n", data->player->moves);
    check_unique(data);
    return;
}

/**
 * @brief Checks the tile to the left of the player and processes movement.
 *
 * Sets the player's facing direction to left ('L').
 * If the tile is a wall ('1'), no movement occurs.
 * If the tile is the exit ('E') and the player has collected all items,
 * the game ends with a victory.
 * Otherwise, the player moves left, the move count is incremented, and any unique
 * items are processed.
 *
 * @param data Pointer to the game data structure.
 */
void check_left(t_data *data)
{
    data->player->facing = 'L';
    if (data->map->map[data->player->y][data->player->x - 1] == '1')
        return;
    else if (data->map->map[data->player->y][data->player->x - 1] == 'E')
    {
        if (data->player->win == 1)
        {
            data->player->moves++;
            ft_printf("Move #%i\n", data->player->moves);
            victory();
            game_destroy(data);
            return;
        }
    }
    data->player->x--;
    data->player->moves++;
    ft_printf("Move #%i\n", data->player->moves);
    check_unique(data);
    return;
}

/**
 * @brief Checks the tile to the right of the player and processes movement.
 *
 * Sets the player's facing direction to right ('R').
 * If the tile is a wall ('1'), no movement occurs.
 * If the tile is the exit ('E') and the player has collected all items,
 * the game ends with a victory.
 * Otherwise, the player moves right, the move count is incremented, and any unique
 * items are processed.
 *
 * @param data Pointer to the game data structure.
 */
void check_right(t_data *data)
{
    data->player->facing = 'R';
    if (data->map->map[data->player->y][data->player->x + 1] == '1')
        return;
    else if (data->map->map[data->player->y][data->player->x + 1] == 'E')
    {
        if (data->player->win == 1)
        {
            data->player->moves++;
            ft_printf("Move #%i\n", data->player->moves);
            victory();
            game_destroy(data);
            return;
        }
    }
    data->player->x++;
    data->player->moves++;
    ft_printf("Move #%i\n", data->player->moves);
    check_unique(data);
    return;
}
