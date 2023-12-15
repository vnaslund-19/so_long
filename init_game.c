/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:01:05 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/09 16:58:06 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_game(t_game *game, t_data *data)
{
	game->width = data->cols * PX_SIZE;
	game->height = data->rows * PX_SIZE;
	game->move_count = 0;
	game->collected = 0;
	game->map = data->map;
	game->data = data;
	game->mlx = mlx_init(game->width, game->height, GAME_NAME, false);
	if (!game->mlx)
		exit_handler("Mlx error", data);
	ft_get_textures(game);
	ft_get_images(game);
	draw_map(data, game, game->image);
	mlx_key_hook(game->mlx, &ft_action, game);
	mlx_loop(game->mlx);
}

void	ft_get_textures(t_game *game)
{
	game->textures = ft_calloc(1, sizeof(t_textures));
	if (!game->textures)
		exit_handler("ft_calloc error", game->data);
	game->textures->floor = mlx_load_png("./textures/empty.png");
	if (!game->textures->floor)
		exit_handler("floor.png error", game->data);
	game->textures->wall = mlx_load_png("./textures/wall.png");
	if (!game->textures->wall)
		exit_handler("wall.png error", game->data);
	game->textures->collectible = mlx_load_png("./textures/collectible.png");
	if (!game->textures->collectible)
		exit_handler("collectible.png error", game->data);
	game->textures->player = mlx_load_png("./textures/player.png");
	if (!game->textures->player)
		exit_handler("player.png error", game->data);
	game->textures->exit = mlx_load_png("./textures/exit.png");
	if (!game->textures->exit)
		exit_handler("exit.png error", game->data);
	game->textures->open_exit = mlx_load_png("./textures/open_exit.png");
	if (!game->textures->open_exit)
		exit_handler("open_exit.png error", game->data);
}

void	ft_get_images(t_game *game)
{
	game->image = ft_calloc(1, sizeof(t_images));
	if (!game->image)
		exit_handler("ft_calloc error", game->data);
	game->image->floor = mlx_texture_to_image(game->mlx, game->textures->floor);
	game->image->wall = mlx_texture_to_image(game->mlx, game->textures->wall);
	game->image->collectible = mlx_texture_to_image(game->mlx,
			game->textures->collectible);
	game->image->player = mlx_texture_to_image(game->mlx,
			game->textures->player);
	game->image->exit = mlx_texture_to_image(game->mlx, game->textures->exit);
	game->image->open_exit = mlx_texture_to_image(game->mlx,
			game->textures->open_exit);
	mlx_delete_texture(game->textures->floor);
	mlx_delete_texture(game->textures->wall);
	mlx_delete_texture(game->textures->collectible);
	mlx_delete_texture(game->textures->player);
	mlx_delete_texture(game->textures->exit);
	mlx_delete_texture(game->textures->open_exit);
}
