/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parse_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:50:33 by mvalient          #+#    #+#             */
/*   Updated: 2023/05/17 16:23:31 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/*
 * Function will return nonzero if color line is invalid.
 */
static int	ft_parse_color(char *line, int j, int k, int l)
{
	int	i;

	i = 0;
	while (line[++i] == ' ')
		 ;
	while (ft_isdigit(line[i + j]))
		j++;
	if (line[i++ + j] != ',')
		return (printf("Error\nInvalid color.\n"));
	while (ft_isdigit(line[i + j + k]))
		k++;
	if (line[i++ + j + k] != ',')
		return (printf("Error\nInvalid color.\n"));
	while (ft_isdigit(line[i + j + k + l]))
		l++;
	while (line[i + j + k + l])
	{
		if (!(line[i + j + k + l] == ' ' || line[i + j + k + l] == '\n'))
			return (printf("Error\nInvalid color.\n"));
		i++;
	}
	if (j > 3 || k > 3 || l > 3)
		return (printf("Error\nInvalid color.\n"));
	return (0);
}

static int	ft_texture_exits(char *line, int i)
{
	int		fd;
	char	**split;

	i = -1;
	split = ft_split(line, ' ');
	if (split[2])
	{
		while (split[++i])
			free (split[i]);
		free(split);
		return (printf("Error\nInvalid texture.\n"));
	}
	if (split[1])
	{
		split[1][ft_strlen(split[1]) - 1] = 0;
		fd = open(split[1], O_WRONLY);
		if (fd < 0)
			return (close(fd), printf("Error\nInvalid texture.\n"));
		close(fd);
	}
	while (split[++i])
		free (split[i]);
	free(split);
	return (1);
}

int	ft_parse_textures(char **map, int j, int k, int l, int m)
{
	int			i;
	static int	f;
	static int	c;

	i = -1;
	while (map[++i])
	{
		if (!ft_strncmp(map[i], "NO ", 3))
			j += ft_texture_exits(map[i], 0);
		else if (!ft_strncmp(map[i], "SO ", 3))
			k += ft_texture_exits(map[i], 0);
		else if (!ft_strncmp(map[i], "WE ", 3))
			l += ft_texture_exits(map[i], 0);
		else if (!ft_strncmp(map[i], "EA ", 3))
			m += ft_texture_exits(map[i], 0);
		if (map[i][0] == 'F')
			f += !ft_parse_color(map[i], 0, 0, 0);
		else if (map[i][0] == 'C')
			c += !ft_parse_color(map[i], 0, 0, 0);
	}
	if (j != 1 || k != 1 || l != 1 || m != 1)
		return (printf("There's a missing texture.\n"));
	if (f != 1 || c != 1)
		return (printf("There's a missing color.\n"));
	return (0);
}