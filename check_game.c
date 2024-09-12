/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:08:47 by hlachhab          #+#    #+#             */
/*   Updated: 2024/06/27 08:10:26 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_is_rectangular(char **map)
{
	int	x;
	int	y;
	int	x_len;

	x_len = ft_strlen(map[0]);
	y = 1;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		if (x_len != x)
			return (FALSE);
		y++;
	}
	return (TRUE);
}

int	map_is_walled(char **map)
{
	int	i;
	int	x_len;
	int	y_len;

	i = 0;
	y_len = 0;
	while (map[y_len])
		y_len++;
	x_len = ft_strlen(map[0]);
	while (i < x_len)
	{
		if (map[0][i] != '1' || map[y_len - 1][i] != '1')
			return (FALSE);
		i++;
	}
	i = 0;
	while (i < y_len)
	{
		if (map[i][0] != '1' || map[i][x_len - 1] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	check_all_components(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!(map[y][x] == '1' || map[y][x] == '0'
				|| map[y][x] == 'P' || map[y][x] == 'E'
					|| map[y][x] == 'C'))
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}

int	check_game(char **map)
{
	if (map_is_rectangular(map) == FALSE)
		return (ft_printf(INVALID_MAP), (FALSE));
	if (map_is_walled(map) == FALSE)
		return (ft_printf(WALL_ERROR), (FALSE));
	if (check_all_components(map) == FALSE)
		return (ft_printf(COMPONENETS_ERROR), (FALSE));
	if (check_min_components(map) == FALSE)
		return (ft_printf(COMPONENETS_ERROR), (FALSE));
	return (TRUE);
}
