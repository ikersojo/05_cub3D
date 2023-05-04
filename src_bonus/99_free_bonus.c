/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:29:13 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/04 11:21:28 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/*
 * Checks and frees all elements of a map
 */
void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (map->params[i] != NULL)
			free(map->params[i++]);
	}
	i = 0;
	while (i < map->map_h)
		free (*(map->grid + i++));
	free (map->grid);
	if (map != NULL)
		free(map);
}

t_map	*ft_closefd_and_free_map(t_map *map)
{
	close(map->mapfd);
	ft_free_map(map);
	return (NULL);
}

void	ft_free_textures(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		mlx_destroy_image(game->gui->mlx, game->gui->texture[i]->img->img);
		free(game->gui->texture[i]->img);
		free(game->gui->texture[i]);
	}
}

void	ft_free_all_but_textures(t_game *game)
{
	if (game->gui->win != NULL)
		mlx_destroy_window(game->gui->mlx, game->gui->win);
	if (game->gui != NULL)
		free (game->gui);
	ft_free_map(game->map);
	if (game->player != NULL)
		free(game->player);
	if (game != NULL)
		free (game);
}

void	ft_free_all(t_game *game)
{
	ft_free_textures(game);
	ft_free_all_but_textures(game);
}
