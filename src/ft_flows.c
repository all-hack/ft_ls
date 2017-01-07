/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flows.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:21:37 by obelange          #+#    #+#             */
/*   Updated: 2017/01/05 15:21:39 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"


void	t_node_print(t_node *node)
{
	printf("\n");
	if (node)
	{
		printf("name: %s\n", node->name);
		printf("size: %ld\n", node->size);
		printf("path: %s\n", node->path);
		printf("path_size: %ld\n", node->path_size);
	}
	else
		printf("no node\n");
}


t_filelist	**ft_sequencer_ascending(t_filelist **list)
{
 	return (list);
}





void	depth_first_flow(t_node *node, char **invalid_names, t_filelist **(*sequencer)(t_filelist**), void (*node_function)(t_node*))
{
	DIR		*der;
	t_filelist	**list;
	t_filelist	**direct;
	t_filelist	**file;
	size_t	i;

	list = NULL;
	i = 0;
	printf("enter depth_first_flow: node->path: %s\n", node->path);
	if (node && sequencer && node_function)
	{
		// printf("launching...\n");
		der = opendir(node->path);
		list = t_filelist_make(der, t_filelist_name_validator, invalid_names);
		// printf("der: %p\n", der);
		// printf("list: %p\n", list);
		if (list)			
		{
			
			// while (list[i])
			// {
			// 	t_node_add_node(node, list[i++]->d_name);
			// 	depth_first_flow(node, sequencer, node_function);
			// 	t_node_remove_node(node);
			// }
		}
		
		// printf("print list depth_first_flow: %s\n", node->path);
		t_filelist_print(list);
		closedir(der);
	}	
}



int	main(void)
{
	t_node *root;
	t_node *noot;
	t_node *loot;
	t_node *coot;

	char 	*invalid[3];

	invalid[0] = ".";
	invalid[1] = "..";
	invalid[2] = NULL;

	root = t_node_init("0/a", NULL);

	// t_node_print(root);


	// t_node_add_node(root, "0123456789");	
	// t_node_print(root);

	// t_node_remove_node(root);
	// t_node_print(root);




	// t_node_update_node(root, "jj");	
	// ft_node_print(root);


	depth_first_flow(root, invalid, ft_sequencer_ascending, t_node_print);



	// t_node_clean(&root);






	return (0);
}