/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:35:41 by isojo-go          #+#    #+#             */
/*   Updated: 2023/04/30 09:12:27 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	ft_rotate_ray(t_game *game, int i, double angle)
{
	game->rays.dir[i].x = game->rays.dir[i - 1].x * cos(angle)
		- game->rays.dir[i - 1].y * sin(angle);
	game->rays.dir[i].y = game->rays.dir[i - 1].x * sin(angle)
		+ game->rays.dir[i - 1].y * cos(angle);
	game->rays.dir[i].x /= hypot(game->rays.dir[i].x, game->rays.dir[i].y);
	game->rays.dir[i].y /= hypot(game->rays.dir[i].x, game->rays.dir[i].y);
	game->rays.angle[i] = game->rays.angle[i - 1] + angle;
}

void	ft_get_rays_dir(t_game *game)
{
	int	i;

	i = 0;
	game->rays.dir[i].x = game->player->vx * cos(FOD / 2)
		- game->player->vy * sin(FOD / 2);
	game->rays.dir[i].y = game->player->vx * sin(FOD / 2)
		+ game->player->vy * cos(FOD / 2);
	game->rays.dir[i].x /= hypot(game->rays.dir[i].x, game->rays.dir[i].y);
	game->rays.dir[i].y /= hypot(game->rays.dir[i].x, game->rays.dir[i].y);
	game->rays.angle[i] = FOD / 2;
	while (++i < game->gui->width)
		ft_rotate_ray(game, i, (-FOD / game->gui->width));
}

void	ft_get_rays_dist(t_game *game) // TODO: optimizar algoritmo
{
	int 	i;
	int		j;
	double	x;
	double	y;
	int		max;

	max = ft_max(game->map->map_w, game->map->map_h) * 100;
	i = -1;
	while (++i < game->gui->width)
	{
		game->rays.texture[i] = 0;
		j = -1;
		while (++j < max)
		{
			x = (game->player->x_pos + (game->rays.dir[i].x) * j * 0.01);
			y = (game->player->y_pos + (game->rays.dir[i].y) * j * 0.01);
			game->rays.texture[i] = check_coords(game, x, y);
			if(game->rays.texture[i] != 0)
				break ;
		}
		game->rays.dist[i] = sqrt(pow((x - game->player->x_pos), 2)
			+ pow((y - game->player->y_pos), 2));
	}
}

void	ft_get_walls(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->gui->width)
	{
		game->rays.wall_h[i] = WALL_H / (game->rays.dist[i]
			* cos(game->rays.angle[i]));
	}
}

void	ft_draw_walls(t_game *game) // with colors, not images
{
	ft_get_rays_dir(game);
	ft_get_rays_dist(game);
	ft_get_walls(game);


	int	i;
	int	j;
	int	color;


	i = -1;
	while (++i < game->gui->width)
	{
		if (game->rays.texture[i] == 1)
			color = 0x00333333;
			// color = 0x00ffff00;
		else if (game->rays.texture[i] == 2)
			color = 0x00333333;
			// color = 0x00ff0000;
		else if (game->rays.texture[i] == 3)
			color = 0x00999999;
			// color = 0x00990099;
		else if (game->rays.texture[i] == 4)
			color = 0x00999999;
			// color = 0x00ffcc00;
		else
			color = 0x00000000;


		if (game->gui->height <= game->rays.wall_h[i])
		{
			j = -1;
			while (++j < game->gui->height)
				ft_put_pixel(game->gui->img, i, j, color);
		}
		else
		{
			j = (game->gui->height - game->rays.wall_h[i]) / 2;
			while (++j < (game->rays.wall_h[i] + game->gui->height) / 2)
				ft_put_pixel(game->gui->img, i, j, color);
		}
	}


	// if (DEBUG == 1)
	// 	ft_print_rays(game);
}



