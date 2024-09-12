/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 22:42:42 by hlachhab          #+#    #+#             */
/*   Updated: 2024/01/29 22:55:27 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if (s && (char)c == 0)
		return ((char *)(s + ft_strlen(s)));
	while (len && *(s + len) != (char)c)
	{
		len--;
		if (*(s + len) == (char)c)
			return ((char *)s + len);
		if (!c)
			return (NULL);
	}
	if (!c)
		return ((char *)s + len);
	return (NULL);
}
