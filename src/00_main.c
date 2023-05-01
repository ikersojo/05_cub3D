/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:34:53 by isojo-go          #+#    #+#             */
/*   Updated: 2023/04/29 11:27:15 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int		map_w;
	int		map_h;

	if (argc == 2 && ft_ext_ok(*(argv + 1), ".cub"))
	{
		if (ft_check_map(*(argv + 1), &map_w, &map_h) == 1)
			ft_exit_w_error("The map file is not valid\n");
		game = ft_initialize_game(*(argv + 1), map_w, map_h);
		if (DEBUG == 1)
			ft_print_game_data(game);
		game->gui = ft_initialize_gui();
		if (game->gui == NULL)
		{
			ft_free_map(game->map);
			free(game->player);
			free (game);
			ft_exit_w_error("errno");
		}
		

		if (ft_load_textures(game) == 1)
		{
			ft_free_all_but_textures(game);
			ft_exit_w_error("errno");
		}


		mlx_hook(game->gui->win, ON_DESTROY, 1L << 17, ft_on_destroy, &game);
		mlx_hook(game->gui->win, ON_KEYDOWN, 0, ft_on_keydown, &game);

		// (confirmar necesidad o no de las siguientes lineas:)
			// mlx_hook(game->gui->win, ON_KEYUP, 0, ft_on_keyup, &game);
			// mlx_loop_hook(game->gui->mlx, ft_on_idle, &game);

		printf("Initializing GUI...\n");
		ft_put_img(game);
		mlx_loop(game->gui->mlx);
	}
	else
		ft_exit_w_error("syntax: ./bin/cub3D xxxxxx.cub\n");
	return (EXIT_SUCCESS);
}

/*

TOOD LIST:

IMPROVEMENTS:
optimize collision search algorithm

NEEDED FEATURES:
(Martin) Check map file
move aligned with the camera
return colision direction to apply the correct texture
Load textures
Replace current draw Wall function with the textured one

*/

