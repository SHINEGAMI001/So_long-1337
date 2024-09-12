/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:28:29 by hlachhab          #+#    #+#             */
/*   Updated: 2024/06/27 08:08:09 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	bibakhawa()
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	atexit(bibakhawa);
	t_game	game;

	if (ac == 2)
	{
		if (check_file_type(av[1]) == FALSE)
			return (ft_printf(FILETYPE_ERROR), (1));
		game.map = read_map(av[1]);
		if (!(game.map))
		{
			ft_printf(MAP_ERROR);
			return (free_map(game.map), (1));
		}
		if (check_game(game.map) == FALSE)
			return (free_map(game.map), 1);
		get_map_size(&game, game.map);
		if (check_path(&game, av[1]) == FALSE)
		{
			free_map(game.map);
			return (printf(PATH_ERROR), (0));
		}
		if (load_game(&game) == 1)
			return (free_map(game.map), (1));
		free_map(game.map);
	}
	return (0);
}
