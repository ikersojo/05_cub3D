/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_load_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:12:30 by isojo-go          #+#    #+#             */
/*   Updated: 2023/04/29 11:40:02 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	ft_load_textures(t_game *game)
{
	int	i;
	int	j;
	int	error_flag;

	error_flag = 0;
	i = -1;
	while (++i < 4)
	{
		game->gui->texture[i] = (t_tex *)malloc(sizeof(t_tex));
		if (game->gui->texture[i] == NULL)
		{
				error_flag = 1;
				break;
		}

		game->gui->texture[i]->img = (t_img *)malloc(sizeof(t_img));
		if (game->gui->texture[i]->img == NULL)
		{
				error_flag = 2;
				break;
		}

		game->gui->texture[i]->img->img = mlx_xpm_file_to_image(game->gui->mlx,
			game->map->params[i], &game->gui->texture[i]->width,
			&game->gui->texture[i]->height);
		if (game->gui->texture[i]->img == NULL)
		{
				error_flag = 3;
				break;
		}

		// en este punto tengo las texturas cargadas

	}



	// exiting without garbage
	j = -1;
	if (error_flag == 1)
	{
		while (++j < i - 1)
			free(game->gui->texture[j]);
	}
	else if (error_flag == 2)
	{
		while (++j < i - 1)
			free(game->gui->texture[j]->img);
		j = -1;
		while (++j < i)
			free(game->gui->texture[j]);
	}
	else if (error_flag == 3)
	{
		while (++j < i - 1)
			mlx_destroy_image(game->gui->mlx, game->gui->texture[j]->img);
		j = -1;
		while (++j < i)
			free(game->gui->texture[j]->img);
		j = -1;
		while (++j < i)
			free(game->gui->texture[j]);
	}
	if (error_flag != 0)
		return (1);
	return (0);

}