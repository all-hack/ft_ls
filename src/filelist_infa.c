/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filelist_infa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:18:49 by obelange          #+#    #+#             */
/*   Updated: 2017/01/20 15:18:51 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

t_file	**filelist_build(size_t size)
{
	t_file	**filelist;

	filelist = (t_file**)malloc(sizeof(t_file) * (size + 1));
	filelist[size] = NULL;
	return (filelist);
}

// void	filelist_destroy(t_file	**filelist)
// {
// 	int i;

// 	i = -1;
// 	if (filelist)
// 	{

// 		// while (filelist[++i])
// 		// {
// 		// 	free(filelist[i]);
// 		// }
// 		free(filelist);
// 	}
// }

t_file	**filelist_addfile(t_file **filelist, t_file *file, size_t size)
{
	int	i;
	t_file	**new_filelist;

	new_filelist = filelist_build(size + 1);
	i = -1;
	if (new_filelist && file)
		while (++i < size)
			new_filelist[i] = filelist[i];
	new_filelist[i] = file;
	free(filelist);
	return (new_filelist);	
}


void	filelist_print(t_file **filelist)
{
	if (filelist)
	{
		while (*filelist)
		{
			printf("file name: %s, inode: %ld\n", (*filelist)->d_name, (*filelist)->d_ino);
			filelist++;			
		}
	}
}


t_file	**filelist_init(t_context *context, char *filename)
{
	t_file	**filelist;
	size_t	size;
	DIR		*der;
	t_file	*file;

	der = NULL;
	filelist = NULL;
	size = 0;
	if (filename)
	{
		der = opendir(filename);		
		if (der)
		{
			while ((file = readdir(der)))
			{
				if (file_validate(context, file))
					filelist = filelist_addfile(filelist, file, size++);
			}
			closedir(der);
		}
	}
	return (filelist);
}




























