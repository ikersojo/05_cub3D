/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:43:17 by mvalient          #+#    #+#             */
/*   Updated: 2023/05/15 18:15:02 by mvalient         ###   ########.fr       */
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

int ft_get_longest_line(char **map, int j)
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