/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:28:43 by ailbezer          #+#    #+#             */
/*   Updated: 2024/10/26 17:28:49 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int(int n, int *count)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_c('-', count);
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_print_int(nbr / 10, count);
	ft_putchar_c((nbr % 10) + '0', count);
}

void	ft_print_unsint(unsigned int n, int *count)
{
	if (n > 9)
		ft_print_unsint(n / 10, count);
	ft_putchar_c((n % 10) + '0', count);
}
