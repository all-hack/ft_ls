/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_argument_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:25:34 by obelange          #+#    #+#             */
/*   Updated: 2017/02/13 15:25:36 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

char **ls_get_directories(t_context *context, char ***argList)
{
	char 	**dirList;
	t_lstat	rstat;
	char	*path;
	int		i;
	int		flag;

	dirList = NULL;
	if (argList && *argList)
	{		
		flag = 1;
		while (flag == 1)
		{
			i = -1;
			flag = 0;			
			while ((*argList)[++i])
			{
				path = ft_fstrmcat(ls_pathname(context->path), (*argList)[i]);
				lstat(path, &rstat);
				if (S_ISDIR(rstat.st_mode))
				{
					dirList = ft_strlist_add(dirList, (*argList)[i]);
					*argList = ft_strlist_remove(*argList, (*argList)[i]);
					flag = 1;
					ft_strdel(&path);
					break ;
				}
				ft_strdel(&path);
			}
		}
	}
	return (dirList);
}



