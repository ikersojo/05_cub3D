/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:07:41 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/15 17:50:51 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	re_get_next_line(int fd, char **line)
{
	*line = ft_gnl(fd);
	return (ft_strlen(*line));
}

// If the map meets the requirements returns 0. If not, 1.
// No memoryt should remain allocated when existing this function
int	ft_check_map(char *map_file, int *w, int *h)
{
	static int	error;
	char		*map[20];
	static int	i;
	int			fd;

	*w = 15;
	printf("\033[0;96mChecking map...\033[0;39m\n");
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (printf("Map file does not exist or cannot be accessed.\n"));
	while (re_get_next_line(fd, &map[i]))
		i++;
	close(fd);
	map[i] = NULL;
	error += parse_textures(map, 0, 0, 0, 0);
	error += ft_allowed_chars(map, ft_map_start(map));
	error += ft_bounds(map, ft_map_start(map));
	*h = i - ft_map_start(map);
	while (i >= 0)
		free(map[i--]);
	return (error);
}

// TODO: map check logic:
//(if an error exists: print error type in red, free all allocated mem and return 1)
// The IDs are all before the map
// there is nothing more than ids and newline chars before the map starts
// each id line only contains 2 items when splited (ID and VALUE)
// multiples spaces can be present
// Checking the map:
// GNL on each line:
// store the height of the
// The length of each line needs to be the same, unless addtinal spaces are required. This means ending in '1'
// In the process of sweeping lines, store the max width (without the new line char)
//the map file ends when the file ends
// if there are one or multiple empty new lines at the end of the file do not consider them
// if there are empty lines in between valid lines, consider them as spaces
