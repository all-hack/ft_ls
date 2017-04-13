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

	if ((filelist = (t_file**)malloc(sizeof(t_file) * (size + 1))) == NULL)
		return (NULL);
	ft_bzero(filelist, sizeof(t_file) * (size + 1));
	// filelist[size] = NULL;
	return (filelist);
}

void	filelist_destroy(t_file	***filelist)
{
	int i;

	i = -1;
	if (filelist)
	{
		free(*filelist);
		*filelist = NULL;
	}
}

t_file	**filelist_addfile(t_file **filelist, t_file *file, size_t size)
{
	int	i;
	int j;
	t_file	**new_filelist;

	if (file)
	{		
		new_filelist = filelist_build(size + 1);
		i = -1;
		if (new_filelist)
		{
			while (++i < size)
			{				
				new_filelist[i] = filelist[i];
				// printf("old file name: %-11s\n", filelist[i]->d_name);
				// printf("new file name: %-11s\n\n", new_filelist[i]->d_name);
			}
		}
		new_filelist[i] = file;
		free(filelist);
		return (new_filelist);
	}
	return (filelist);
}


void	filelist_print(t_file **filelist)
{
	if (filelist)
	{
		printf("\n");
		// printf("size: %d\n", filelist_len(filelist));
		while (*filelist)
		{			
			printf("file name: %-11s\n", (*filelist)->d_name);
			// printf("file node: %-11p\n", (*filelist)->d_ino);
			filelist++;			
		}
	}
}

t_file	**filelist_init(t_context *context, char *filename, DIR **der)
{
	t_file	**filelist;
	size_t	size;
	t_file	*file;

	*der = NULL;
	filelist = NULL;
	size = 0;
	if (filename)
	{
		if ((*der = opendir(filename)))
		{
			while ((file = readdir(*der)) != NULL && size < 79)
			{
				if (!file)
					break;
				// printf("filename: %s\n", file->d_name);
				if (file_validate(context, file))
				{	
					filelist = filelist_addfile(filelist, file, size);
					// printf("array   : %s\n\n", filelist[size]->d_name);
					// filelist_print(filelist);
					// printf("\n");
					size += 1;
				}
			}
		}
		else	
			perror(filename);
	}
	return (filelist);
}

int	filelist_len(t_file **filelist)
{
	int i;

	i = 0;
	if (filelist)
	{
		while (*filelist)
		{
			filelist++;
			i++;
		}
	}
	return (i);
}
