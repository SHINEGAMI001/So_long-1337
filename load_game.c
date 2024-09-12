/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:12:43 by hlachhab          #+#    #+#             */
/*   Updated: 2024/09/12 20:09:01 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_texture(t_game *game)
{
	game->textures = malloc(1 * sizeof(t_textures));
	game->textures->m_floor = mlx_load_png(FLOOR_PATH);
	game->textures->m_wall = mlx_load_png(WALL_PATH);
	game->textures->m_playr = mlx_load_png(PLAYER_PATH);
	game->textures->m_food = mlx_load_png(C_PATH);
	game->textures->m_exit = mlx_load_png(EXIT_PATH);
	game->textures->m_exit2 = mlx_load_png(BROKEN_EXIT_PATH);
}

void	load_image(t_game *game, t_textures *textures)
{
	game->images = malloc(1 * sizeof(t_images));
	game->images->m_floor = mlx_texture_to_image(game->mlx, textures->m_floor);
	game->images->m_wall = mlx_texture_to_image(game->mlx, textures->m_wall);
	game->images->m_player = mlx_texture_to_image(game->mlx, textures->m_playr);
	game->images->m_food = mlx_texture_to_image(game->mlx, textures->m_food);
	game->images->m_exit = mlx_texture_to_image(game->mlx, textures->m_exit);
	game->images->m_exit2 = mlx_texture_to_image(game->mlx, textures->m_exit2);
	mlx_delete_texture(game->textures->m_floor);
	mlx_delete_texture(game->textures->m_wall);
	mlx_delete_texture(game->textures->m_playr);
	mlx_delete_texture(game->textures->m_food);
	mlx_delete_texture(game->textures->m_exit);
	mlx_delete_texture(game->textures->m_exit2);
}

void	put_floor(t_game *game, t_images *image)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_image_to_window(game->mlx, image->m_floor, x * 32, y * 32);
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, image->m_wall, x * 32, y * 32);
			if (game->map[y][x] == 'E')
			{
				mlx_image_to_window(game->mlx, image->m_exit2, x * 32, y * 32);
				mlx_image_to_window(game->mlx, image->m_exit, x * 32, y * 32);
			}
			x++;
		}
		y++;
	}
}

void	put_map(t_game *game, t_images *image)
{
	int	y;
	int	x;

	put_floor(game, game->images);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, image->m_player, x * 32, y * 32);
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, image->m_food, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

int	load_game(t_game *game)
{
	game->count_food = 0;
	game->count_move = 0;
	game->mlx = mlx_init(game->m_width, game->m_height, "so_long", false);
	if (!(game->mlx))
		return (1);
	load_texture(game);
	load_image(game, game->textures);
	put_map(game, game->images);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free(game->images);
	free(game->textures);
	return (0);
}
