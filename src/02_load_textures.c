/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_load_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:17:00 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/03 23:17:02 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/*
 * From the loaded image, generates a 2D grid of the texture, with the color
 * value as int for each pixel.
 * Returns 0 if succes, 1 if fails.
 */
static void	ft_gen_texel_grid(t_tex *texture)
{
	int		i;
	int		j;
	char	*location;

	i = -1;
	while (++i < texture->height)
	{
		j = -1;
		while (++j < texture->width)
		{
			location = texture->img->addr + (i * texture->img->linelen + j
					* (texture->img->bpp / 8));
			texture->texel[i][j] = *(int *)location;
		}
	}
	if (DEBUG == 1)
		ft_print_texel(texture);
}

/*
 * Loads each xpm file as img, and populates the parameters of the image.
 * Returns 0 if succes, 1 if fails.
 */
static int	ft_text_to_img(t_game *game, int i)
{
	t_tex	*tex;

	game->gui->texture[i] = (t_tex *)malloc(sizeof(t_tex));
	tex = game->gui->texture[i];
	if (tex == NULL)
		return (1);
	tex->img = (t_img *)malloc(sizeof(t_img));
	if (tex->img == NULL)
		return (2);
	tex->img->img = mlx_xpm_file_to_image(game->gui->mlx,
			game->map->params[i], &tex->width, &tex->height);
	if (tex->img == NULL)
		return (3);
	tex->img->addr = mlx_get_data_addr(tex->img->img, &tex->img->bpp,
			&tex->img->linelen, &tex->img->endian);
	ft_gen_texel_grid(tex);
	return (0);
}

/*
 * Checks if all previous steps succeded in loading functions.
 * Returns 0 if succes, 1 if fails.
 */
static int	ft_return_status(t_game *game, int error_flag, int i)
{
	int	j;

	if (error_flag != 0)
	{
		j = -1;
		while (++j < i)
		{
			if (game->gui->texture[j]->img->img)
				mlx_destroy_image(game->gui->mlx,
					game->gui->texture[j]->img->img);
			if (game->gui->texture[j]->img)
				free(game->gui->texture[j]->img);
			if (game->gui->texture[j])
				free(game->gui->texture[j]);
		}
		return (1);
	}
	return (0);
}

/*
 * Loads the 4 game textures.
 * Returns 0 if succes, 1 if fails.
 */
int	ft_load_textures(t_game *game)
{
	int	i;
	int	error_flag;

	error_flag = 0;
	i = -1;
	while (++i < 4 && error_flag == 0)
		error_flag = ft_text_to_img(game, i);
	return (ft_return_status(game, error_flag, i));
}
