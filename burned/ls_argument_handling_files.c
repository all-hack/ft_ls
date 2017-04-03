/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_argument_handling_files.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:01:54 by obelange          #+#    #+#             */
/*   Updated: 2017/02/24 17:01:55 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	ls_args_handleFile(t_context *context, char *filename)
{
	t_file	**filelist;
	t_file	**file;
	DIR 	*der;
	int		i;
	char	*add;

	filelist = NULL;
	file = NULL;
	if (context && filename)
	{		
		if ((add = ft_strrchr(filename, '/')) != NULL)
			context->path = ft_fstrmcatf(ls_pathname(context->path), ft_strsub(filename, 0, add - filename));
		if ((filelist = filelist_init(context, context->path, &der)) == NULL)
			ft_printf("%s: is not an existing file.\n", filename);
		i = -1;
		if (filelist)
			while (filelist[++i])
			{
				if (add)
				{
					if (ft_strcmp((filelist[i])->d_name, add + 1) == 0)
					{
						file = filelist_addfile(file, filelist[i], 0);
						break;
					}
				}
				else
				{
					if (ft_strcmp((filelist[i])->d_name, filename) == 0)
					{
						file = filelist_addfile(file, filelist[i], 0);
						break;
					}
				}
			}
		if (file)
		{
			context->filelist_action(context, file);
			ft_printf("\n");
		}
		else
			ft_printf("%s: is not an existing file.\n", filename);
		filelist_destroy(&file);
		filelist_destroy(&filelist);
		if (der)
			closedir(der);
	}
}
