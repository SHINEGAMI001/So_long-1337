/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:58:27 by hlachhab          #+#    #+#             */
/*   Updated: 2024/01/26 20:23:23 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
