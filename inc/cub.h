/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <yerkiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:09:22 by yerkiral          #+#    #+#             */
/*   Updated: 2023/02/02 12:09:23 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define CUBERR -1

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_E 14
# define KEY_M 46
# define KEY_Z 6
# define KEY_X 7

# define RO_SPEED 0.04
# define MV_SPEED 0.06

# define X 0
# define Y 1

# define CONFIG_FILE "config/config.cubc"

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

# include "mlx.h"
# include "libft.h"
# include "libft_printer.h"

typedef struct s_map	t_map;
typedef struct s_game	t_game;
typedef struct s_data	t_data;
typedef struct s_input	t_input;
typedef struct s_dvec	t_dvec;
typedef struct s_ivec	t_ivec;
typedef struct s_dda	t_dda;
typedef struct s_debug	t_debug;
typedef struct s_tex	t_tex;

typedef struct s_map
{
	char	map_file[96];
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**a;
	int		f_color;
	int		c_color;
	int		height;
	int		width;
	char	**map;
}	t_map;

typedef struct s_ivec
{
	int	x;
	int	y;
}	t_ivec;

typedef struct s_dvec
{
	double	x;
	double	y;
}	t_dvec;

typedef struct s_dda
{
	t_dvec		ray_dir;
	t_dvec		ray_len;
	t_dvec		dis_delta;
	t_ivec		pos_map;
	t_ivec		step_dir;
	bool		side;
	double		current_ray_len;
}	t_dda;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_player
{
	t_dvec	pos;
	t_dvec	dir;
}	t_player;

typedef struct s_debug
{
	bool		mode;
	t_dvec		ray_coll[10000];
}	t_debug;

typedef struct s_tex
{
	t_data	data;
	int		x;
	int		y;
}	t_tex;

typedef struct s_input
{
	bool	key_a_down;
	bool	key_s_down;
	bool	key_d_down;
	bool	key_w_down;
	bool	key_q_down;
	bool	key_e_down;
}	t_input;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**config;
	char		*title;	
	int			width;
	int			height;
	int			cell_size;
	int			space;
	bool		render_minimap;
	t_dvec		plane;
	t_map		map;
	t_input		input;
	t_player	player;
	t_dda		dda;
	t_data		data;
	t_debug		debug;
	t_tex		tex[4];
}	t_game;

// CONFIG
void	config_reset_buffer(char *buffer);
char	*config_find_value(t_game *cub, char *name);
int		config_read_file(char *buffer);
int		config_init(t_game *cub);

// MAP
int		buffer_check_for_multiple_nwse(char **buffer);
int		map_fill_name(char *file, char map_file[96]);
int		map_file_format(char *file);
int		map_init(char *map_file, t_map *map);
int		map_fill_map(t_map *map);
int		map_floor_color(t_map *map, char *buffer);
int		map_ceiling_color(t_map *map, char *buffer);
int		map_reset_buffer(char *buffer);
int		map_compare(char *u);
int		open_map(char *u);
int		map_apply_function(t_map *map, char *u, int funCode);
char	*connect_map(char *map, int max);

// WIN
int		win_init(t_game *cub);

// IMG
int		rgb(int t, int r, int g, int b);
int		img_init(t_game *cub);

// INPUT
int		input_init(t_game *cub);
int		input_reg(t_game *cub);
int		input_mouse(t_game *cub);
int		input_key_up(int key_id, t_game *cub);
int		input_key_down(int key_id, t_game *cub);

// RENDER
void	render_pixel_put(t_data *data, int x, int y, int color);
void	render_reset_image(t_game *cub, int color);
void	render_line_put(t_game *cub, t_ivec start, t_ivec end);
void	render_cell_put(t_game *cub, int x, int y, int color);
void	render_dda_calc_ray_data(t_game *cub, double cam_x);
void	render_dda_calc_wall_height(t_game *cub, int ray_count);
void	render_dda_calc_first_step(t_game *cub);
void	render_dda_calc_ray_len(t_game *cub, int ray_count);
void	render_dda_wall_draw(t_game *cub, int rc, int wall_d[3], double p_wall);
int		render_ray(t_game *cub);
int		render_floor(t_game *cub);
int		render_ceiling(t_game *cub);
int		render_minimap(t_game *cub);
int		render_loop(t_game *cub);
int		render_init(t_game *cub);

// GAME
int		game_start(char *map_file);
int		game_end(t_game *cub);

// PLAYER
int		player_init(t_game *cub);
int		player_rotate_right(t_game *cub);
int		player_rotate_left(t_game *cub);
int		player_move_up(t_game *cub);
int		player_move_down(t_game *cub);
int		player_move_lr(t_game *cub, bool left);

// DEBUG
void	debug_outputs(t_game *cub);
void	debug_output_pdata(t_game *cub);
void	debug_output_cdata(t_game *cub);

#endif