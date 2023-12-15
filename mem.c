/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:34:22 by vnaslund          #+#    #+#             */
/*   Updated: 2023/11/09 17:25:53 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_handler(char *msg, t_data *data)
{
	if (data->allocated_map)
		ft_free_matrix(data, (void **)data->map);
	free(data);
	ft_printf("Error\n%s\n", msg);
	exit(1);
}

void	ft_free_matrix(t_data *data, void **matrix)
{
	int	i;

	i = 0;
	while (i < data->rows && matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	ft_end_game(t_game *game)
{
	ft_free_matrix(game->data, (void **)game->map);
	free(game->textures);
	free(game->image);
	free(game->data);
	free(game);
}
