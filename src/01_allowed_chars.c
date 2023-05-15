/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_allowed_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:45:19 by mvalient          #+#    #+#             */
/*   Updated: 2023/05/15 09:01:39 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/*
 * Function will return nonzero if the line contains any non-allowed character.
 * flag argument is used to return the number of players on the map.
 */
static int	ft_allowed(char *line, int flag)
{
	static int	player = 0;
	int			i;

	if (flag == 1)
		return (player);
	i = -1;
	while (line[++i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == ' ')
			printf("%c", line[i]);
		else if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E')
		{
			if (player == 1)
				return (printf("Error\nMore than one player on the map.\n"));
			player = 1;
			printf("%c", line[i]);
			line[i] = '0';
		}
		else if (line[i] == '\n')
			printf("%c", line[i]);
		else
			return (printf("Error\nInvalid character on the map.\n"));
	}
	return (0);
}

/*
 * Function will return nonzero map contains any invalid character.
 * map argument contains full configuration file.
 * i argument is the index of the line where the map starts.
 */
int	ft_allowed_chars(char **map, int i)
{
	static int	error;

	i -= 1;
	while (map[++i])
		error += ft_allowed(map[i], 0);
	if (!ft_allowed(NULL, 1))
		return (printf("Error\nThere's no player on the map.\n"));
	return (error);
}
