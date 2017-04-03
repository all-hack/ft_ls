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

static	int	norm_cheat(t_context *context, char ***argList, char ***dirList, int i)
{
	t_lstat	rstat;
	char	*path;

	path = ft_fstrmcat(ls_pathname(context->path), (*argList)[i]);
	lstat(path, &rstat);
	if (S_ISDIR(rstat.st_mode))
	{
		*dirList = ft_strlist_add(*dirList, (*argList)[i]);
		if (ft_strlist_len(*argList) <= 1)						
		{
			ft_strlist_del(argList);
			ft_strdel(&path);
			return (0);
		}
		else
			*argList = ft_strlist_remove(*argList, (*argList)[i]);
		ft_strdel(&path);
		return (3);
	}
	ft_strdel(&path);
	return (1);
}

char **ls_get_directories(t_context *context, char ***argList)
{
	char 	**dirList;
	int		i;
	int		flag;
	int		fuck;

	dirList = NULL;
	flag = 1;
	if (argList && *argList)
		while (flag == 1)
		{
			i = -1;
			flag = 0;			
			while ((*argList)[++i])
			{
				fuck = norm_cheat(context, argList, &dirList, i);
				if (fuck == 3)
					flag = 1;
				if (fuck == 3 || fuck == 0)
					break ;				
			}
		}
	return (dirList);
}

