/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:22:03 by hlachhab          #+#    #+#             */
/*   Updated: 2024/01/20 09:50:16 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;
	char	*ptr;

	ptr = (char *)haystack;
	i = 0;
	c = 0;
	if (!haystack && len == 0)
		return (NULL);
	if (needle[c] == '\0')
		return ((char *)haystack);
	while (i <= len && haystack[i])
	{
		if (*(needle + c) == *(haystack + i)
			&& ft_strncmp((char *)ptr, needle, ft_strlen(needle)) == 0)
		{
			if (i + ft_strlen(needle) > len)
				return (NULL);
			else
				return (ptr);
		}
		i++;
		ptr++;
	}
	return (NULL);
}
