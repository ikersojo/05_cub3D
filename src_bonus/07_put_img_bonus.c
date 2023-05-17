/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_put_img_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:21:12 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/17 22:35:50 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	ft_color_minimap(t_game *game, int i, int j, int first_pixel)
{
	int	k;
	int	z;
	int	map_scale;
	int	color;

	map_scale = (ft_min(SCREEN_H, SCREEN_W) / ft_max(game->map->map_w,
				game->map->map_h)) / 4;
	if (i == game->map->map_h - (int)floor(game->player->y_pos) - 1
		&& j == (int)floor(game->player->x_pos))
		color = 999;
	else if (game->map->grid[i][j] != '1')
		color = 110011;
	else
		color = 0;
	z = -1;
	while (++z < map_scale)
	{
		k = -1;
		while (++k < map_scale)
			ft_put_pixel(game->gui->img, j * map_scale + z + first_pixel,
				i * map_scale + k + first_pixel, color);
	}
}

static void	ft_gen_minimap(t_game *game)
{
	int	i;
	int	j;
	int	first_pixel;

	first_pixel = 10;
	i = -1;
	while (++i < game->map->map_h)
	{
		j = -1;
		while (++j < game->map->map_w)
			ft_color_minimap(game, i, j, first_pixel);
	}
}

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
	ft_gen_minimap(game);
	mlx_put_image_to_window(game->gui->mlx, game->gui->win,
		game->gui->img->img, 0, 0);
	mlx_destroy_image(game->gui->mlx, game->gui->img->img);
}
