/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99_aux_1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:21:33 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/04 11:21:23 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	ft_close_game(t_game *game)
{
	ft_free_all(game);
	printf("Exiting game...\n");
	exit(EXIT_SUCCESS);
}

static int	ft_get_i(t_game *game, double y)
{
	int	i;

	i = game->map->map_h - (int)floor(y) - 1;
	if (i < 0)
		i = 0;
	if (i > game->map->map_h - 1)
		i = game->map->map_h - 1;
	return (i);
}

static int	ft_get_j(t_game *game, double x)
{
	int	j;

	j = (int)floor(x);
	if (j < 0)
		j = 0;
	if (j > game->map->map_w - 1)
		j = game->map->map_w - 1;
	return (j);
}

/*
 * Checks coordinates and returns collision plane: 0: N, 1: S, 2: W, 3: E
 */
int	check_coords(t_game *game, double x, double y)
{
	char	**grid;
	int		i;
	int		j;

	grid = game->map->grid;
	i = ft_get_i(game, y);
	j = ft_get_j(game, x);
	if (grid[i][j] == '1')
	{
		if (j > 0 && (fabs(x - floor(x)) < 0.01) && grid[i][j - 1] != '1')
			return (3);
		else if (j < game->map->map_w - 1 && (fabs(x - ceil(x)) < 0.01)
			&& grid[i][j + 1] != '1')
			return (2);
		else if (i < game->map->map_h - 1 && (fabs(y - floor(y)) < 0.01)
			&& grid[i + 1][j] != '1')
			return (0);
		else if (i > 0 && (fabs(y - ceil(y)) < 0.01) && grid[i - 1][j] != '1')
			return (1);
		else
			return (4);
	}
	return (10);
}

/*
 * Returns 1 if the player is in the map or 0 if it is in a wall
 * or outside the map
 */
int	ft_inmap(t_game *game)
{
	int	i;
	int	j;
	int	inmap;

	inmap = 1;
	j = (int)floor(game->player->x_pos);
	i = game->map->map_h - (int)floor(game->player->y_pos) - 1;
	if (j < 0)
		j = 0;
	if (j > game->map->map_w - 1)
		j = game->map->map_w - 1;
	if (i < 0)
		i = 0;
	if (i > game->map->map_h - 1)
		i = game->map->map_h - 1;
	if (game->map->grid[i][j] == '1')
		inmap = 0;
	if (DEBUG == 1)
		printf("\033[0;93mINMAP DEBUG (j: %d, i: %d) -> inmap: %d\033[0;39m\n",
			j, i, inmap);
	return (inmap);
}
