/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:46:18 by ailbezer          #+#    #+#             */
/*   Updated: 2024/10/10 11:56:08 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*str;

	i = ft_strlen(s);
	str = ((unsigned char *)s) + i;
	while (i-- > 0)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str--;
	}
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (NULL);
}
