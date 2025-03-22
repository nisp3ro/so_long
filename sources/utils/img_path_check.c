#include "../../includes/so_long.h"

/**
 * @brief Checks the existence of essential image files.
 *
 * Verifies that the required XPM image files exist by attempting to open each one.
 * If any file fails to open, the function img_fail() is called to handle the error.
 * This function checks the first set of image files and then delegates further checks
 * to check_file_02().
 */
void check_file(void)
{
    int file;

    file = open("./assets/floor.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/wall.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/bg.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/m_icon.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/exit/door_closed.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    check_file_02(file);
}

/**
 * @brief Checks the second set of essential image files.
 *
 * Continues verifying that additional required XPM image files exist.
 * If any file fails to open, the function img_fail() is called.
 * After checking these files, the function delegates further checks to check_file_03().
 *
 * @param file Dummy parameter used to chain file checking.
 */
void check_file_02(int file)
{
    file = open("./assets/exit/door_open.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/collect/coin_f0.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/collect/coin_f1.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/collect/coin_f2.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/collect/coin_f3.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    check_file_03(file);
}

/**
 * @brief Checks the third set of essential image files.
 *
 * Verifies the existence of player idle animation images for the left and right directions.
 * If any file fails to open, the function img_fail() is called.
 * After checking these files, the function delegates further checks to check_file_04().
 *
 * @param file Dummy parameter used to chain file checking.
 */
void check_file_03(int file)
{
    file = open("./assets/player/idle_L_0.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/player/idle_R_0.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/player/idle_L_1.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/player/idle_R_1.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/player/idle_L_2.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    check_file_04(file);
}

/**
 * @brief Checks the fourth set of essential image files.
 *
 * Verifies the existence of the remaining player idle animation images and the first set
 * of monster idle animation images. If any file fails to open, the function img_fail() is called.
 * After checking these files, the function delegates further checks to check_file_05().
 *
 * @param file Dummy parameter used to chain file checking.
 */
void check_file_04(int file)
{
    file = open("./assets/player/idle_R_2.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/player/idle_L_3.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/player/idle_R_3.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/monster/idle_L_0.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/monster/idle_R_0.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    check_file_05(file);
}

/**
 * @brief Checks the fifth set of essential image files.
 *
 * Verifies the remaining monster idle animation images. If any file fails to open,
 * the function img_fail() is called.
 *
 * @param file Dummy parameter used to chain file checking.
 */
void check_file_05(int file)
{
    file = open("./assets/monster/idle_L_1.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/monster/idle_R_1.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/monster/idle_L_2.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/monster/idle_R_2.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/monster/idle_L_3.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);

    file = open("./assets/monster/idle_R_3.xpm", O_RDONLY);
    if (file == -1)
        img_fail();
    close(file);
}
