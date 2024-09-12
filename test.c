/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:50:31 by hlachhab          #+#    #+#             */
/*   Updated: 2024/06/20 19:50:32 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	len;
	char	*cpy;

	len = 0;
	while (str[len])
		len++;
	cpy = malloc((len + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	j;

	i = start;
	if (!s)
		return (NULL);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if (i > ft_strlen(s))
		return (ft_strdup(""));
	subs = malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	j = 0;
	while (j < len)
		subs[j++] = s[i++];
	subs[j] = '\0';
	return (subs);
}

static int	count_words(char const *str, char c)
{
	size_t	count;

	count = 0;
	while (str && *str)
	{
		if (str && *str != c && (*(str + 1) == c || *(str + 1) == '\0'))
			count++;
		str++;
	}
	return (count);
}

static void	ft_free(char **str)
{
	int	len;

	len = 0;
	while (str && str[len])
	{
		free(str[len]);
		len++;
	}
	free(str);
}

static char	**ft_str(char **str, char const *s, char c, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	while (i < len)
	{
		y = 0;
		while (s && *s == c)
			s++;
		while (s[y] && s[y] != c)
			y++;
		str[i] = ft_substr(s, 0, y);
		if (!str[i])
		{
			ft_free(str);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t		len;
	char		**str;

	if (!s)
		return (NULL);
	len = count_words(s, c);
	str = (char **)malloc((len + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str = ft_str(str, s, c, len);
	return (str);
}

char	**read_map(char *mapfile)
{
	char	**map;
	char	*tmp;
	int		n;
	int		fd;

	n = 0;
	tmp = (char *)malloc(10000 + 1);
	if (!tmp)
		return (0);
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		return (free(tmp), (0));
	n = read(fd, tmp, 10000);
	if (n < 0 || n == 0)
	{
		free(tmp);
		return (0);
	}
	tmp[n] = '\0';
	// printf("%s\n", tmp);
	map = ft_split(tmp, '\n');
	free(tmp);
	close(fd);
	return (map);
}

typedef struct s_game
{
	char	**map;
}t_game; 

int main(int ac, char **av)
{
	t_game	game;
	int		i;

	i = 0;
	if (ac == 2)
	{
		game.map = read_map(av[1]);
		if (!(game.map))
			return (0);
		while (game.map[i])
		{
			printf("%s\n", game.map[i]);
			i++;
		}
	}
	return (0);
}