#include "../../includes/so_long.h"

/**
 * @brief Checks that the map boundaries are valid.
 *
 * Verifies that the first and last rows of the map are completely filled with walls ('1').
 * It also updates the map length (c->len) based on the first row, ensuring consistency.
 *
 * @param c Pointer to the map structure.
 * @return int Returns 0 if boundaries are valid; otherwise, returns -1.
 */
int boundary_check(t_map *c)
{
    c->len = ft_strlen(c->map[0]) - 1;
    while (c->current_col < c->len)
    {
        if (c->map[0][c->current_col] != '1')
        {
            return (-1);
        }
        c->current_col++;
    }
    c->current_col = 0;
    if (c->len != (int)(ft_strlen(c->map[c->mlen])) - 1)
        return (-1);
    while (c->current_col < c->len)
    {
        if (c->map[c->mlen][c->current_col] != '1')
        {
            return (-1);
        }
        c->current_col++;
    }
    return (0);
}

/**
 * @brief Checks adjacent cells to determine if a valid path exists.
 *
 * Recursively checks the four cardinal directions (up, down, left, right) from the current cell.
 * If any adjacent cell leads to a valid path, the function returns 1; otherwise, it returns 0.
 *
 * @param c Pointer to the map structure.
 * @param row Current row index.
 * @param col Current column index.
 * @return int Returns 1 if at least one adjacent cell leads to a valid path; otherwise returns 0.
 */
int pathing_map(t_map *c, int row, int col)
{
    int res1;
    int res2;
    int res3;
    int res4;

    res1 = is_valid_path(c, row - 1, col);
    res2 = is_valid_path(c, row + 1, col);
    res3 = is_valid_path(c, row, col - 1);
    res4 = is_valid_path(c, row, col + 1);
    if (res1 || res2 || res3 || res4)
        return (1);
    else
        return (0);
}

/**
 * @brief Displays an error message when the map format is invalid.
 *
 * Prints specific error messages based on the error flags stored in the map structure:
 * - If the map is not rectangular or not surrounded by walls.
 * - If an unknown map component is found.
 * - If the map is too big.
 * - If there are not enough collectibles or if the required number of player or exit components is incorrect.
 *
 * After printing the error messages, sets the error flag to prevent further checks.
 *
 * @param c Pointer to the map structure.
 */
void invalid_format(t_map *c)
{
    if (c->error_flag == 1)
        return;
    ft_printf("\033[1;31m");
    ft_printf("Error: Invalid map format.\n");
    if (c->fd == -1)
        ft_printf("Map needs to be rectangular, surrounded by Walls(1).\n");
    if (c->fd == -2)
        ft_printf("Unknown map component (%c) found in map.\n", c->check);
    if (c->len >= MAX_WIDTH || c->mlen >= MAX_HEIGHT)
        ft_printf("Map too big.\n");
    if (c->c_count < 1)
        ft_printf("At least one Collectible(C) required.\n");
    if (c->p_count != 1)
        ft_printf("Only one Player(P) is required.\n");
    if (c->e_count != 1)
        ft_printf("Only one Exit(E) is required.\n");
    ft_printf("\033[0m");
    c->fd = 0;
    c->error_flag = 1;
}

/**
 * @brief Checks whether a path is valid from a given position.
 *
 * Determines if the cell at the given row and column is accessible, marking it as visited
 * by setting its value to '-' in the buffer. Additionally, if the cell contains an exit or a collectible,
 * updates the found counters.
 *
 * @param c Pointer to the map structure.
 * @param row Current row index.
 * @param col Current column index.
 * @return int Returns 1 if a valid path is found (i.e. all exits and collectibles have been reached),
 *             or if at least one recursive path is valid; returns 0 otherwise.
 */
int is_valid_path(t_map *c, int row, int col)
{
    int result;

    if (row < 0 || row >= c->mlen || col < 0 || col >= c->len
        || c->map_buffer[row][col] == '1' || c->map_buffer[row][col] == '-'
        || c->map_buffer[row][col] == 'M')
        return (0);
    if (c->map[row][col] == 'E')
        c->e_found++;
    else if (c->map[row][col] == 'C')
        c->c_found++;
    c->map_buffer[row][col] = '-';
    result = pathing_map(c, row, col);
    if (c->e_found == c->e_count && c->c_found == c->c_count)
        return (1);
    return (result);
}

/**
 * @brief Validates the map's path connectivity.
 *
 * Initializes the player's starting coordinates on the map, and then checks if there is a valid
 * path from that starting position to collect all collectibles and reach the exit.
 * If a valid path is found, the game title is displayed; otherwise, an error message is printed.
 *
 * @param c Pointer to the map structure.
 * @param p Pointer to the player structure.
 * @param fd File descriptor for the map file.
 * @return int Returns 1 if the path is valid; returns 0 if not or if an error occurs.
 */
int validate_path(t_map *c, t_player *p, int fd)
{
    if (fd == -1)
        return (-1);
    if (!init_player_coords(c, p, 0, 0))
        return (0);
    if (!is_valid_path(c, c->start_row, c->start_col))
    {
        ft_printf("\n\033[1;31mInvalid Path\033[0m\n\n");
        return (0);
    }
    else
    {
        tittle();
        return (1);
    }
}
