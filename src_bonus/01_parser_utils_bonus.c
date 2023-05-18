/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parser_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:43:17 by mvalient          #+#    #+#             */
/*   Updated: 2023/05/18 14:50:44 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	ft_map_start(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (map[i][0] == '1' || map[i][0] == '0' || map[i][0] == ' ')
			return (i);
	}
	return (0);
}

int	ft_get_longest_line(char **map, int j)
{
	static int	i;

	while (map[j])
	{
		if (ft_strlen(map[j]) > i)
			i = ft_strlen(map[j]);
		j++;
	}
	return (i);
}

char	**ft_safe_map(char **map, int diff, int w, int h)
{
	char	**new_map;
	int		i;
	int		j;

	new_map = (char **)malloc(sizeof(char *) * (h + 1));
	i = -1;
	while (++i < h)
	{
		new_map[i] = (char *)malloc(sizeof(char) * (w + 3));
		ft_memset(new_map[i], ' ', w + 3);
		new_map[i][w + 1] = '\n';
		new_map[i][w + 2] = 0;
		j = -1;
		while (map[i + diff][++j])
			new_map[i][j] = map[i + diff][j];
	}
	new_map[i] = NULL;
	return (new_map);
}
