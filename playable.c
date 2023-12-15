/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:46:38 by vnaslund          #+#    #+#             */
/*   Updated: 2023/12/15 11:59:50 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_check(t_data *data, char **map)
{
	int	i;
	int	first_len;
	int	len;

	first_len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len != first_len)
			exit_handler("Map error: not a rectangle", data);
		if (map[i][0] != WALL || map[i][len - 2] != WALL)
			exit_handler("Map error: missing wall", data);
		i++;
	}
	len--;
	data->cols = len;
	while (len--)
	{
		if (!map[0] || map[0][len] != WALL || map[i - 1][len] != WALL)
			exit_handler("Map error: missing wall", data);
	}
	ft_playable_check(data, map);
}

void	ft_playable_check(t_data *data, char **map)
{
	int	**visited;

	data->players = 0;
	data->collectibles = 0;
	data->exits = 0;
	pec_config_check(data, map);
	if (data->players != 1 || data->exits != 1 || data->collectibles == 0)
		exit_handler("Map error: Wrong configuration of P, E and or C", data);
	init_explore(data, &visited);
	explore(data, data->p_position[0], data->p_position[1], visited);
	ft_free_matrix(data, (void **)visited);
	if (data->found != (data->collectibles + 1))
		exit_handler("Map error: Collectible or Exit is unreachable", data);
}

void	pec_config_check(t_data *data, char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == PLAYER)
			{
				data->players++;
				data->p_position[0] = j;
				data->p_position[1] = i;
			}
			else if (map[i][j] == EXIT)
				data->exits++;
			else if (map[i][j] == COLLECTIBLE)
				data->collectibles++;
			else if (map[i][j] != EMPTY &&
				map[i][j] != WALL && map[i][j] != '\n')
				exit_handler("Map error: Invalid character found", data);
		}
	}
}

void	init_explore(t_data *data, int ***visited)
{
	int	i;

	*visited = (int **)malloc(data->rows * sizeof(int *));
	if (!*visited)
		exit_handler("Malloc error", data);
	i = 0;
	while (i < data->rows)
	{
		(*visited)[i++] = (int *)ft_calloc(data->cols, sizeof(int));
		if (!(*visited)[i - 1])
			exit_handler("Malloc error", data);
	}
	data->found = 0;
}

void	explore(t_data *data, int x, int y, int **visited)
{
	if (x < 0 || y < 0 || x >= (data->cols + 1) || y >= (data->rows + 1)
		|| visited[y][x] == 1 || data->map[y][x] == WALL)
		return ;
	visited[y][x] = 1;
	if (data->map[y][x] == COLLECTIBLE || data->map[y][x] == EXIT)
		data->found++;
	explore(data, x, (y - 1), visited);
	explore(data, x, (y + 1), visited);
	explore(data, (x + 1), y, visited);
	explore(data, (x - 1), y, visited);
}
