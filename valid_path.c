/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 23:40:04 by hlachhab          #+#    #+#             */
/*   Updated: 2024/06/25 23:04:14 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_map(t_game *game, int y, int x)
{
	if (x >= 1 && x < game->m_width && y >= 1 
		&& y < game->m_height && game->tmp_map[y][x] != 'X'
		&& game->tmp_map[y][x] != '1')
	{
		game->tmp_map[y][x] = 'X';
		flood_map(game, y + 1, x);
		flood_map(game, y, x + 1);
		flood_map(game, y - 1, x);
		flood_map(game, y, x - 1);
	}
}

int	check_fmap(char **fmap)
{
	int	y;
	int	x;

	y = 0;
	while (fmap[y])
	{
		x = 0;
		while (fmap[y][x])
		{
			if (fmap[y][x] == 'C' || fmap[y][x] == 'E')
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}

int	*get_position(t_game *game)
{
	int	y;
	int	x;
	int	*pos;

	pos = malloc(1 * sizeof(int));
	if (!pos)
		return (0);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				pos[0] = y;
				pos[1] = x;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

int	check_path(t_game *game, char *mapfile)
{
	int	*pos;

	pos = get_position(game);
	game->tmp_map = read_map(mapfile);
	if (game->tmp_map)
	{
		flood_map(game, pos[0], pos[1]);
		if (check_fmap(game->tmp_map) == FALSE)
		{
			free_map(game->tmp_map);
			return (free(pos), FALSE);
		}
	}
	free(pos);
	free_map(game->tmp_map);
	return (TRUE);
}
