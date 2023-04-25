/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_init_gui.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:35:18 by isojo-go          #+#    #+#             */
/*   Updated: 2023/04/25 23:37:44 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

t_gui	*ft_initialize_gui(void)
{
	t_gui	*gui;

	gui = (t_gui *)malloc(sizeof(t_gui));
	if (gui == NULL)
		return (NULL);
	gui->mlx = mlx_init();
	if (gui->mlx == NULL)
		return (NULL);
	gui->width = SCREEN_W;
	gui->height = SCREEN_H;
	gui->win = mlx_new_window(gui->mlx, gui->width, gui->height, "cub3D");
	if (gui->win == NULL)
	{
		free (gui);
		return (NULL);
	}
	gui->img = (t_img *)malloc(sizeof(t_img));
	if (gui->img == NULL)
	{
		mlx_destroy_window(gui->mlx, gui->win);
		free (gui);
		return (NULL);
	}
	return (gui);
}
