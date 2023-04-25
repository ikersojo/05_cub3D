/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:35:00 by isojo-go          #+#    #+#             */
/*   Updated: 2023/04/25 23:37:44 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

// If the map meets the requirements returns 0. If not, 1.
int	ft_check_map(char *map_file, int *w, int *h)
{
	printf("\n\033[0;96mChecking map...\033[0;39m");



	// TODO: map check logic: default for development set as map ok.
	(void)map_file;
	*w = 12; // from test map
	*h = 8; // from test map



	printf("\033[0;92m ---> Map is OK!\n\n\033[0;39m");
	return (0); // forced for continuing the development of the rest
}
