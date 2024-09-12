/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:03:20 by hlachhab          #+#    #+#             */
/*   Updated: 2024/06/25 22:50:25 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_game *game)
{
	int	x;
	int	y;

	y = game->images->m_player->instances->y / 32;
	x = game->images->m_player->instances->x / 32;
	if (game->map[y][x + 1] != '1')
	{
		game->images->m_player->instances->x += 32;
		game->count_move++;
		ft_printf("MOVE COUNT: %d\n", game->count_move);
	}
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->images->m_player->instances->x / 32;
	y = game->images->m_player->instances->y / 32;
	if (game->map[y + 1][x] != '1')
	{
		game->images->m_player->instances->y += 32;
		game->count_move++;
		ft_printf("MOVE COUNT: %d\n", game->count_move);
	}
}

void	move_left(t_game *game)
{
	int	y;
	int	x;

	y = game->images->m_player->instances->y / 32;
	x = game->images->m_player->instances->x / 32;
	if (game->map[y][x - 1] != '1')
	{
		game->images->m_player->instances->x -= 32;
		game->count_move++;
		ft_printf("MOVE COUNT: %d\n", game->count_move);
	}
}

void	move_up(t_game *game)
{
	int	y;
	int	x;

	y = game->images->m_player->instances->y / 32;
	x = game->images->m_player->instances->x / 32;
	if (game->map[y - 1][x] != '1')
	{
		game->images->m_player->instances->y -= 32;
		game->count_move++;
		ft_printf("MOVE COUNT: %d\n", game->count_move);
	}
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& (keydata.action == MLX_RELEASE || keydata.action == MLX_REPEAT))
		move_right(game);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& (keydata.action == MLX_RELEASE || keydata.action == MLX_REPEAT))
		move_down(game);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& (keydata.action == MLX_RELEASE || keydata.action == MLX_REPEAT))
		move_left(game);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) 
		&& (keydata.action == MLX_RELEASE || keydata.action == MLX_REPEAT))
		move_up(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		mlx_close_window(game->mlx);
		ft_printf(GAME_ESC_MSG);
	}
	take_food(game);
}
