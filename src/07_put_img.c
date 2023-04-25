/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:35:46 by isojo-go          #+#    #+#             */
/*   Updated: 2023/04/25 23:37:44 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	ft_put_img(t_game *game)
{
	game->gui->img->img = mlx_new_image(game->gui->mlx, SCREEN_W, SCREEN_H);
	game->gui->img->addr = mlx_get_data_addr(game->gui->img->img,
		&game->gui->img->bpp, &game->gui->img->linelen, &game->gui->img->endian);
	ft_draw_background(game);
	ft_draw_walls(game);
	mlx_put_image_to_window(game->gui->mlx, game->gui->win, game->gui->img->img, 0, 0);
	mlx_destroy_image(game->gui->mlx, game->gui->img->img);
}
