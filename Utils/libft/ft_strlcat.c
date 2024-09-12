/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 22:04:50 by hlachhab          #+#    #+#             */
/*   Updated: 2024/02/16 06:37:09 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s;
	size_t	tmp;
	size_t	dstlen;
	size_t	srclen;

	dstlen = 0;
	srclen = ft_strlen(src);
	if (dst || dstsize > 0)
		dstlen = ft_strlen(dst);
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	tmp = ft_strlen(dst);
	s = 0;
	while (src[s] && tmp < (dstsize - 1))
	{
		dst[tmp++] = src[s++];
	}
	dst[tmp] = '\0';
	return (dstlen + srclen);
}
