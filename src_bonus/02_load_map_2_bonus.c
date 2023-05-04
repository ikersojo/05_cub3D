/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_load_map_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:14:52 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/04 11:21:08 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/*
 * Generates a string for each parameter read on the map file, except for the
 * map itself. Returns 0 if successfully found each string, if not, returns 1.
 */
int	ft_load_map_params(t_map *map, char *line)
{
	char	**items;

	items = ft_split(line, ' ');
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
int	ft_check_params(t_map *map)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (map->params[i] == NULL)
			return (1);
		*(map->params[i] + ft_strlen(map->params[i]) - 1) = '\0';
	}
	return (0);
}

/*
 * Populates the integers for the colors based on str input.
 */
int	ft_get_rgb(char *str, int *r, int *g, int *b)
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
