/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_init_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:07:52 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/17 22:21:03 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

t_player	*ft_init_player(t_map *map)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (player == NULL)
	{
		ft_free_map(map);
		return (NULL);
	}
	player->x_pos = (double)map->start_x + 0.5;
	player->y_pos = (double)(map->map_h - map->start_y) - 0.5;
	player->vx = 0;
	player->vy = 0;
	if (map->start_char == 'N')
		player->vy = 1;
	else if (map->start_char == 'S')
		player->vy = -1;
	else if (map->start_char == 'W')
		player->vx = -1;
	else if (map->start_char == 'E')
		player->vx = 1;
	return (player);
}

static void	ft_free_game_and_exit(t_game *game)
{
	if (game->map)
		ft_free_map(game->map);
	if (game->player)
		free(game->player);
	free (game);
	ft_exit_w_error("errno");
}

t_game	*ft_initialize_game(char *map_file, int map_w, int map_h)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		ft_exit_w_error("errno");
	game->map = ft_load_map(map_file, map_w, map_h);
	if (game->map == NULL)
		ft_free_game_and_exit(game);
	ft_get_initial_pos(game->map);
	game->player = ft_init_player(game->map);
	if (game->player == NULL)
		ft_free_game_and_exit(game);
	game->gui = ft_initialize_gui();
	if (game->gui == NULL)
		ft_free_game_and_exit(game);
	if (ft_load_textures(game) == 1)
	{
		ft_free_all_but_textures(game);
		ft_exit_w_error("Textures could not be loaded");
	}
	return (game);
}
