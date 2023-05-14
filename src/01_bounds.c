/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_bounds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalient <mvalient@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:20:32 by mvalient          #+#    #+#             */
/*   Updated: 2023/05/14 22:44:51 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/*
 * Function will return nonzero if the space is surrounded by walls or spaces.
 */
static int ft_check_near(char **map, int i, int j)
{
    if (map[i][j + 1] == '1' || map[i][j + 1] == '0')
        if (map[i][j - 1] == '1' || map[i][j - 1] == '0')
            if (map[i + 1][j] == '1' || map[i + 1][j] == '0')
                if (map[i - 1][j] == '1' || map[i - 1][j] == '0')
                    return (1);
    return (0);
}

/*
 * Function will return nonzero if the line contains any space.
 */
static int ft_first_last_line(char *line)
{
    int i;

    i = -1;
    while (line[++i] && line[i] != '\n')
        if (line[i] == '0')
            return (printf("Error\nMap is not surrounded by walls.\n"));
    return (0);
}

/*
 * Function will return nonzero if map spaces are not surrounded by walls.
 * map argument contains full configuration file.
 * i argument is the index of the line where the map starts.
 */
int ft_bounds(char **map, int i)
{
    static int j;

    if (ft_first_last_line(map[i]))
        return (1);
    while (map[++i])
    {
        j = 0;
        if (map[i][j] == '0')
            return (printf("Error\nMap is not surrounded by walls.\n"));
        if (!map[i + 1])
            break ;
        while (map[i][++j])
        {
            if (map[i][j + 1] == '\0' && map[i][j] == '0')
                return (printf("Error\nMap is not surrounded by walls.\n"));
            else if (map[i][j] == '0')
                if (ft_check_near(map, i, j) == 0)
                    return (printf("Error\nMap is not surrounded by walls.\n"));
        }
    }
    if (ft_first_last_line(map[i]))
        return (1);
    return (0);
}