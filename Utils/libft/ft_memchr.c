/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:41:11 by hlachhab          #+#    #+#             */
/*   Updated: 2024/02/16 03:15:03 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t	ptr;

	ptr = 0;
	while (ptr < len)
	{
		if (*((char *)s + ptr) == (char)c)
			return ((void *)s + ptr);
		ptr++;
	}
	return (NULL);
}
