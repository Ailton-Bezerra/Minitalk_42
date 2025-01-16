/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:38:26 by ailbezer          #+#    #+#             */
/*   Updated: 2024/10/26 13:38:30 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(va_list arg, int c, int *count)
{
	if (c == 'c')
		ft_putchar_c(va_arg(arg, int), count);
	else if (c == 's')
		ft_print_str(va_arg(arg, char *), count);
	else if (c == 'p')
		ft_print_address(va_arg(arg, unsigned long), count);
	else if (c == 'd' || c == 'i')
		ft_print_int(va_arg(arg, long), count);
	else if (c == 'u')
		ft_print_unsint(va_arg(arg, unsigned int), count);
	else if (c == 'x')
		ft_print_hex(va_arg(arg, unsigned long), count, 'x');
	else if (c == 'X')
		ft_print_hex(va_arg(arg, unsigned long), count, 'X');
	else if (c == '%')
		ft_putchar_c('%', count);
}
