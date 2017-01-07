/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:22:05 by obelange          #+#    #+#             */
/*   Updated: 2017/01/05 15:22:10 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

t_node	*t_node_init(char *name, char *path)
{
	t_node *node;

	if ((node = (t_node*)malloc(sizeof(t_node))) == 0)
		ft_ls_error(0, "malloc has failed...");
	
	if (name)
		node->name = ft_strdup(name);		
	else
		node->name = ft_strdup(".");

	if (path)
	{
		if (path[0] == '/')
			node->path = ft_strdup("/");
		else
			node->path = ft_fstrmcat(ft_strdup(path), "/");
		node->path = ft_fstrmcat(node->path, node->name);
	}
	else
		node->path = ft_strdup(node->name);

	node->path_size = ft_strlen(node->path);
	node->size = ft_strlen(node->name);
	
	return (node);
}

void	t_node_clean(t_node **node)
{
	if (node && *node)
	{
		if ((*node)->name)
			free((*node)->name);
		if ((*node)->path)
			free((*node)->path);		
		free(*node);
		node = NULL;
	}
}

void	t_node_add_node(t_node *node, char *name)
{	
	if (node && name)
	{
		if (node->name)
			node->name = ft_fstrdup(node->name, name);
		else
			node->name = ft_strdup(name);
		node->size = ft_strlen(node->name);
		if (node->path)
			node->path = ft_fstrmcat(ft_fstrappend(node->path, '/'), node->name);
		else
			node->path = ft_strdup(node->name);
		node->path_size = ft_strlen(node->path);
	}

}

void	t_node_remove_node(t_node *node)
{
	size_t	index;
	char	*slash;

	// printf("\nremove node\n");
	if (node)
	{
		slash = ft_strrchr(node->path, '/');
		if (slash)
		{
			// printf("node->path: %s\n", node->path);
			index = slash - node->path;
			// printf("index: %ld\n", index);
			// printf("slash: %s\n", slash);
			ft_fstrinsert(&node->path, "", index, node->path_size);
			node->path_size = ft_strlen(node->path);
			// printf("node->path: %s\n", node->path);
			slash = ft_strrchr(node->path, '/');
			if (slash)
				index = slash - node->path + 1;
			else
				index = 0;
			node->name = ft_fstrdup(node->name, node->path + index);
			node->size = ft_strlen(node->name);	
		}
		else
		{
			node->path = NULL;
			node->name = NULL;
			node->path_size = 0;
			node->size = 0;
		}
	}	
}


