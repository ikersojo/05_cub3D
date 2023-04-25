/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:19:29 by isojo-go          #+#    #+#             */
/*   Updated: 2023/04/25 23:33:42 by isojo-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// ---- LIBRARIES ---- //
# include "../lib/LIBFT/inc/libft.h"
# include "../lib/LIBMLX/inc/mlx.h"
# include <fcntl.h>
# include <math.h>


// ---- MACROS ---- //

// Debug Mode
# define DEBUG		1

// Game Parameters
# define SCREEN_W	1280
# define SCREEN_H	720
# define WALL_H		1000
# define STEP		0.2
# define ROT_STEP	0.05
# define FOD		M_PI / 3

// Key Codes for MacOS
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_LEFT	123
# define KEY_RIGHT	124

// MacOS Events
# define ON_KEYDOWN		2
# define ON_KEYUP 		3
# define ON_MOUSEDOWN	4
# define ON_MOUSEUP		5
# define ON_MOUSEMOVE	6
# define ON_EXPOSE		12
# define ON_DESTROY		17


// ---- Custom Structs ---- //

// 2D vector definition
typedef struct s_vector
{
	double	x;
	double	y;
}			t_vector;

// store the infomation to map
typedef struct s_rays
{
	t_vector	dir[SCREEN_W];
	double		angle[SCREEN_W];
	double		dist[SCREEN_W];
	double		wall_h[SCREEN_W];
}				t_rays;

// store all information about the image to be displayed
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		linelen;
	int		endian;
	int		width;
	int		height;
}			t_img;

// store all information about the graphic window
typedef struct s_gui
{
	void	*mlx;
	void	*win;
	t_img	*img;
	int		width;
	int		height;
}			t_gui;

// store all information about the map
typedef struct s_map
{
	int		mapfd;
	char	*params[6];
		// char	*no_path;
		// char	*so_path;
		// char	*we_path;
		// char	*ea_path;
		// char	*floor;
		// char	*ceiling;

	int		f_r;
	int		f_g;
	int		f_b;

	int		c_r;
	int		c_g;
	int		c_b;

	char	**grid;
	int		map_w;
	int		map_h;

	int		start_x;
	int		start_y;
	char	start_char;

}			t_map;

// store all information about the player
typedef struct s_player
{
	double	x_pos;
	double	y_pos;
	double	vx;
	double	vy;
}			t_player;

// store all information about the game
typedef struct s_game
{
	t_gui		*gui;
	t_map		*map;
	t_player	*player;
	t_rays		rays;
}				t_game;


// ---- CROSS FILE FUNCTIONS ---- //

// 01 Confim map validity (and extract WxH)
int	ft_check_map(char *map_file, int *w, int *h);

// 02 Initialize game
t_game	*ft_initialize_game(char *map_file, int map_w, int map_h);
t_map	*ft_load_map(char *map_file, int map_w, int map_h);

// 03 Define events on game
int		ft_on_destroy(int keycode, void *param);
int		ft_on_keydown(int keycode, void *param);
int		ft_on_idle(int keycode, void *param);




t_gui	*ft_initialize_gui(void);
t_img	*ft_init_img(t_game *game);

// 04 draw pixels to image

int	ft_gen_color_int(int r, int g, int b);
void	ft_put_pixel(t_img *img, int x, int y, int color);


void	ft_draw_background(t_game *game);
void	ft_draw_walls(t_game *game);
// put to screen
void	ft_put_img(t_game *game);



// Auxiliary Functions
void	ft_close_game(t_game *game);

// Debugging Information to console
void	ft_print_player_data(t_player *player);
void	ft_print_map_data(t_map *map);
void	ft_print_game_data(t_game *game);
void	ft_print_rays(t_game *game);
#
// Free functions
t_map	*ft_closefd_and_free_map(t_map *map);
void	ft_free_map(t_map *map);
void	ft_free_all(t_game *game);

#endif
