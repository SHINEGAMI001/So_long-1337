/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:38:23 by hlachhab          #+#    #+#             */
/*   Updated: 2024/04/25 04:52:09 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	checkconvertion(va_list ap, const char *str, int *count)
{
	if (*str == '%')
		ft_putchar(*str, count);
	else if (*str == 'c')
		ft_putchar(va_arg(ap, int), count);
	else if (*str == 's')
		ft_putstr(va_arg(ap, char *), count);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(ap, int), count);
	else if (*str == 'u')
		ft_putnnbr(va_arg(ap, unsigned int), count);
	else if (*str == 'x')
		ft_puthexa(va_arg(ap, unsigned int), 0, count);
	else if (*str == 'X')
		ft_puthexa(va_arg(ap, unsigned int), 1, count);
	else if (*str == 'p')
	{
		ft_putstr("0x", count);
		ft_puthexa(va_arg(ap, unsigned long), 0, count);
	}
	else
		ft_putchar(*str, count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(ap, str);
	if (write(1, 0, 0) == -1)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			checkconvertion(ap, &str[i], &count);
		}
		else
			ft_putchar(str[i], &count);
		i++;
	}
	va_end(ap);
	return (count);
}
