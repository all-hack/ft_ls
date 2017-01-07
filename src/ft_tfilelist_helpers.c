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

t_filelist	**t_filelist_append(t_filelist **list, t_filelist *file, size_t size)
{
	t_filelist	**new_list;
	size_t		i;

	// printf("ft_t_filelist_append\n");
	// printf("file->d_name: %s\n", file->d_name);
	if (file)
	{
		// printf("launching...\n");
		i = 0;
		new_list = (t_filelist**)malloc(sizeof(t_filelist*) * (size + 1));
		ft_bzero(new_list, sizeof(t_filelist*) * (size + 1));
		// printf("loop\n");
		if (list)
			while (list[i])
			{
				// printf("i: %d\n", i);			
				new_list[i] = list[i];
				i++;
			}
		// printf("size: %d\n", size);
		new_list[i] = file;
		new_list[i + 1] = NULL;
		// printf("\n");
		// ft_print_t_filelist(new_list);
		return (new_list);
	}
	return (NULL);
}

t_filelist	**t_filelist_make(DIR	*der, int (*t_filelist_name_validator)(char*, char**), char **invalid_names)
{
	t_filelist	**list;
	t_filelist	*tmp;
	size_t		size;

	// printf("\nft_make_t_filelist\n");
	if (der)
	{
		// printf("launching...\n");
		size = 0;
		list = NULL;
		// printf("loop\n");
		while ((tmp = readdir(der)) > 0)
		{
			// printf("tmp->d_name: %s\n", tmp->d_name);
			if ((*t_filelist_name_validator)(tmp->d_name, invalid_names))
				list = t_filelist_append(list, tmp, ++size);
			// printf("\n");
		}
		// printf("list: %p\n", list);
		// printf("*list->d_name: %s\n", (*list)->d_name);
		return (list);
	}
	return (NULL);
}

void	t_filelist_print(t_filelist **list)
{
	int	i;

	// printf("\nft_print_t_filelist\n");
	if (list)
	{
		// printf("launching...\n");
		i = -1;
		// printf("list: %s\n", (*list)->d_name);
		while (list[++i])
			printf("list[%d]->d_name: %s\n", i, list[i]->d_name);		
	}
}

int		t_filelist_name_validator(char *file_name, char	**invalid_name)
{
	if (file_name && invalid_name)
	{
		while (*invalid_name)
		{
			if (ft_strcmp(file_name, *invalid_name++) == 0)
				return (0);				
		}
		return (1);
	}



}