/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:41:31 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/09 17:36:14 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collect(t_game *game)
{
	if (game->map[game->image->player->instances->y / PX_SIZE]
		[game->image->player->instances->x / PX_SIZE] == COLLECTIBLE)
	{
		if (game->collected == game->data->collectibles)
			return ;
		ft_remove_collectible(game);
		game->map[game->image->player->instances->y / PX_SIZE]
		[game->image->player->instances->x / PX_SIZE] = EMPTY;
		game->collected++;
		if (game->collected == game->data->collectibles)
			game->image->exit->instances->enabled = false;
	}
	if ((game->map[game->image->player->instances->y / PX_SIZE]
			[game->image->player->instances->x / PX_SIZE] == EXIT)
		&& (game->collected == game->data->collectibles))
		mlx_close_window(game->mlx);
}

void	ft_remove_collectible(t_game *game)
{
	int	i;
	int	total;

	total = game->data->collectibles;
	i = 0;
	while (i < total)
	{
		if ((game->image->collectible->instances[i].y
				== game->image->player->instances->y)
			&& (game->image->collectible->instances[i].x
				== game->image->player->instances->x)
			&& game->image->collectible->instances[i].enabled)
		{
			game->image->collectible->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}
