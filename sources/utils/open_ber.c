#include "../../includes/so_long.h"

/**
 * @brief Tracks and counts map objects.
 *
 * Checks the current character stored in c->check and increments the corresponding
 * counter for exit ('E'), player ('P'), collectible ('C'), or monster ('M').
 * If the character is not one of the allowed map symbols ('E', 'P', 'C', '1', '0', 'M'),
 * sets the file descriptor to -2 and returns -1 to indicate an error.
 *
 * @param c Pointer to the map structure.
 * @return int Returns -1 if an invalid character is found; otherwise returns 0.
 */
int object_tracker(t_map *c)
{
    if (c->check == 'E')
        c->e_count++;
    if (c->check == 'P')
        c->p_count++;
    if (c->check == 'C')
        c->c_count++;
    if (c->check == 'M')
        c->m_count++;
    if (c->check != 'E' && c->check != 'P' && c->check != 'C' &&
        c->check != '1' && c->check != '0' && c->check != 'M')
    {
        c->fd = -2;
        return (-1);
    }
    return (0);
}

/**
 * @brief Validates the walls and components of the map.
 *
 * Iterates over each row of the map, checking that:
 * - All rows have the same length.
 * - The first and last characters in each row are walls ('1').
 * - Each cell in the row is a valid object by calling object_tracker().
 *
 * If any of these checks fail, sets an error flag (via c->fd) and returns -1.
 *
 * @param c Pointer to the map structure.
 * @return int Returns 0 if the map passes all checks; otherwise returns -1.
 */
int walls_and_components(t_map *c)
{
    int i;

    i = 0;
    while (i <= (c->mlen))
    {
        c->current_col = 0;
        if (c->len != (int)(ft_strlen(c->map[i])) - 1)
            return (-1);
        if (c->map[i][c->current_col] != '1' || c->map[i][c->len] != '1')
        {
            c->fd = -1;
            return (-1);
        }
        while (c->current_col <= c->len)
        {
            c->check = c->map[i][c->current_col];
            if (object_tracker(c) == -1)
                return (-1);
            c->current_col++;
        }
        i++;
    }
    return (0);
}

/**
 * @brief Validates the overall format of the map.
 *
 * Determines the number of rows (mlen) in the map, checks the boundaries using
 * boundary_check(), and validates that the walls and map components are correct.
 * Also ensures there is exactly one exit and one player, at least one collectible,
 * and that the map dimensions do not exceed the maximum allowed width or height.
 *
 * @param c Pointer to the map structure.
 * @return int Returns 0 if the map format is valid; otherwise returns -1.
 */
int valid_map_format(t_map *c)
{
    while (c->map[c->mlen + 1])
        c->mlen++;
    if (boundary_check(c) != 0)
    {
        c->fd = -1;
        return (-1);
    }
    if (walls_and_components(c) != 0)
        return (-1);
    if (c->e_count != 1 || c->p_count != 1 || c->c_count < 1 ||
        (c->len >= MAX_WIDTH || c->mlen >= MAX_HEIGHT))
        return (-1);
    return (0);
}

/**
 * @brief Reads the .ber map file and builds the map representation.
 *
 * Reads the map file line by line using get_next_line(), appending each line to
 * the map read buffer via mem_map_buffer(). Once complete, splits the buffer into
 * the map and map_buffer arrays. Finally, validates the map format and calls
 * invalid_format() if any issues are found.
 *
 * @param c Pointer to the map structure.
 */
void read_ber(t_map *c)
{
    c->line = get_next_line(c->fdmap);
    while (c->line)
    {
        mem_map_buffer(c);
        c->line = get_next_line(c->fdmap);
    }
    mem_alloc(c);
    if (valid_map_format(c) != 0)
        invalid_format(c);
}

/**
 * @brief Opens and validates the .ber map file.
 *
 * Checks that the proper number of arguments is passed and that the map filename
 * ends with ".ber". Opens the file and assigns its descriptor to both fd and fdmap.
 * If the file fails to open, prints an error message using perror().
 * Finally, reads and processes the map by calling read_ber().
 *
 * @param c Pointer to the map structure.
 * @param map_name The name of the map file.
 * @param ac Argument count.
 * @param av Array of arguments.
 * @return int Returns the file descriptor if successful; otherwise returns 0.
 */
int open_ber(t_map *c, char *map_name, int ac, char **av)
{
    if (ac != 2 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
    {
        ft_printf("Invalid arguments.\n");
        return (0);
    }
    c->fd = open(map_name, O_RDONLY);
    c->fdmap = c->fd;
    if (c->fd == -1)
    {
        perror("Error opening file.\n");
        return (0);
    }
    read_ber(c);
    return (c->fd);
}
