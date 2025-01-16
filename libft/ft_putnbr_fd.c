/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:42:45 by ailbezer          #+#    #+#             */
/*   Updated: 2024/10/04 17:01:22 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_min_value_fd(int n, size_t fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	return (0);
}

static void	ft_print_reverse(char *buffer, size_t len, size_t fd)
{
	size_t	start;
	size_t	end;
	char	temp;

	start = 0;
	end = len - 1;
	while (start < end)
	{
		temp = buffer[start];
		buffer[start] = buffer[end];
		buffer[end] = temp;
		start++;
		end--;
	}
	write(fd, buffer, len);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	i;
	char	buffer[12];
	char	signal;

	i = 0;
	signal = '\0';
	if (ft_min_value_fd(n, fd))
		return ;
	if (n == 0)
		buffer[i++] = '0';
	else if (n < 0)
	{
		signal = '-';
		n = -n;
	}
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (signal == '-')
		buffer[i++] = '-';
	buffer[i] = '\0';
	ft_print_reverse(buffer, i, fd);
}
