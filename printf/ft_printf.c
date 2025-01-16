/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:18:15 by ailbezer          #+#    #+#             */
/*   Updated: 2024/10/25 11:20:30 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		index;
	int		count;

	va_start(arg, str);
	count = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] != '%')
		{
			ft_putchar_c(str[index], &count);
		}
		else
			ft_check(arg, str[++index], &count);
		index++;
	}
	va_end(arg);
	if (count < 0)
		return (-1);
	return (count);
}
