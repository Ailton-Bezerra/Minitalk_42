/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:11:05 by ailbezer          #+#    #+#             */
/*   Updated: 2024/10/26 15:11:07 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_c(int c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_print_str(char *s, int *count)
{
	if (!s)
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	while (*s)
	{
		ft_putchar_c(*s, count);
		s++;
	}
}

void	ft_print_address(unsigned long pointer, int *count)
{
	char	*base_hex;
	char	str[17];
	int		i;

	if (pointer == 0)
	{
		ft_print_str("(nil)", count);
		return ;
	}
	ft_print_str("0x", count);
	base_hex = "0123456789abcdef";
	if (pointer == 0)
	{
		ft_putchar_c('0', count);
		return ;
	}
	i = 0;
	while (pointer)
	{
		str[i++] = base_hex[pointer % 16];
		pointer /= 16;
	}
	str[i] = '\0';
	while (i--)
		ft_putchar_c(str[i], count);
}

void	ft_print_hex(unsigned int hex_num, int *count, char hex)
{
	char	*base_hex;
	char	str[17];
	int		i;

	if (hex == 'x')
		base_hex = "0123456789abcdef";
	else if (hex == 'X')
		base_hex = "0123456789ABCDEF";
	if (hex_num == 0)
	{
		ft_putchar_c('0', count);
		return ;
	}
	i = 0;
	while (hex_num)
	{
		str[i++] = base_hex[hex_num % 16];
		hex_num /= 16;
	}
	str[i] = '\0';
	while (i--)
		ft_putchar_c(str[i], count);
}
