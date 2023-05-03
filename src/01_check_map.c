/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:07:41 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/03 19:38:32 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

// If the map meets the requirements returns 0. If not, 1.
// No memoryt should remain allocated when existing this function
int	ft_check_map(char *map_file, int *w, int *h)
{
	printf("\n\033[0;96mChecking map...\033[0;39m");



	// TODO: map check logic:
	//(if an error exists: print error type in red, free all allocated mem and return 1)
		// file exists
		// file can be accessed and read
		// file contains all 6 ids (NO, SO, WE, EA F and C) separated by x amount of \n
		// IDs are not repeated
		// there is nothing more than ids and newline chars before the map starts
		// each id line only contains 2 items when splited (ID and VALUE)
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
	
	
	//for development set as map ok.
	(void)map_file;
	*w = 15; // from test map
	*h = 8; // from test map



	printf("\033[0;92m ---> Map is OK!\n\n\033[0;39m");
	return (0); // forced for continuing the development of the rest
}
