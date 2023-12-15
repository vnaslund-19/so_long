/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:35:45 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/09 16:48:28 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_action(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.action == MLX_RELEASE
		&& (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP))
		ft_move_up(game);
	if (keydata.action == MLX_RELEASE
		&& (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN))
		ft_move_down(game);
	if (keydata.action == MLX_RELEASE
		&& (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT))
		ft_move_left(game);
	if (keydata.action == MLX_RELEASE
		&& (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT))
		ft_move_right(game);
	if (keydata.action == MLX_RELEASE && keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	ft_collect(game);
}

void	ft_move_up(t_game *game)
{
	if (game->map[game->image->player->instances->y / PX_SIZE - 1]
		[game->image->player->instances->x / PX_SIZE] != WALL)
	{
		game->image->player->instances->y -= PX_SIZE;
		game->move_count++;
		ft_printf("MOVES: %d\n", game->move_count);
	}
}

void	ft_move_down(t_game *game)
{
	if (game->map[game->image->player->instances->y / PX_SIZE + 1]
		[game->image->player->instances->x / PX_SIZE] != WALL)
	{
		game->image->player->instances->y += PX_SIZE;
		game->move_count++;
		ft_printf("MOVES: %d\n", game->move_count);
	}
}

void	ft_move_left(t_game *game)
{
	if (game->map[game->image->player->instances->y / PX_SIZE]
		[game->image->player->instances->x / PX_SIZE - 1] != WALL)
	{
		game->image->player->instances->x -= PX_SIZE;
		game->move_count++;
		ft_printf("MOVES: %d\n", game->move_count);
	}
}

void	ft_move_right(t_game *game)
{
	if (game->map[game->image->player->instances->y / PX_SIZE]
		[game->image->player->instances->x / PX_SIZE + 1] != WALL)
	{
		game->image->player->instances->x += PX_SIZE;
		game->move_count++;
		ft_printf("MOVES: %d\n", game->move_count);
	}
}
