/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_def_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:35:30 by isojo-go          #+#    #+#             */
/*   Updated: 2023/04/27 16:56:58 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	ft_on_destroy(int keycode, void *param)
{
	t_game	**game_ptr;
	t_game	*game;

	(void)keycode;
	game_ptr = param;
	game = *game_ptr;
	(void)game;
	printf("Exiting game...\n");
	// ft_close_game(game); // --> once destroyed, we cannot access any of the parameters
	exit(EXIT_SUCCESS);
	return (0);
}

static void	ft_move(t_game *game, int x, int y) // TODO: movernos en la dir de la camara
{
	game->player->x_pos += (STEP * x);
	game->player->y_pos += (STEP * y);
	if (DEBUG == 1)
		ft_print_player_data(game->player);
	ft_put_img(game);
}

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

int	ft_on_keydown(int keycode, void *param)
{
	t_game		**game_ptr;
	t_game		*game;

	game_ptr = param;
	game = *game_ptr;
	if (keycode == KEY_ESC)
		ft_close_game(game);
	else if (keycode == KEY_W)
		ft_move(game, 0, 1);
	else if (keycode == KEY_S)
		ft_move(game, 0, -1);
	else if (keycode == KEY_A)
		ft_move(game, -1, 0);
	else if (keycode == KEY_D)
		ft_move(game, 1, 0);
	else if (keycode == KEY_LEFT)
		ft_rotate(game, 1);
	else if (keycode == KEY_RIGHT)
		ft_rotate(game, -1);
	return (0);
}

int	ft_on_idle(int keycode, void *param)
{
	t_game	**game_ptr;
	t_game	*game;

	game_ptr = param;
	game = *game_ptr;
	(void)keycode;
	(void)game;
	return (0);
}
