/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:41:29 by hlachhab          #+#    #+#             */
/*   Updated: 2024/01/21 02:07:55 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		c;

	i = 0;
	c = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n)
	{
		i++;
	}
	if (s1[i] != s2[i] && i < n)
	{
		c = (unsigned char)s1[i] - (unsigned char)s2[i];
	}
	if (c >= 1)
		return (1);
	else if (c < 0)
		return (-1);
	return (c);
}
