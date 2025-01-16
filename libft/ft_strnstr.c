/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:43:09 by ailbezer          #+#    #+#             */
/*   Updated: 2024/10/04 12:40:56 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return (((char *)big));
	while (big[i])
	{
		j = 0;
		while ((big[i + j] == little[j]) && little[j] && (i + j) < len)
			j++;
		if (little[j] == '\0')
			return (((char *)big) + i);
		i++;
	}
	return (NULL);
}
