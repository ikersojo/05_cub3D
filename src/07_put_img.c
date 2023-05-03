/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:21:12 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/03 23:21:15 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/*
 * Generates an image of all grey pixels
 */
static void	ft_greyscreen(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->gui->width)
	{
		j = -1;
		while (++j < (game->gui->height))
			ft_put_pixel(game->gui->img, i, j, 0x00333333);
	}
}

/*
 * Puts the image to the screen
 */
void	ft_put_img(t_game *game)
{
	game->gui->img->img = mlx_new_image(game->gui->mlx, SCREEN_W, SCREEN_H);
	game->gui->img->addr = mlx_get_data_addr(game->gui->img->img,
			&game->gui->img->bpp, &game->gui->img->linelen,
			&game->gui->img->endian);
	ft_draw_background(game);
	if (ft_inmap(game) == 1)
		ft_draw_walls(game);
	else
		ft_greyscreen(game);
	mlx_put_image_to_window(game->gui->mlx, game->gui->win,
		game->gui->img->img, 0, 0);
	mlx_destroy_image(game->gui->mlx, game->gui->img->img);
}
