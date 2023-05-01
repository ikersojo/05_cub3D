/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99_aux_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:35:51 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/01 09:53:20 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	ft_close_game(t_game *game)
{
	ft_free_all(game);
	printf("Exiting game...\n");
	exit(EXIT_SUCCESS);
}

// Checks coordinates and returns collision plane: 1: N, 2: S, 3: W, 4: E
int	check_coords(t_game *game, double x, double y)
{
	char	**grid;
	int		i;
	int		j;

	grid = game->map->grid;
	j = (int)floor(x);
	i = game->map->map_h - (int)floor(y) - 1;
	if (j < 0)
		j = 0;
	if (j > game->map->map_w - 1)
		j = game->map->map_w - 1;
	if (i < 0)
		i = 0;
	if (i > game->map->map_h - 1)
		i = game->map->map_h - 1;
	if (grid[i][j] == '1')
	{
		if (j > 0 && (fabs(x - floor(x)) < 0.01) && grid[i][j - 1] != '1')
			return (4);
		else if (j < game->map->map_w - 1 && (fabs(x - ceil(x)) < 0.01) && grid[i][j + 1] != '1')
			return (3);
		else if (i < game->map->map_h - 1 && (fabs(y - floor(y)) < 0.01) && grid[i + 1][j] != '1')
			return (1);
		else if (i > 0 && (fabs(y - ceil(y)) < 0.01) && grid[i - 1][j] != '1')
			return (2);
		else
			return (5);
	}
	return (0);
}
