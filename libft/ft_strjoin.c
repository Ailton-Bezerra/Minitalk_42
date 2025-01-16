/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:57:37 by ailbezer          #+#    #+#             */
/*   Updated: 2024/10/04 14:56:35 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *s_result, const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] || s2[j])
	{
		if (s1[i])
		{
			s_result[i] = s1[i];
			i++;
		}
		else
		{
			s_result[i + j] = s2[j];
			j++;
		}
	}
	s_result[i + j] = '\0';
	return (s_result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	new_str = (char *)malloc(i + j + 1);
	if (new_str == NULL)
		return (NULL);
	new_str[i + j] = '\0';
	return (ft_strcat(new_str, s1, s2));
}
