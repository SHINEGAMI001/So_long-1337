/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:05:10 by hlachhab          #+#    #+#             */
/*   Updated: 2024/02/17 07:34:12 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checker(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	i;
	size_t	len;

	if (!s || !set)
		return (NULL);
	i = 0;
	while (s[i] && ft_strchr(set, s[i]))
		i++;
	len = ft_strlen(s);
	while (ft_strrchr(set, s[len]) && len > 0)
		len--;
	return (ft_substr(s, i, len - i + 1));
}
