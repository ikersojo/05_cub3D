/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:18:44 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/03 23:19:27 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/*
 * Gets the direction of the next ray
 */
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

/*
 * Derive the direction of all the rays to be casted. Starts with the first
 * one and then derives all the rest with a subfunction one by one.
 */
static void	ft_get_rays_dir(t_game *game)
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

/*
 * Get the distance to the collision of all the rays casted, using
 * the direction.
 */
static void	ft_get_rays_dist(t_game *game)
{
	int		i;
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
			if (game->rays.texture[i] != 10)
				break ;
		}
		game->rays.dist[i] = sqrt(pow((x - game->player->x_pos), 2)
				+ pow((y - game->player->y_pos), 2));
		game->rays.x[i] = x;
		game->rays.y[i] = y;
	}
}

/*
 * Derive the height of the wall hitted by the all the rays casted, using the
 * distance to the wall.
 */
static void	ft_get_walls(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->gui->width)
	{
		game->rays.wall_h[i] = (int)(WALL_H / (game->rays.dist[i]
					* cos(game->rays.angle[i])));
	}
}

/*
 * Launch all the steps to derive the location of the collision and
 * height of the walls.
 */
void	ft_raycast(t_game *game)
{
	ft_get_rays_dir(game);
	ft_get_rays_dist(game);
	ft_get_walls(game);
	if (DEBUG == 1)
		ft_print_rays(game);
}
