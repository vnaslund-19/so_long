/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:39:57 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/09 17:25:20 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_game	*game;

	if (argc != 2)
		return (ft_printf("Exactly 1 map should be passed as argument"));
	data = malloc(sizeof(t_data));
	if (!data)
		exit_handler("Malloc error", data);
	ft_read_map(data, argv);
	game = malloc(sizeof(t_game));
	if (!game)
		exit_handler("Malloc error", data);
	ft_init_game(game, data);
	mlx_terminate(game->mlx);
	ft_end_game(game);
	return (0);
}
