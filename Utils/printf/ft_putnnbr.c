/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:59:38 by hlachhab          #+#    #+#             */
/*   Updated: 2024/04/24 03:47:37 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnnbr(unsigned int nb, int *count)
{
	if (nb > 9)
	{
		ft_putnnbr(nb / 10, count);
		ft_putnnbr(nb % 10, count);
	}
	else
		ft_putchar(nb + '0', count);
}
