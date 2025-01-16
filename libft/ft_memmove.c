/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:07:47 by ailbezer          #+#    #+#             */
/*   Updated: 2024/10/04 10:23:00 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*temp;

// 	temp = (unsigned char *)malloc(n);
// 	i = 0;
// 	while (i < n)
// 	{
// 		temp[i] = ((unsigned char *)src)[i];
// 		i++;
// 	}
// 	i = 0;
// 	while (i < n)
// 	{
// 		((unsigned char *)dest)[i] = temp[i];
// 		i++;
// 	}
// 	return (dest);
// }

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest == src || n == 0)
		return (dest);
	if (dest < src || dest >= src + n)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
	}
	return (dest);
}
