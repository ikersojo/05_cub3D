/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:07:41 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/18 07:53:03 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	ft_re_get_next_line(int fd, char **line)
{
	*line = get_next_line(fd);
	return (ft_strlen(*line));
}

// If the map meets the requirements returns 0. If not, 1.
// No memoryt should remain allocated when existing this function
int	ft_check_map(char *map_file, int *w, int *h)
{
	static int	error;
	char		*map[1000];
	static int	i;
	int			fd;

	ft_memset(map, 0, sizeof(map));
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (printf("Map file does not exist or cannot be accessed.\n"));
	while (ft_re_get_next_line(fd, &map[i]))
	{
		if (i == 999)
			return (ft_free_return(map, 2, 0));
		i++;
	}
	close(fd);
	error += ft_parse_textures(map, 0, 0, 0);
	error += ft_allowed_chars(map, ft_map_start(map));
	*w = ft_get_longest_line(map, ft_map_start(map)) - 1;
	*h = i - ft_map_start(map);
	if (*w <= 1 || *h <= 1)
		return (ft_free_return(map, 3, 0));
	error += ft_bounds(ft_safe_map(map, ft_map_start(map), *w, *h), 0);
	ft_free_return(map, 0, 0);
	return (error);
}
