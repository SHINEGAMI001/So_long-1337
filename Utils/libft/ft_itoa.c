/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 00:32:59 by hlachhab          #+#    #+#             */
/*   Updated: 2024/02/16 06:36:29 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	nbrlen(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*s;
	size_t		j;
	long int	x;

	x = n;
	if (x == 0)
		return (ft_strdup("0"));
	j = nbrlen(x);
	s = (char *)malloc(sizeof(char) * (j + 1));
	if (!s)
		return (NULL);
	s[j] = '\0';
	if (x < 0)
	{
		s[0] = '-';
		x *= -1;
	}
	while (j-- > 0 && x != 0)
	{
		s[j] = (x % 10) + 48;
		x /= 10;
	}
	return (s);
}
