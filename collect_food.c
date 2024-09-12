/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_food.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:05:42 by hlachhab          #+#    #+#             */
/*   Updated: 2024/06/26 00:38:48 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_food(t_game *game)
{
	int	i;
	int	x;
	int	y;
	int	x_food;
	int	y_food;

	y = game->images->m_player->instances->y;
	x = game->images->m_player->instances->x;
	i = 0;
	while (i < game->total_food)
	{
		y_food = game->images->m_food->instances[i].y;
		x_food = game->images->m_food->instances[i].x;
		if (y == y_food && x == x_food
			&& game->images->m_food->instances[i].enabled != false)
		{
			game->images->m_food->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

void	take_food(t_game *game)
{
	int	y;
	int	x;

	y = game->images->m_player->instances->y / 32;
	x = game->images->m_player->instances->x / 32;
	if (game->map[y][x] == 'C')
	{
		delete_food(game);
		game->count_food++;
		ft_printf("\nCOLLECTED HEADS : %d\n\n", game->count_food);
		game->map[y][x] = '0';
		if (game->count_food == game->total_food)
		{
			game->images->m_exit->instances->enabled = false;
			ft_printf(DOOR_OPENED_MSG);
		}
	}
	if (game->map[y][x] == 'E')
	{
		if (game->count_food == game->total_food)
		{
			ft_printf(GAME_WON_MSG);
			mlx_close_window(game->mlx);
		}
	}
}
