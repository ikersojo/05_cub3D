/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:29:27 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/03 23:29:30 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	ft_print_player_data(t_player *player)
{
	printf("\n\n\033[0;93m--------------- PLAYER DATA ---------------\n\n");
	printf("Position: (%f, %f)\n", player->x_pos, player->y_pos);
	printf("Direction Vector: (%f, %f)\n", player->vx, player->vy);
	printf("\n-----------------------------------------\033[0;39m\n\n");
}

void	ft_print_map_data(t_map *map)
{
	int	i;
	int	j;

	printf("\n\n\033[0;93m--------------- MAP DATA ---------------\n\n");
	printf("MAP (%d x %d):\n", map->map_w, map->map_h);
	printf("NO Texture: %s\n", map->params[0]);
	printf("SO Texture: %s\n", map->params[1]);
	printf("WE Texture: %s\n", map->params[2]);
	printf("EA Texture: %s\n\n", map->params[3]);
	printf("Floor:   %s --> (%d, %d, %d)\n", map->params[4],
		map->f_r, map->f_g, map->f_b);
	printf("Ceiling: %s --> (%d, %d, %d)\n\n", map->params[5],
		map->c_r, map->c_g, map->c_b);
	i = -1;
	while (++i < map->map_h)
	{
		j = 0;
		while (j < map->map_w)
			printf("%c ", map->grid[i][j++]);
		printf("\n");
	}
	printf("\nSTART POSTION: %c (%d, %d)\n", map->start_char,
		map->start_x, map->start_y);
	printf("\n-----------------------------------------\033[0;39m\n\n");
}

void	ft_print_rays(t_game *game)
{
	int	i;

	printf("\n\n\033[0;93m--------------- RAY DATA ---------------\n\n");
	i = 0;
	while (i < SCREEN_W)
	{
		printf(" - ray %d - vector (%.3f, %.3f)", i, game->rays.dir[i].x,
			game->rays.dir[i].y);
		printf(" - dist: %.3f (corrected: %.3f)", game->rays.dist[i],
			game->rays.dist[i] * cos(game->rays.angle[i]));
		printf(" - wall_h: %d", game->rays.wall_h[i]);
		printf(" - text: %d\n", game->rays.texture[i]);
		i += 30;
	}
	printf("\n-----------------------------------------\033[0;39m\n\n");
}

void	ft_print_game_data(t_game *game)
{
	ft_print_map_data(game->map);
	ft_print_player_data(game->player);
}

void	ft_print_texel(t_tex *texture)
{
	int	i;
	int	j;

	printf("\n\n\033[0;93m--------------- TEXEL DATA ---------------\n\n");
	i = -1;
	while (++i < texture->height)
	{
		j = 0;
		while (j < texture->width)
			printf("%d ", texture->texel[i][j++]);
		printf("\n");
	}
	printf("\n texture->width: %d, texture->height: %d\n\n", texture->width,
		texture->height);
	printf("\n-----------------------------------------\033[0;39m\n\n");
}
