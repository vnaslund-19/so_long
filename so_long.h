/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:40:28 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/09 17:36:17 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdbool.h>
# include <fcntl.h>

# define PX_SIZE 64

# define GAME_NAME "Welcome to Freddy Fazbear's Pizza"

# define EMPTY '0'
# define WALL '1'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'

typedef struct s_data
{
	char	**map;
	int		rows;
	int		cols;
	int		p_position[2];
	int		collectibles;
	int		players;
	int		exits;
	int		found;
	bool	allocated_map;
}			t_data;

typedef struct s_game
{
	struct s_textures	*textures;
	struct s_images		*image;
	struct s_data		*data;
	mlx_t				*mlx;
	int					width;
	int					height;
	int					move_count;
	int					collected;
	char				**map;
}						t_game;

typedef struct s_textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*collectible;
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
	mlx_texture_t	*open_exit;
}					t_textures;

typedef struct s_images
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*collectible;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*open_exit;
}				t_images;

// Playable check
void	ft_read_map(t_data *data, char **argv);
void	ft_map_check(t_data *data, char **map);
int		ft_allocate_lines(t_data *data, char **argv);
void	ft_playable_check(t_data *data, char **map);
void	init_explore(t_data *data, int ***visited);
void	explore(t_data *data, int x, int y, int **visited);
void	pec_config_check(t_data *data, char **map);

// Graphic programming with MLX42
void	ft_init_game(t_game *game, t_data *data);
void	ft_get_textures(t_game *game);
void	ft_get_images(t_game *game);
void	draw_map(t_data *data, t_game *game, t_images *image);
void	draw_floor(t_data *data, t_game *game, t_images *image);

// Key hook
void	ft_action(mlx_key_data_t keydata, void *param);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
void	ft_collect(t_game *game);
void	ft_remove_collectible(t_game *game);

// Memory and error handling
void	ft_free_matrix(t_data *data, void **matrix);
void	ft_end_game(t_game *game);
void	exit_handler(char *msg, t_data *data);

#endif
