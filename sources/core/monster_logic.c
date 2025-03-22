#include "../../includes/so_long.h"

/**
 * @brief Checks if the next position for a monster is valid.
 *
 * Evaluates the cells surrounding the monster's next intended move and returns a status:
 * - 0: Movement is blocked (both above and below are walls).
 * - 2: Next cell is blocked by an obstacle (wall, exit, collectible, monster, or player on the first move),
 *      or the cells above and below the next cell are both walls.
 * - -1: Next cell contains the player.
 * - 1: The next cell is clear for movement.
 *
 * @param data Pointer to the game data structure.
 * @param num The index of the monster in the monster array.
 * @param side The horizontal direction to check: -1 for left, 1 for right.
 * @return int Status code indicating if movement is valid.
 */
int next_is_valid(t_data *data, int num, int side)
{
    char up;
    char down;
    char next;
    char next_up;
    char next_down;

    up = data->map->map[data->monster->y[num] - 1][data->monster->x[num]];
    down = data->map->map[data->monster->y[num] + 1][data->monster->x[num]];
    next = data->map->map[data->monster->y[num]][data->monster->x[num] + side];
    next_up = data->map->map[data->monster->y[num] - 1][data->monster->x[num] + side];
    next_down = data->map->map[data->monster->y[num] + 1][data->monster->x[num] + side];

    if (up == '1' && down == '1')
        return (0);
    else if (next == '1' || next == 'E' || next == 'C' || next == 'M'
        || next == 'X' || (next_up == '1' && next_down == '1')
        || (next == 'P' && data->player->moves == 0))
        return (2);
    else if (next == 'P')
        return (-1);
    else
        return (1);
}

/**
 * @brief Handles monster movement to the left.
 *
 * Uses the next_is_valid() function to determine if the monster can move left.
 * If the next cell is blocked (returns 0 or 2), the monster changes its facing direction to right.
 * If the next cell contains the player (returns -1), the game is lost and terminated.
 * Otherwise, the monster's position is updated on the map.
 *
 * @param data Pointer to the game data structure.
 * @param num The index of the monster in the monster array.
 */
void monster_left(t_data *data, int num)
{
    if (next_is_valid(data, num, -1) == 0)
    {
        data->monster->facing[num] = 'R';
        return;
    }
    else if (next_is_valid(data, num, -1) == 2)
        data->monster->facing[num] = 'R';
    else if (next_is_valid(data, num, -1) == -1)
    {
        lose();
        game_destroy(data);
    }
    else
    {
        /* Clear current monster position */
        data->map->map[data->monster->y[num]][data->monster->x[num]] = '0';
        data->monster->x[num]--;
        /* Update monster position on the map */
        data->map->map[data->monster->y[num]][data->monster->x[num]] = 'M';
    }
}

/**
 * @brief Handles monster movement to the right.
 *
 * Uses the next_is_valid() function to determine if the monster can move right.
 * If the next cell is blocked (returns 0 or 2), the monster changes its facing direction to left.
 * If the next cell contains the player (returns -1), the game is lost and terminated.
 * Otherwise, the monster's position is updated on the map.
 *
 * @param data Pointer to the game data structure.
 * @param num The index of the monster in the monster array.
 */
void monster_right(t_data *data, int num)
{
    if (next_is_valid(data, num, 1) == 0)
    {
        data->monster->facing[num] = 'L';
        return;
    }
    else if (next_is_valid(data, num, 1) == 2)
        data->monster->facing[num] = 'L';
    else if (next_is_valid(data, num, 1) == -1)
    {
        lose();
        game_destroy(data);
    }
    else
    {
        /* Clear current monster position */
        data->map->map[data->monster->y[num]][data->monster->x[num]] = '0';
        data->monster->x[num]++;
        /* Update monster position on the map */
        data->map->map[data->monster->y[num]][data->monster->x[num]] = 'M';
    }
}

/**
 * @brief Moves all monsters based on their current facing direction.
 *
 * Iterates through each monster and, if the idle time condition is met,
 * moves the monster left or right by calling the corresponding functions.
 *
 * @param data Pointer to the game data structure.
 */
void monster_move(t_data *data)
{
    int num;

    num = 0;
    data->monster->idle_time = (data->monster->idle_time + 1) % (200 - data->map->delay);
    while (num < data->map->m_count)
    {
        if (data->monster->idle_time == 0)
        {
            if (data->monster->facing[num] == 'L')
            {
                monster_left(data, num);
            }
            else if (data->monster->facing[num] == 'R')
            {
                monster_right(data, num);
            }
        }
        num++;
    }
}

/**
 * @brief Controls the overall monster logic.
 *
 * Updates the monsters' coordinates and triggers their movement.
 *
 * @param data Pointer to the game data structure.
 */
void monster_logic(t_data *data)
{
    init_monster_coords(data->map, data->monster);
    monster_move(data);
}
