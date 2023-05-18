/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_load_map_1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:14:42 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/18 07:04:11 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/*
 * Initialize map loading (separated due to norm limitations).
 * Returns NULL if memory cannot be allocated.
 */
static t_map	*ft_init_map(char *map_file, int map_w, int map_h)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->mapfd = open(map_file, O_RDONLY);
	if (map->mapfd == -1)
	{
		free(map);
		return (NULL);
	}
	map->map_h = map_h;
	map->map_w = map_w;
	return (map);
}

/*
 * Checks correct loading of the map and closes the map file.
 */
static t_map	*ft_check_map_loading(t_map *map)
{
	if (ft_check_params(map) == 1)
		return (ft_closefd_and_free_map(map));
	if ((ft_get_rgb(map->params[4], &map->f_r, &map->f_g, &map->f_b) == 1)
		|| (ft_get_rgb(map->params[5], &map->c_r, &map->c_g, &map->c_b) == 1)
		|| (map->grid == NULL))
		return (ft_closefd_and_free_map(map));
	close(map->mapfd);
	return (map);
}

/*
 * Loads the map from a pre-validated file. Returns NULL if memory cannot
 * be allocated.
 */
t_map	*ft_load_map(char *map_file, int map_w, int map_h)
{
	t_map	*map;
	char	*line;

	map = ft_init_map(map_file, map_w, map_h);
	if (map == NULL)
		return (NULL);
	while (1)
	{
		line = get_next_line(map->mapfd);
		if (line == NULL)
			return (ft_closefd_and_free_map(map));
		else if (ft_chars_valid(line, " \n") == 1)
			free (line);
		else if (ft_chars_valid(line, "1 \n") == 1)
			break ;
		else
		{
			if (ft_load_map_params(map, line) == 1)
				return (ft_closefd_and_free_map(map));
		}
	}
	map->grid = ft_gen_map_grid(map, &line);
	return (ft_check_map_loading(map));
}
