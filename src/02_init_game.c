/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:35:07 by isojo-go          #+#    #+#             */
/*   Updated: 2023/04/25 23:37:44 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

t_player	*ft_init_player(t_map *map)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (player == NULL)
		return (NULL);
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

t_game	*ft_initialize_game(char *map_file, int map_w, int map_h)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		ft_exit_w_error("errno");


	game->map = ft_load_map(map_file, map_w, map_h);
	if (game->map == NULL)
	{
		free (game);
		ft_exit_w_error("errno");
	}


	game->player = ft_init_player(game->map);
	if (game->player == NULL)
	{
		ft_free_map(game->map);
		free (game);
		ft_exit_w_error("errno");
	}


	return (game);
}
