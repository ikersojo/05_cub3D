/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_def_events_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:18:23 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/04 11:21:08 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/*
 * Close the game when pressing the red icon on the window.
 */
int	ft_on_destroy(int keycode, void *param)
{
	t_game	**game_ptr;
	t_game	*game;

	(void)keycode;
	game_ptr = param;
	game = *game_ptr;
	(void)game;
	printf("Exiting game...\n");
	exit(EXIT_SUCCESS);
	return (0);
}

/*
 * BONUS: Limits the potetial movement of the player to the map
 */
static void	ft_limit_player_pos(t_game *game, double new_x, double new_y)
{
	int	i;
	int	j;

	j = (int)floor(new_x);
	i = game->map->map_h - (int)floor(new_y) - 1;
	if (game->map->grid[i][j] != '1')
	{
		game->player->x_pos = new_x;
		game->player->y_pos = new_y;
	}
}

/*
 * Derive the new player location after requesting to move and requests to
 * re-draw the image
 */
static void	ft_move(t_game *game, int x, int y)
{
	double	rot_vx;
	double	rot_vy;
	double	new_x;
	double	new_y;

	rot_vx = game->player->vx * cos(M_PI / 2)
		- game->player->vy * sin(M_PI / 2);
	rot_vy = game->player->vx * sin(M_PI / 2)
		+ game->player->vy * cos(M_PI / 2);
	if (x != 0)
	{
		new_x = game->player->x_pos + (STEP * game->player->vx * x);
		new_y = game->player->y_pos + (STEP * game->player->vy * x);
	}
	else
	{
		new_x = game->player->x_pos + (STEP * rot_vx * y);
		new_y = game->player->y_pos + (STEP * rot_vy * y);
	}
	ft_limit_player_pos(game, new_x, new_y);
	if (DEBUG == 1)
		ft_print_player_data(game->player);
	ft_put_img(game);
}

/*
 * Derive the new player location after requesting to rotate and requests to
 * re-draw the image
 */
static void	ft_rotate(t_game *game, int sign)
{
	game->player->vx = game->player->vx * cos(ROT_STEP * sign)
		- game->player->vy * sin(ROT_STEP * sign);
	game->player->vy = game->player->vx * sin(ROT_STEP * sign)
		+ game->player->vy * cos(ROT_STEP * sign);
	game->player->vx /= hypot(game->player->vx, game->player->vy);
	game->player->vy /= hypot(game->player->vx, game->player->vy);
	if (DEBUG == 1)
		ft_print_player_data(game->player);
	ft_put_img(game);
}

/*
 * Launc different events depending on the key pressed.
 */
int	ft_on_keydown(int keycode, void *param)
{
	t_game		**game_ptr;
	t_game		*game;

	game_ptr = param;
	game = *game_ptr;
	if (keycode == KEY_ESC)
		ft_close_game(game);
	else if (keycode == KEY_W)
		ft_move(game, 1, 0);
	else if (keycode == KEY_S)
		ft_move(game, -1, 0);
	else if (keycode == KEY_A)
		ft_move(game, 0, 1);
	else if (keycode == KEY_D)
		ft_move(game, 0, -1);
	else if (keycode == KEY_LEFT)
		ft_rotate(game, 1);
	else if (keycode == KEY_RIGHT)
		ft_rotate(game, -1);
	return (0);
}

// // puede que sobre...
// int	ft_on_idle(int keycode, void *param)
// {
// 	t_game	**game_ptr;
// 	t_game	*game;

// 	game_ptr = param;
// 	game = *game_ptr;
// 	(void)keycode;
// 	(void)game;
// 	return (0);
// }
