/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:07:06 by isojo-go          #+#    #+#             */
/*   Updated: 2023/05/18 07:53:03 by mvalient         ###   ########.fr       */
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
		printf("\033[0;96mChecking map...\033[0;39m\n");
		if (ft_check_map(*(argv + 1), &map_w, &map_h))
			ft_exit_w_error("The map file is not valid\n");
		game = ft_initialize_game(*(argv + 1), map_w, map_h);
		if (DEBUG == 1)
			ft_print_game_data(game);
		mlx_hook(game->gui->win, ON_DESTROY, 1L << 17, ft_on_destroy, &game);
		mlx_hook(game->gui->win, ON_KEYDOWN, 0, ft_on_keydown, &game);
		printf("Initializing GUI...\n");
		ft_put_img(game);
		mlx_loop(game->gui->mlx);
	}
	else
		ft_exit_w_error("syntax: ./bin/cub3D xxxxxx.cub\n");
	return (EXIT_SUCCESS);
}
