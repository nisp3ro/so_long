#include "../../includes/so_long.h"

/**
 * @brief Destroys all game resources and exits the game.
 *
 * Frees allocated textures, destroys the window and display, releases allocated memory,
 * and terminates the program.
 *
 * @param data Pointer to the game data structure.
 * @return int Always returns 0 (though the function terminates the program).
 */
int game_destroy(t_data *data)
{
    int i;

    i = 0;
    while (i < 4)
    {
        mlx_destroy_image(data->mlx_ptr, data->texture->player_l[i]);
        mlx_destroy_image(data->mlx_ptr, data->texture->player_r[i]);
        mlx_destroy_image(data->mlx_ptr, data->texture->monster_l[i]);
        mlx_destroy_image(data->mlx_ptr, data->texture->monster_r[i]);
        mlx_destroy_image(data->mlx_ptr, data->texture->collect[i]);
        i++;
    }
    mlx_destroy_image(data->mlx_ptr, data->texture->exit[0]);
    mlx_destroy_image(data->mlx_ptr, data->texture->exit[1]);
    mlx_destroy_image(data->mlx_ptr, data->texture->wall);
    mlx_destroy_image(data->mlx_ptr, data->texture->floor);
    mlx_destroy_image(data->mlx_ptr, data->texture->bg);
    mlx_destroy_image(data->mlx_ptr, data->texture->m_icon);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    free_game(data);
    exit(0);
    return (0);
}

/**
 * @brief Handles key press events.
 *
 * Responds to key events by exiting the game when ESC is pressed, or moving the player
 * up, down, left, or right based on the key pressed.
 *
 * @param keysym The key symbol corresponding to the pressed key.
 * @param data Pointer to the game data structure.
 * @return int Always returns 0.
 */
int on_keypress(int keysym, t_data *data)
{
    if (keysym == KEY_ESC)
        game_destroy(data);
    else if (keysym == KEY_W || keysym == KEY_UP)
        move_up(data);
    else if (keysym == KEY_S || keysym == KEY_DOWN)
        move_down(data);
    else if (keysym == KEY_A || keysym == KEY_LEFT)
        move_left(data);
    else if (keysym == KEY_D || keysym == KEY_RIGHT)
        move_right(data);
    return (0);
}

/**
 * @brief Refreshes the game state and updates the display.
 *
 * Checks if the player has collected all items to win, redraws the game map,
 * updates the texture keyframes and animation frames, and executes the logic for monsters.
 *
 * @param data Pointer to the game data structure.
 * @return int Always returns 0.
 */
int refresh(t_data *data)
{
    if (data->player->score == data->map->c_count)
    {
        data->player->win = 1;
    }
    draw_map(data, data->map, data->texture);
    data->texture->keyframe = (data->texture->keyframe + 1) % (200 - data->map->delay);
    if (data->texture->keyframe == 0)
    {
        data->texture->frame = (data->texture->frame + 1) % 4;
    }
    monster_logic(data);
    return (0);
}
