#include "../../includes/so_long.h"

/**
 * @brief Main game loop.
 *
 * Sets up hooks for key presses, window destruction, and the periodic refresh callback,
 * then enters the main MLX loop.
 *
 * @param data Pointer to the game's data structure.
 * @return int Always returns 0.
 */
int game_loop(t_data *data)
{
    mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &on_keypress, data);
    mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &game_destroy, data);
    mlx_loop_hook(data->mlx_ptr, &refresh, data);
    mlx_loop(data->mlx_ptr);
    return (0);
}

/**
 * @brief Program entry point.
 *
 * Validates the input file, initializes the game data structure, creates the game map,
 * and finally frees allocated resources.
 *
 * @param argc Number of arguments.
 * @param argv Array of arguments.
 * @return int Returns 0 if execution was successful.
 */
int main(int argc, char **argv)
{
    t_data data;

    check_file();
    init_struct_pointers(&data);
    create_map(&data, argc, argv);
    free_game(&data);
    return (0);
}
