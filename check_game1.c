/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:05:33 by hlachhab          #+#    #+#             */
/*   Updated: 2024/06/27 08:10:02 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_type(char *mapfile)
{
	size_t	i;

	i = ft_strlen(mapfile);
	if (!(mapfile[i - 1] == 'r' && mapfile[i - 2] == 'e'
			&& mapfile[i - 3] == 'b' && mapfile[i - 4] == '.'))
		return (FALSE);
	return (TRUE);
}

void	count_comps(char **map, int *c, int *e, int *p)
{
	int	y;
	int	x;

	*c = 0;
	*e = 0;
	*p = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				(*c)++;
			if (map[y][x] == 'E')
				(*e)++;
			if (map[y][x] == 'P')
				(*p)++;
			x++;
		}
		y++;
	}
}

int	check_min_components(char **map)
{
	int	count_exit;
	int	count_entry;
	int	count_food;

	count_food = 0;
	count_exit = 0;
	count_entry = 0;
	count_comps(map, &count_food, &count_exit, &count_entry);
	if (count_food < 1 || count_exit != 1
		|| count_entry != 1)
		return (FALSE);
	return (TRUE);
}
