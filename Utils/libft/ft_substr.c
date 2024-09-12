/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 23:41:46 by hlachhab          #+#    #+#             */
/*   Updated: 2024/06/20 19:41:37 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
