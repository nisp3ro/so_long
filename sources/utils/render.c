#include "../../includes/so_long.h"

/**
 * @brief Renders the coin collection status on the screen.
 *
 * Constructs a string displaying the current number of coins collected by the player
 * against the total coins available in the map (formatted as "Coins: <score>/<total>").
 * The message is rendered using mlx_string_put at the given position (temp_x, temp_y + 15).
 *
 * @param d Pointer to the game data structure.
 * @param c Pointer to the map structure.
 * @param temp_x The x-coordinate for text rendering.
 * @param temp_y The y-coordinate for text rendering.
 */
void render_collect(t_data *d, t_map *c, int temp_x, int temp_y)
{
    char *msg;
    char *temp_msg;
    char *temp_value;

    temp_value = ft_itoa(d->player->score);
    if (!temp_value)
        exit(EXIT_FAILURE);
    msg = ft_strjoin("Coins: ", temp_value);
    if (!msg)
        exit(EXIT_FAILURE);
    free(temp_value);
    temp_value = ft_itoa(c->c_count);
    temp_msg = ft_strjoin(msg, "/");
    if (!temp_value || !temp_msg)
        exit(EXIT_FAILURE);
    free(msg);
    msg = ft_strjoin(temp_msg, temp_value);
    if (!msg)
        exit(EXIT_FAILURE);
    free(temp_msg);
    free(temp_value);
    temp_y = temp_y + 15;
    mlx_string_put(d->mlx_ptr, d->win_ptr, temp_x, temp_y, 0xFFFFFF, msg);
    free(msg);
}

/**
 * @brief Renders the number of moves made by the player.
 *
 * Displays an icon and a text string indicating the move count. The text is rendered
 * using mlx_string_put at a position relative to the bottom of the window. After rendering
 * the moves, it calls render_collect() to display the coin collection status.
 *
 * @param d Pointer to the game data structure.
 * @param c Pointer to the map structure.
 */
void render_moves(t_data *d, t_map *c)
{
    int temp_x;
    int temp_y;
    char *msg;
    char *temp_value;

    temp_x = 0;
    temp_y = c->height - SIZE;
    mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->texture->m_icon, temp_x, temp_y);
    temp_value = ft_itoa(d->player->moves);
    if (!temp_value)
        exit(EXIT_FAILURE);
    msg = ft_strjoin("Moves: ", temp_value);
    if (!msg)
        exit(EXIT_FAILURE);
    temp_x = SIZE - 5;
    temp_y = temp_y + 15;
    mlx_string_put(d->mlx_ptr, d->win_ptr, temp_x, temp_y, 0xFFFFFF, msg);
    free(msg);
    free(temp_value);
    render_collect(d, c, temp_x, temp_y);
}

/**
 * @brief Loads an XPM image file and returns a pointer to the image.
 *
 * This helper function wraps the mlx_xpm_file_to_image() function, loading the XPM image
 * from the specified path with the pixel size defined in the texture structure.
 *
 * @param d Pointer to the game data structure.
 * @param path The file path to the XPM image.
 * @param t Pointer to the texture structure (used to obtain pixel size).
 * @return void* Pointer to the loaded image.
 */
void *xpm_i(t_data *d, char *path, t_texture *t)
{
    return (mlx_xpm_file_to_image(d->mlx_ptr, path, t->px_size, t->px_size));
}

/**
 * @brief Loads character images into texture arrays.
 *
 * Loads all XPM files for player and monster animations and stores the image pointers
 * into the respective arrays in the texture structure.
 *
 * @param data Pointer to the game data structure.
 * @param t Pointer to the texture structure.
 */
void render_characters(t_data *data, t_texture *t)
{
    t->player_l[0] = xpm_i(data, "./assets/player/idle_L_0.xpm", t);
    t->player_r[0] = xpm_i(data, "./assets/player/idle_R_0.xpm", t);
    t->player_l[1] = xpm_i(data, "./assets/player/idle_L_1.xpm", t);
    t->player_r[1] = xpm_i(data, "./assets/player/idle_R_1.xpm", t);
    t->player_l[2] = xpm_i(data, "./assets/player/idle_L_2.xpm", t);
    t->player_r[2] = xpm_i(data, "./assets/player/idle_R_2.xpm", t);
    t->player_l[3] = xpm_i(data, "./assets/player/idle_L_3.xpm", t);
    t->player_r[3] = xpm_i(data, "./assets/player/idle_R_3.xpm", t);
    t->monster_l[0] = xpm_i(data, "./assets/monster/idle_L_0.xpm", t);
    t->monster_r[0] = xpm_i(data, "./assets/monster/idle_R_0.xpm", t);
    t->monster_l[1] = xpm_i(data, "./assets/monster/idle_L_1.xpm", t);
    t->monster_r[1] = xpm_i(data, "./assets/monster/idle_R_1.xpm", t);
    t->monster_l[2] = xpm_i(data, "./assets/monster/idle_L_2.xpm", t);
    t->monster_r[2] = xpm_i(data, "./assets/monster/idle_R_2.xpm", t);
    t->monster_l[3] = xpm_i(data, "./assets/monster/idle_L_3.xpm", t);
    t->monster_r[3] = xpm_i(data, "./assets/monster/idle_R_3.xpm", t);
}

/**
 * @brief Loads all XPM textures for the game.
 *
 * Allocates memory for the pixel size variable, sets the size, and loads various images
 * (floor, wall, background, icon, exit doors, collectible coins) using the helper function xpm_i().
 * After loading static textures, calls render_characters() to load character animations.
 * Finally, frees the temporary memory allocated for pixel size.
 *
 * @param data Pointer to the game data structure.
 * @param t Pointer to the texture structure.
 */
void render_xpm(t_data *data, t_texture *t)
{
    t->px_size = malloc(sizeof(int));
    *t->px_size = SIZE;
    t->floor = xpm_i(data, "./assets/floor.xpm", t);
    t->wall = xpm_i(data, "./assets/wall.xpm", t);
    t->bg = xpm_i(data, "./assets/bg.xpm", t);
    t->m_icon = xpm_i(data, "./assets/m_icon.xpm", t);
    t->exit[0] = xpm_i(data, "./assets/exit/door_closed.xpm", t);
    t->exit[1] = xpm_i(data, "./assets/exit/door_open.xpm", t);
    t->collect[0] = xpm_i(data, "./assets/collect/coin_f0.xpm", t);
    t->collect[1] = xpm_i(data, "./assets/collect/coin_f1.xpm", t);
    t->collect[2] = xpm_i(data, "./assets/collect/coin_f2.xpm", t);
    t->collect[3] = xpm_i(data, "./assets/collect/coin_f3.xpm", t);
    render_characters(data, t);
    free(t->px_size);
}
