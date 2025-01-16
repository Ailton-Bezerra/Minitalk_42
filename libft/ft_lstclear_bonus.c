/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailbezer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:01:36 by ailbezer          #+#    #+#             */
/*   Updated: 2024/10/15 11:43:24 by ailbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (!*lst)
		return ;
	while (*lst != NULL)
	{
		node = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = node;
	}
	*lst = NULL;
}
