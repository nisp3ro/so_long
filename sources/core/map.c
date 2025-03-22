#include "../../includes/so_long.h"

/**
 * @brief Renders an image at the specified cell coordinates.
 *
 * Calculates the pixel coordinates for the given map cell and renders the image
 * on the window.
 *
 * @param d Pointer to the game data structure.
 * @param img_ptr Pointer to the image to be rendered.
 * @param c Pointer to the current map cell structure.
 */
void render_image(t_data *d, void *img_ptr, t_map *c)
{
    int x;
    int y;

    x = c->col * SIZE;
    y = c->row * SIZE;
    mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, img_ptr, x, y);
}

/**
 * @brief Draws objects on the map based on the cell content.
 *
 * Renders the appropriate texture for the current cell according to the map
 * character. The function checks for walls, floor, exit, collectible items, player,
 * and monster, updating the monster counter if needed.
 *
 * @param data Pointer to the game data structure.
 * @param c Pointer to the current map cell structure.
 * @param t Pointer to the texture structure.
 */
void draw_objects(t_data *data, t_map *c, t_texture *t)
{
    if (c->map[c->row][c->col] == '1')
        render_image(data, t->wall, c);
    else if (c->map[c->row][c->col] == '0')
        render_image(data, t->floor, c);
    else if (c->map[c->row][c->col] == 'E')
        render_image(data, t->exit[data->player->win], c);
    else if (c->map[c->row][c->col] == 'C')
        render_image(data, t->collect[t->frame], c);
    else if (c->map[c->row][c->col] == 'P' || c->map[c->row][c->col] == 'X')
    {
        if (data->player->facing == 'L')
            render_image(data, t->player_l[t->frame], c);
        else if (data->player->facing == 'R')
            render_image(data, t->player_r[t->frame], c);
    }
    else if (c->map[c->row][c->col] == 'M')
    {
        if (data->monster->facing[data->monster->count] == 'L')
            render_image(data, t->monster_l[t->frame], c);
        else if (data->monster->facing[data->monster->count] == 'R')
            render_image(data, t->monster_r[t->frame], c);
        data->monster->count++;
    }
}

/**
 * @brief Draws the entire game map.
 *
 * Iterates through all cells in the map to render the corresponding objects,
 * then overlays the background and renders the move count.
 *
 * @param data Pointer to the game data structure.
 * @param c Pointer to the map structure.
 * @param t Pointer to the texture structure.
 */
void draw_map(t_data *data, t_map *c, t_texture *t)
{
    c->row = 0;
    data->monster->count = 0;
    while (c->row <= c->mlen)
    {
        c->col = 0;
        while (c->col <= c->len)
        {
            draw_objects(data, c, t);
            c->col++;
        }
        c->row++;
    }
    c->col = 0;
    while (c->col <= c->len)
    {
        render_image(data, t->bg, c);
        c->col++;
    }
    render_moves(data, c);
}

/**
 * @brief Sets up the game window and initializes the map.
 *
 * Calculates the dimensions for the window based on the map size, initializes the
 * MLX instance, creates the window, loads textures, allocates memory for monsters,
 * and draws the initial map.
 *
 * @param data Pointer to the game data structure.
 * @param c Pointer to the map structure.
 * @param t Pointer to the texture structure.
 */
void map_window(t_data *data, t_map *c, t_texture *t)
{
    c->width = SIZE * (c->len + 1);
    c->height = SIZE * (c->mlen + 2);
    c->delay = (c->len * c->mlen) / 10;
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, c->width, c->height, "so_long");
    render_xpm(data, t);
    mem_monster(data);
    draw_map(data, c, t);
    return;
}

/**
 * @brief Creates and validates the game map, then starts the game.
 *
 * Initializes variables, opens the .ber file and validates the map path.
 * If no errors are found, the window is created and the game loop is started.
 * Finally, the map file descriptor is closed.
 *
 * @param data Pointer to the game data structure.
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 */
void create_map(t_data *data, int argc, char **argv)
{
    init_vars(data);
    if (open_ber(data->map, argv[1], argc, argv) != 0
        && validate_path(data->map, data->player, data->map->fd) == 1)
    {
        if (data->map->error_flag == 0)
        {
            map_window(data, data->map, data->texture);
            game_loop(data);
        }
    }
    close(data->map->fdmap);
}
