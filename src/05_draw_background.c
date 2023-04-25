/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_draw_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:35:35 by isojo-go          #+#    #+#             */
/*   Updated: 2023/04/25 23:37:44 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	ft_gen_color_int(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char *location;

	location = img->addr + (y * img->linelen + x * (img->bpp / 8));
	*(unsigned int *)location = color;
}

void	ft_draw_background(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->gui->width)
	{
		j = -1;
		while (++j < (game->gui->height / 2 + 1))
			ft_put_pixel(game->gui->img, i, j, ft_gen_color_int(game->map->c_r,
				game->map->c_g, game->map->c_b));
		while (++j < (game->gui->height))
			ft_put_pixel(game->gui->img, i, j, ft_gen_color_int(game->map->f_r,
				game->map->f_g, game->map->f_b));
	}
}