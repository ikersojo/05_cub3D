/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:19:43 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/03 23:20:38 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/*
 * Interpolates to derive the y value to be extracted from the texture
 */
static int	ft_corrected_y(t_game *game, int x, int y)
{
	double	texture_h;
	double	wall_h;
	double	corrected_y;

	texture_h = game->gui->texture[game->rays.texture[x]]->height;
	wall_h = game->rays.wall_h[x];
	corrected_y = (texture_h / wall_h) * (y - (game->gui->height
				- game->rays.wall_h[x]) / 2);
	return ((int)floor(corrected_y));
}

/*
 * Interpolates to derive the y value to be extracted from the texture
 */
static int	ft_corrected_x(t_game *game, int x)
{
	double	texture_w;
	double	location_in_square;
	double	corrected_x;

	texture_w = game->gui->texture[game->rays.texture[x]]->width;
	if (game->rays.texture[x] == 0 || game->rays.texture[x] == 1)
		location_in_square = (game->rays.x[x] - floor(game->rays.x[x]));
	else
		location_in_square = (game->rays.y[x] - floor(game->rays.y[x]));
	corrected_x = texture_w * location_in_square;
	return ((int)floor(corrected_x));
}

/*
 * Generates the color of the wall interpolating each texture, depending on the
 * hitting plane of each ray x
 */
static int	ft_color_from_texture(t_game *game, int x, int y)
{
	int		color;
	int		y_val;
	int		x_val;

	if (game->rays.texture[x] > 3)
		return (0x001111111);
	y_val = ft_corrected_y(game, x, y);
	x_val = ft_corrected_x(game, x);
	color = game->gui->texture[game->rays.texture[x]]->texel[y_val][x_val];
	return (color);
}

/*
 * Generates the color of the wall (untextured), depending on the hitting
 * plane of each ray x
 */
static int	ft_untextured_color(t_game *game, int x)
{
	int	color;

	if (game->rays.texture[x] == 0)
		color = 0x00333333;
	else if (game->rays.texture[x] == 1)
		color = 0x00333333;
	else if (game->rays.texture[x] == 2)
		color = 0x00999999;
	else if (game->rays.texture[x] == 3)
		color = 0x00999999;
	else
		color = 0x001111111;
	return (color);
}

/*
 * Puts the corresponding pixels to the image of each wall.
 */
void	ft_draw_walls(t_game *game)
{
	int	x;
	int	y;
	int	color;

	ft_raycast(game);
	x = -1;
	while (++x < game->gui->width)
	{
		y = ((game->gui->height - game->rays.wall_h[x]) / 2) - 1;
		while (++y < game->rays.wall_h[x] + (game->gui->height
				- game->rays.wall_h[x]) / 2)
		{
			if (y > 0 && y < game->gui->height)
			{
				if (TEX_ON == 1)
					color = ft_color_from_texture(game, x, y);
				else
					color = ft_untextured_color(game, x);
				ft_put_pixel(game->gui->img, x, y, color);
			}
		}
	}
}
