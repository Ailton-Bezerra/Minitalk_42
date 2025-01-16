/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:57:53 by ailbezer          #+#    #+#             */
/*   Updated: 2024/10/06 16:25:09 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_nbr(long nbr)
{
	size_t	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

static char	*ft_save_min(char *buffer, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

static char	*ft_invert(char *buffer)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = ft_strlen(buffer) - 1;
	while (start < end)
	{
		temp = buffer[end];
		buffer[end] = buffer[start];
		buffer[start] = temp;
		start++;
		end--;
	}
	return (buffer);
}

static char	*ft_convert(char *buffer, int n, char signal)
{
	int	i;

	i = 0;
	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	if (signal)
		buffer[i++] = signal;
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_itoa(int n)
{
	char	*buffer;
	char	signal;
	int		nbr;

	nbr = n;
	signal = '\0';
	buffer = (char *)malloc(ft_len_nbr(nbr) + 1);
	if (buffer == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_save_min(buffer, "-2147483648"));
	if (nbr < 0)
	{
		signal = '-';
		nbr = -nbr;
	}
	ft_convert(buffer, nbr, signal);
	return (ft_invert(buffer));
}
