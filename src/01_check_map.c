/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:07:41 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/14 12:39:26 by mvalient         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int re_get_next_line(int fd, char **line)
{
    *line = ft_gnl(fd);
    return (ft_strlen(*line));
}

int allowed(char *line, int flag)
{
    static int  player = 0;
    int         i;

    if (flag == 1)
        return (player);
    i = -1;
    while (line[++i])
    {
        if (line[i] == '1' || line[i] == '0' || line[i] == ' ')
            printf("%c", line[i]);
        else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
        {
            if (player == 1)
                return (printf("There's more than one player on the map.\n"));
            player = 1;
            printf("%c", line[i]);
        }
        else if (line[i] == '\n')
            printf("%c", line[i]);
        else
            return (printf("There's an invalid character on the map.\n"));
    }
    return (0);
}

// If the map meets the requirements returns 0. If not, 1.
// No memoryt should remain allocated when existing this function
int	ft_check_map(char *map_file, int *w, int *h)
{
    static int  error;
    char        *map[20];
    static int  i;
    static int  j;
    int         fd;

    *w = 15; // from test map
    *h = 8; // from test map

    printf("\033[0;96mChecking map...\033[0;39m\n");
    fd = open(map_file, O_RDONLY);
    if (fd == -1)
        return(printf("Map file does not exist or cannot be accessed.\n"));
    while (re_get_next_line(fd, &map[i]))
        i++;
    close(fd);
    map[i] = NULL;
    j = 7;
    while   (map[++j])
    {
        error += allowed(map[j], 0);
        //error += bounds(map, j);
    }
    if (!allowed(NULL, 1))
        return (printf("There's no player on the map.\n"));
    while (i >= 0)
        free(map[i--]);
	return (error);
}

// TODO: map check logic:
//(if an error exists: print error type in red, free all allocated mem and return 1)
// file exists
// file can be accessed and read
// file contains all 6 ids (NO, SO, WE, EA F and C) separated by x amount of \n
// the paths are relative to the executable. CHECK THIS BEHAVIOUR when loading from different paths!!
// IDs are not repeated
// The IDs are all before the map
// there is nothing more than ids and newline chars before the map starts
// each id line only contains 2 items when splited (ID and VALUE)
// multiples spaces can be present
// Checking the map:
// Only 0, space, 1 and only 1 starting pos char (N, S, W ,E)
// GNL on each line:
// store the height of the
// The length of each line needs to be the same, unless addtinal spaces are required. This means ending in '1'
// In the process of sweeping lines, store the max width (without the new line char)
//the map file ends when the file ends
// if there are one or multiple empty new lines at the end of the file do not consider them
// if there are empty lines in between valid lines, consider them as spaces
// check the map is close (floodfill)


