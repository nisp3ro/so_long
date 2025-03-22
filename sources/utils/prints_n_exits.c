#include "../../includes/so_long.h"

/**
 * @brief Displays the game title and instructions.
 *
 * Prints a title with colored ASCII art along with instructions on how to play the game.
 */
void tittle(void)
{
    ft_printf("\n\033[1;32mValid Path\033[0m\n");
    ft_printf("\033[1;32mOpening map...\033[0m\n\n");
    ft_printf("\033[1;33m");
    ft_printf("    ┓      \n");
    ft_printf("┏┏┓ ┃┏┓┏┓┏┓\n");
    ft_printf("┛┗┛━┗┗┛┛┗┗┫\n");
    ft_printf("          ┛\n");
    ft_printf("\033[0m");
    ft_printf("\033[1;35mHOW TO PLAY\n");
    ft_printf("===========================================\n");
    ft_printf("| - Use WASD or Arrow keys to move!       |\n");
    ft_printf("| - Exit opens after all coins collected! |\n");
    ft_printf("| - Avoid monsters!                       |\n");
    ft_printf("===========================================\n\033[0m");
}

/**
 * @brief Displays a victory message.
 *
 * Prints a celebratory ASCII art along with a winning message in green.
 */
void victory(void)
{
    ft_printf("\033[1;32m");
    ft_printf("      ⣠⠴⠒⠉⠉⠉⠉⠉⠓⠢⣄⠀⠀⠀\n");
    ft_printf("⠀⠀⠀⠀⠀⡞⠁⠀⢀⡀⠀⠀⠀⠀⡄⠀⠈⣆⠀⠀\n");
    ft_printf("⠀⠀⠀⠀⢸⠁⠀⠀⠀⣱⠀⠀⠀⠐⣣⠂⠀⢹⡀⠀\n");
    ft_printf("⠀⠀⠀⠀⢸⠀⠀⠀⠀⢇⢠⣤⣴⣕⢹⢶⣄⣠⠇⠀\n");
    ft_printf("⠀⠀⠀⠀⠈⢧⠀⠀⡰⠀⠋⢣⣽⠎⠈⣿⡟⢻⠀⠀\n");
    ft_printf("⠀⠀⠀⠀⠀⠀⠓⠦⡷⣄⣀⠀⣰⡀⠀⡇⢀⠞⠀⠀\n");
    ft_printf("⠀⠀⠀⠀⠀⠀⠀⡸⠁⡇⠸⢰⠉⡩⢶⡹⡇⠀⠀⠀\n");
    ft_printf("⠀⣀⠤⠖⠒⡿⠹⠁⢰⠁⠀⠈⠈⢯⣭⠃⡇⠀⠀⠀\n");
    ft_printf("⣋⠀⠀⠀⢰⠁⠀⠀⠘⠦⣄⡀⠀⠈⠐⡆⢙⣆⠀⠀\n");
    ft_printf("⠉⠉⠳⣄⠀⢇⢠⡄⠀⠀⠀⠉⣳⠒⠒⡻⠉⠘⠓⢆ \n");
    ft_printf("        You won!\n");
    ft_printf("\033[0m");
}

/**
 * @brief Displays a losing message.
 *
 * Prints a detailed ASCII art in red along with a "You lose!" message.
 */
void lose(void)
{
    ft_printf("\033[1;31m");
    ft_printf(" ⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣫⣵⣾⣿⣿⣿⡿⠷⠦⠔⣶⣶⣶⣶⣶⠶⠶⠶⠤\n");
    ft_printf("⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⠿⠛⢁⣀⣌⣿⣿⣷⣶⣈⠿⣒⣒⣭⣭⣭⣭⣑⣒⠄\n");
    ft_printf("⠀⠀⠀⣠⡎⣾⣿⣿⣿⣿⢫⣡⡥⠶⠿⣛⠛⠋⠳⢶⣶⣾⣜⣫⣭⣷⠖⡁⠀⠐⢶⣯⡆\n");
    ft_printf("⠀⠀⣰⣿⣷⣿⣿⣿⣿⣿⣷⣖⢟⡻⢿⠃⢸⠱⠶⠀⠿⠟⡻⠿⣿⡏⠀⠅⠛⠀⣘⠟⠁\n");
    ft_printf("⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣮⣥⣤⣴⣤⣦⠄⣠⣾⣿⡻⠿⠾⠿⠿⠟⠛⠁\n");
    ft_printf("⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣭⣶⣿⣿⣿⣿⣿⣷⣿⣿⣿⣧⡀\n");
    ft_printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄\n");
    ft_printf("⢿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢩⡤⠶⠶⠶⠦⠬⣉⣛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⣋⣡\n");
    ft_printf("⠘⣿⣿⣿⣿⣿⣿⣟⢿⣧⣙⠓⢒⣚⡛⠳⠶⠤⢬⣉⣉⣉⣉⣉⣉⣉⣉⣉⣉⡄\n");
    ft_printf("  ⠈⠻⢿⣿⣿⣿⣿⣶⣽⣿⣿⣿⣿⣿⣿⣷⣶⣶⣶⣤⣤⣤⣤⣤⣤⡥⠄⠀\n");
    ft_printf("              You lose!\n");
    ft_printf("\033[0m");
}

/**
 * @brief Handles the error when an image file fails to open.
 *
 * Prints an error message using perror and exits the program with a failure status.
 */
void img_fail(void)
{
    perror("Error opening the XPM file.");
    exit(EXIT_FAILURE);
}
