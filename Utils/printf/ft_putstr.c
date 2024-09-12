/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:06:58 by hlachhab          #+#    #+#             */
/*   Updated: 2024/04/24 03:09:56 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str) 
	{
		ft_putstr("(null)", count);
	}
	else
	{
		while (str[i] != '\0')
		{
			ft_putchar(str[i], count);
			i++;
		}
	}
}
