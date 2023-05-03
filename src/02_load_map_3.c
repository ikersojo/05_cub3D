/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_load_map_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:15:10 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/03 23:15:05 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/*
 * Initializes the map grid array to '1' and returns it.
 * Returns NULL if the allocations fail.
 */
static char	**ft_init_grid(t_map *map)
{
	char	**grid;
	int		i;
	int		j;
	int		k;

	grid = (char **)malloc(sizeof(char *) * map->map_h);
	if (grid == NULL)
		return (NULL);
	i = -1;
	while (++i < map->map_h)
	{
		*(grid + i) = (char *)malloc(sizeof(char) * map->map_w);
		if (*(grid + i) == NULL)
		{
			k = -1;
			while (++k < i)
				free (*(grid + k));
			free (grid);
			return (NULL);
		}
		j = -1;
		while (++j < map->map_w)
			*(*(grid + i) + j) = '1';
	}
	return (grid);
}

/*
 * Generate map grid array and return it.
 * Returns NULL if the allocation fails.
 */
char	**ft_gen_map_grid(t_map *map, char **line)
{
	char	**grid;
	int		i;
	int		j;

	grid = ft_init_grid(map);
	if (grid == NULL)
		return (NULL);
	i = -1;
	while (++i < map->map_h)
	{
		if (i != 0)
			*line = ft_gnl(map->mapfd);
		j = -1;
		while (++j < map->map_w)
		{
			if (*(*line + j) == '\0' || *(*line + j) == '\n')
				break ;
			else if (ft_ischarset(*(*line + j), " 1") == 1)
				*(*(grid + i) + j) = '1';
			else if (ft_ischarset(*(*line + j), "0NSEW") == 1)
				*(*(grid + i) + j) = *(*line + j);
		}
		free (*line);
	}
	return (grid);
}

/*
 * Locate the initial position of the player in the map.
 */
void	ft_get_initial_pos(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->map_h)
	{
		j = -1;
		while (++j < map->map_w)
		{
			if (ft_ischarset(map->grid[i][j], "NSEW") == 1)
			{
				map->start_char = map->grid[i][j];
				map->start_x = j;
				map->start_y = i;
			}
		}
	}
}
