/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   99_aux_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:35:51 by isojo-go          #+#    #+#             */
/*   Updated: 2023/04/25 23:37:44 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	ft_close_game(t_game *game)
{
	ft_free_all(game);
	printf("Exiting game...\n");
	exit(EXIT_SUCCESS);
}
