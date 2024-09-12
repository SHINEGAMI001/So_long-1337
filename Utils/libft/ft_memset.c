/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 00:13:54 by hlachhab          #+#    #+#             */
/*   Updated: 2024/02/16 06:31:56 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = str;
	while (len)
	{
		*tmp = (unsigned char)c;
		tmp++;
		len--;
	}
	return (str);
}
