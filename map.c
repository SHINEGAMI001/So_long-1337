/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:16:38 by hlachhab          #+#    #+#             */
/*   Updated: 2024/06/25 23:07:42 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	total_collectibales(char **map)
{
	int	y;
	int	x;
	int	count_c;

	count_c = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count_c++;
			x++;
		}
		y++;
	}
	return (count_c);
}

void	get_map_size(t_game *game, char **map)
{
	int	i;

	i = 0;
	game->total_food = total_collectibales(map);
	game->m_width = ft_strlen(map[0]) * 32;
	while (map[i])
		i++;
	game->m_height = i * 32;
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	*read_read(int fd)
{
	char	*res;
	int		n;

	res = (char *)malloc(BUFFER_SIZE + 1);
	n = 0;
	n = read(fd, res, BUFFER_SIZE);
	if (n < 0)
	{
		free(res);
		return (0);
	}
	res[n] = '\0';
	return (res);
}

char	**read_map(char *mapfile)
{
	char	**map;
	char	*tmp;
	int		n;
	int		fd;

	n = 0;
	tmp = NULL;
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
	{
		free (tmp);
		return (TRUE);
	}
	tmp = read_read(fd);
	if (!tmp)
		return (0);
	map = ft_split(tmp, '\n');
	free(tmp);
	close(fd);
	return (map);
}
