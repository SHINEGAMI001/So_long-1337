/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:10:54 by hlachhab          #+#    #+#             */
/*   Updated: 2024/04/24 03:09:41 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned long nb, int upper, int *count)
{
	char	*base;

	if (upper)
	{
		base = "0123456789ABCDEF";
	}
	else
		base = "0123456789abcdef";
	if (nb >= 0 && nb <= 15)
	{
		ft_putchar(base[nb], count);
	}
	else
	{
		ft_puthexa((nb / 16), upper, count);
		ft_puthexa((nb % 16), upper, count);
	}
}
