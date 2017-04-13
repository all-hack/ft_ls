/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:03:52 by obelange          #+#    #+#             */
/*   Updated: 2017/03/17 11:03:54 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	ls_shortprint(struct s_env *context, t_file **filelist)
{
	char	*print;

	print = NULL;
	if (context && filelist)
	{		
		while (*filelist)
		{
			if (context->pre_seed)				
				print = context->pre_seed;
			else
				print = (*filelist)->d_name;
			ft_putstr(print);
			ft_putstr("\n");
			filelist++;
		}
	}
}

void	ls_recursion(t_context *context, t_file **filelist)
{
	t_lstat	rstat;
	char	*old;

	if (context && filelist)
		while (*filelist)
		{
			old = ft_strdup(context->access_path);
			context = t_context_add_path(context, (*filelist)->d_name);
			lstat(context->access_path, &rstat);
			if (S_ISDIR(rstat.st_mode))
			{
				ft_printf("\n");
				ft_printf("%s:\n", context->access_path);
				ls_engine(context);
			}
			
			ft_strdel(&context->access_path);
			context->access_path = old;

			filelist++;
		}
}

void	ls_do_nothing(t_context *context, t_file **filelist)
{
	return ;
}

void	ls_engine(t_context *context)
{
	t_file 	**filelist;
	DIR 	*der;

	if ((filelist = filelist_init(context, context->access_path, &der)) == NULL)
		return ;

	// printf("filelist plain\n");
	// filelist_print(filelist);
	// ft_printf("access path: %s\n", extract_access_path(context->presentation_path));
	// ft_printf("access path: %s\n", context->access_path);
	// ft_printf("access path: %s\n", context->access_path);
	filelist = context->filelist_sort(context, filelist);
	// printf("filelist plain\n");
	// filelist_print(filelist);
	context->filelist_action(context, filelist);
	context->bonus_action(context, filelist);
	closedir(der);
	// printf("0: %s\n", filelist[7]->d_name);
	filelist_destroy(&filelist);
}

