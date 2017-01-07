/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 21:48:18 by obelange          #+#    #+#             */
/*   Updated: 2016/10/20 21:48:21 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	NULL_GUARD((node = (t_list*)malloc(sizeof(t_list))));
	node->next = NULL;
	if (content)
	{
		if ((node->content = (void*)malloc(content_size)))
		{
			ft_memcpy(node->content, content, content_size);
			node->content_size = content_size;
		}
		else
		{
			free(node);
			return (NULL);
		}
	}
	else
	{
		node->content = 0;
		node->content_size = 0;
	}
	return (node);
}
