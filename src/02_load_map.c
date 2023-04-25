/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:35:13 by isojo-go          #+#    #+#             */
/*   Updated: 2023/04/25 23:37:44 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/*
 * Generates a string for each parameter read on the map file, except for the
 * map itself. Returns 0 if successfully found each string, if not, returns 1.
 */
static int	ft_load_map_params(t_map *map, char *line)
{
	char	**items;

	items = ft_split(line, ' '); // TODO: al comprobar el mapa asegurar que solo hay 2 items
	free (line);
	if (items == NULL)
		return (1);
	if (ft_strcmp(*(items + 0), "NO") == 0)
		map->params[0] = ft_strdup(*(items + 1));
	else if (ft_strcmp(*(items + 0), "SO") == 0)
		map->params[1] = ft_strdup(*(items + 1));
	else if (ft_strcmp(*(items + 0), "WE") == 0)
		map->params[2] = ft_strdup(*(items + 1));
	else if (ft_strcmp(*(items + 0), "EA") == 0)
		map->params[3] = ft_strdup(*(items + 1));
	else if (ft_strcmp(*(items + 0), "F") == 0)
		map->params[4] = ft_strdup(*(items + 1));
	else if (ft_strcmp(*(items + 0), "C") == 0)
		map->params[5] = ft_strdup(*(items + 1));
	free (*(items + 0));
	free (*(items + 1));
	free (items);
	return (0);
}

/*
 * Checks the allocation of params and trims the \n.
 * Returns 0 if successfully allocated each string, if not, returns 1.
 */
static int	ft_check_params(t_map *map)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (map->params[i] == NULL)
			return (1);
		*(map->params[i] + ft_strlen(map->params[i]) - 1) ='\0';
	}
	return (0);
}

/*
 * Generate map grid array and return it.
 */
static char	**ft_gen_map_grid(t_map *map, char **line)
{
	char	**grid;
	int		i;
	int		j;

	grid = (char **)malloc(sizeof(char *) * map->map_h);
	if (grid == NULL)
		return (NULL);
	i = 0;
	while (i < map->map_h)
	{
		if (i != 0)
			*line = ft_gnl(map->mapfd);
		*(grid + i) = (char *)malloc(sizeof(char) * map->map_w);
		j = -1;
		while (++j < map->map_w)
		{
			*(*(grid + i) + j) = *(*line + j);
			if(ft_ischarset(*(*(grid + i) + j), "NSEW") == 1)
			{
				map->start_char = *(*(grid + i) + j);
				map->start_x = j;
				map->start_y = i;
			}
		}
		i++;
		free (*line);
	}
	return (grid);
}

/*
 * Populates the integers for the colors based on str input.
 */
static int	ft_derive_rgb(char *str, int *r, int *g, int *b)
{
	char	**rgb;
	int		i;

	rgb = ft_split(str, ',');
	if (rgb == NULL)
		return (1);
	*r = ft_atoi(rgb[0]);
	*g = ft_atoi(rgb[1]);
	*b = ft_atoi(rgb[2]);
	i = 0;
	while (i < 3)
		free (rgb[i++]);
	free(rgb);
	return (0);
}


t_map	*ft_init_map(char *map_file, int map_w, int map_h)
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
		line = ft_gnl(map->mapfd);
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
	if (ft_check_params(map) == 1)
		return (ft_closefd_and_free_map(map));
	if ((ft_derive_rgb(map->params[4], &map->f_r, &map->f_g, &map->f_b) == 1)
		|| (ft_derive_rgb(map->params[5], &map->c_r, &map->c_g, &map->c_b) == 1)
		|| (map->grid == NULL))
		return (ft_closefd_and_free_map(map));
	close(map->mapfd);
	return (map);
}
