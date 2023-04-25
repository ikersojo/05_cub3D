/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:35:41 by isojo-go          #+#    #+#             */
/*   Updated: 2023/04/25 23:37:44 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	ft_rotate_ray(t_game *game, int i, double angle)
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
	while (++i < SCREEN_W)
	{
		ft_rotate_ray(game, i, (-FOD / SCREEN_W));
	}
}


// void	ft_get_rays_dist(t_game *game)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < SCREEN_W)
// 	{
// 		ft_get_dist(game, );
// 	}
// }

static int	check_coords(t_game *game, double x, double y) // en vez de devolver uno, que devuelva un numero distinto por direccion contra la que choca
{
	char	**grid;
	int		i;
	int		j;

	grid = game->map->grid;
	i = game->map->map_h - (int)floor(y);
	j = (int)floor(x);
	if (grid[i][j] == '1')
		return (1);
	return (0);
}

void	ft_get_rays_dist(t_game *game)
{
	int i;
	int	j;
	double	x;
	double	y;

	i = -1;
	while (++i < SCREEN_W)
	{
		j = -1;
		while (++j < SCREEN_H * 100) // no es lo más óptimo...
		{
			x = (game->player->x_pos + (game->rays.dir[i].x) * j * 0.1);
			y = (game->player->y_pos + (game->rays.dir[i].y) * j * 0.1);
			if(check_coords(game, x, y) == 1)
				break ;
		}
		game->rays.dist[i] = sqrt(pow((x - game->player->x_pos), 2)
			+ pow((y - game->player->y_pos), 2));
		// printf("DEBUG: x = %f, y = %f, dist = %f\n", x, y, game->rays.dist[i]); // DEBUG
	}
}

void	ft_get_walls(t_game *game)
{
	int	i;

	i = -1;
	while (++i < SCREEN_W)
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

	i = -1;
	while (++i < game->gui->width)
	{
		if (game->gui->height <= game->rays.wall_h[i])
		{
			j = -1;
			while (++j < game->gui->height)
				ft_put_pixel(game->gui->img, i, j, 0x00111111);
		}
		else
		{
			j = (game->gui->height - game->rays.wall_h[i]) / 2;
			while (++j < (game->rays.wall_h[i] + game->gui->height) / 2)
				ft_put_pixel(game->gui->img, i, j, 0x00111111);
		}
	}


	if (DEBUG == 1)
		ft_print_rays(game);
}
