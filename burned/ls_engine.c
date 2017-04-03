/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lf_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:11:40 by obelange          #+#    #+#             */
/*   Updated: 2017/01/30 18:11:44 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	ls_do_nothing(t_context *context, t_file **filelist)
{
	return ;
}

void	ls_recursion(t_context *context, t_file **filelist)
{
	t_lstat	rstat;
	char	*str;

	if (context && filelist)
		while (*filelist)
		{			
			context = t_context_add_path(context, (*filelist)->d_name);
			lstat(context->path, &rstat);			
			if (S_ISDIR(rstat.st_mode))
			{
				str = ls_recurse_pathname(context->path);
				ft_printf("\n%s:\n", str);
				ls_engine(context);
				ft_strdel(&str);
			}
			context = t_context_minus_path(context);
			filelist++;
		}
}

void	ls_engine(t_context *context)
{
	t_file 	**filelist;
	DIR 	*der;

	if ((filelist = filelist_init(context, context->path, &der)) == NULL)
		return ;
	filelist = context->filelist_sort(context, filelist);
	context->filelist_action(context, filelist);
	context->bonus_action(context, filelist);
	closedir(der);
	filelist_destroy(&filelist);
}
