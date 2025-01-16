/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:22:11 by ailbezer          #+#    #+#             */
/*   Updated: 2024/10/03 18:45:37 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alocated;
	size_t	i;
	size_t	total_size;

	i = 0;
	total_size = nmemb * size;
	if (total_size == 0)
		return (malloc(0));
	if (total_size / nmemb != size)
		return (NULL);
	alocated = malloc(nmemb * size);
	if (alocated == NULL)
		return (NULL);
	while (i < (nmemb * size))
	{
		((unsigned char *)alocated)[i] = 0;
		i++;
	}
	return (alocated);
}
